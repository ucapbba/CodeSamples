// ============================================================================
// ContainersLesson.cpp
//
// Walks through the core C++ standard containers - std::array, std::vector,
// std::list, std::deque, std::map, std::unordered_map - and compares each one
// to its closest Python equivalent, so the mental model transfers across
// languages.
//
// Quick cheat sheet (C++  ->  Python):
//   std::array<T,N>       ->  tuple (fixed size) / list used as fixed-size
//   std::vector<T>        ->  list
//   std::list<T>          ->  collections.deque (doubly linked list semantics)
//   std::deque<T>         ->  collections.deque
//   std::map<K,V>         ->  dict (but C++ map is ORDERED by key; Python
//                              dict is insertion-ordered, not key-ordered -
//                              closest true equivalent is a sorted structure
//                              like the 'sortedcontainers.SortedDict')
//   std::unordered_map<K,V>-> dict (Python's dict IS a hash map, so this is
//                              the truest match)
// ============================================================================

#include "ContainersLesson.h"

#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>

namespace
{
    template <typename Container>
    void Print(const std::string& label, const Container& c)
    {
        std::cout << label << ": ";
        for (const auto& item : c)
        {
            std::cout << item << " ";
        }
        std::cout << "\n";
    }
}

// ----------------------------------------------------------------------------
// std::array<T, N>
//
// - Fixed size, known at COMPILE time (part of the type itself).
// - Stored entirely on the stack (no heap allocation), so it's very fast.
// - Size can never grow or shrink.
//
// Python equivalent: closest is a tuple (immutable, fixed-length), though
// Python has no true "stack allocated fixed-size" concept - everything is
// heap-allocated and dynamically resizable/mutable by default:
//
//      point = (1, 2, 3)     # tuple - fixed size, similar spirit to std::array
// ----------------------------------------------------------------------------
void Lesson1_Array()
{
    std::cout << "\n=== Lesson 1: std::array<T, N> (like a Python tuple) ===\n";

    std::array<int, 3> point = { 1, 2, 3 };
    Print("point", point);

    std::cout << "size (fixed, compile-time) = " << point.size() << "\n";

    // You CAN mutate elements (unlike a Python tuple), just not resize.
    point[0] = 99;
    Print("point after point[0] = 99", point);

    // point.push_back(4); // <-- would NOT compile: std::array has no push_back
}

// ----------------------------------------------------------------------------
// std::vector<T>
//
// - Dynamically resizable, contiguous memory (like a Python list, and like a
//   growable C array under the hood).
// - Random access O(1), append at the end (amortized) O(1).
// - Inserting/removing in the middle is O(n) because elements must shift.
//
// Python equivalent: list
//
//      numbers = [1, 2, 3]
//      numbers.append(4)
//      numbers.insert(1, 99)   # O(n), just like std::vector::insert
// ----------------------------------------------------------------------------
void Lesson2_Vector()
{
    std::cout << "\n=== Lesson 2: std::vector<T> (like a Python list) ===\n";

    std::vector<int> numbers = { 1, 2, 3 };
    numbers.push_back(4); // like numbers.append(4) in Python
    Print("numbers after push_back(4)", numbers);

    numbers.insert(numbers.begin() + 1, 99); // like numbers.insert(1, 99)
    Print("numbers after insert(1, 99)", numbers);

    numbers.erase(numbers.begin()); // like numbers.pop(0)
    Print("numbers after erase(begin())", numbers);

    std::cout << "random access numbers[2] = " << numbers[2] << " (O(1), like Python's list[2])\n";
}

// ----------------------------------------------------------------------------
// std::vector<T> - UNDER THE HOOD (manual pointer logic)
//
// This reimplements the essential mechanics of std::vector using a raw
// heap-allocated buffer, so you can see EXACTLY why each operation has the
// complexity it does:
//
// - The buffer is `T* data = new T[capacity]` - a single contiguous block.
// - `size`   = number of elements actually in use.
// - `capacity` = how much memory is currently allocated (>= size). The
//   compiler/library doesn't know some magic number - it just doubles (or
//   similar growth factor) whenever it runs out of room.
// - push_back:
//     if size == capacity -> grow (allocate new bigger block, copy every
//                             existing element over, delete the old block)
//     data[size] = value; size++;
// - insert(pos, value):
//     grow if needed, then shift every element from `pos` to `size-1` one
//     slot to the right (going backwards to avoid overwriting), THEN write
//     value into the gap. That shifting is why insert-in-the-middle is O(n).
// ----------------------------------------------------------------------------
void Lesson2b_VectorPointerLogic()
{
    std::cout << "\n=== Lesson 2b: std::vector<T> under the hood (raw pointer logic) ===\n";

    int size = 0;
    int capacity = 2;                       // deliberately small so growth is easy to see
    int* data = new int[capacity];

    auto grow = [&]()
    {
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; ++i)
        {
            newData[i] = data[i];           // copy every existing element into the new block
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
        std::cout << "  (grew capacity to " << capacity << " and copied " << size << " elements)\n";
    };

    auto pushBack = [&](int value)
    {
        if (size == capacity)
        {
            grow();
        }
        data[size] = value;
        ++size;
    };

    auto insertAt = [&](int index, int value)
    {
        if (size == capacity)
        {
            grow();
        }
        for (int i = size; i > index; --i)  // shift everything from the end backwards
        {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size;
    };

    auto print = [&]()
    {
        std::cout << "  data = ";
        for (int i = 0; i < size; ++i) std::cout << data[i] << " ";
        std::cout << "(size=" << size << ", capacity=" << capacity << ")\n";
    };

    pushBack(1);
    pushBack(2);
    print();

    pushBack(3); // size(2) == capacity(2) -> triggers grow() before appending
    print();

    insertAt(1, 99); // shifts elements at/after index 1 one slot right
    print();

    delete[] data;
}

// ----------------------------------------------------------------------------
// std::list<T>
//
// - Doubly-linked list. No random access (no operator[]).
// - O(1) insertion/removal ANYWHERE, as long as you already have an iterator
//   to that position (no shifting of other elements required).
// - Higher per-element memory overhead (each node stores prev/next pointers).
//
// Python has no built-in doubly-linked list type in the same sense - the
// closest standard-library match is collections.deque, which Python
// implements as a doubly-linked list of blocks, giving O(1) push/pop at
// both ends (but still no O(1) random-access indexing in the middle,
// similar in spirit to std::list):
//
//      from collections import deque
//      items = deque([1, 2, 3])
//      items.appendleft(0)
//      items.append(4)
// ----------------------------------------------------------------------------
void Lesson3_List()
{
    std::cout << "\n=== Lesson 3: std::list<T> (closest: Python's collections.deque) ===\n";

    std::list<int> items = { 1, 2, 3 };
    items.push_front(0); // O(1)
    items.push_back(4);  // O(1)
    Print("items after push_front(0) & push_back(4)", items);

    // Insert in the middle in O(1) once you have an iterator - no shifting!
    auto it = std::find(items.begin(), items.end(), 2);
    items.insert(it, 99); // insert 99 right before the element '2'
    Print("items after inserting 99 before '2'", items);

    // items[0]; // <-- would NOT compile: std::list has no operator[]
}

// ----------------------------------------------------------------------------
// std::list<T> - UNDER THE HOOD (manual pointer logic)
//
// A linked list is just a chain of independently allocated Node objects,
// each holding a value and a pointer to the next node. There is no single
// contiguous buffer, which is exactly why:
//
// - There's no operator[]: to reach the Nth element you MUST walk the chain
//   one `next` pointer at a time - O(n), no shortcuts.
// - Inserting/removing is just pointer rewiring (no shifting of memory),
//   which is O(1) once you already have a pointer to the right spot.
// ----------------------------------------------------------------------------
struct ListNode
{
    int value;
    ListNode* next;
};

void Lesson3b_ListPointerLogic()
{
    std::cout << "\n=== Lesson 3b: std::list<T> under the hood (raw pointer logic) ===\n";

    ListNode* head = nullptr;

    auto pushFront = [&](int value)
    {
        ListNode* node = new ListNode{ value, head };
        head = node; // no shifting - just repoint head
    };

    auto pushBack = [&](int value)
    {
        ListNode* node = new ListNode{ value, nullptr };
        if (!head)
        {
            head = node;
            return;
        }
        ListNode* cur = head;
        while (cur->next) cur = cur->next; // O(n) walk - no direct "end" access here
        cur->next = node;
    };

    auto insertAfterValue = [&](int afterValue, int value)
    {
        ListNode* cur = head;
        while (cur && cur->value != afterValue) cur = cur->next; // O(n) search
        if (cur)
        {
            ListNode* node = new ListNode{ value, cur->next };
            cur->next = node; // O(1) once positioned - just two pointer writes
        }
    };

    auto print = [&]()
    {
        std::cout << "  items = ";
        for (ListNode* cur = head; cur; cur = cur->next) std::cout << cur->value << " ";
        std::cout << "\n";
    };

    pushFront(1);
    pushFront(0);
    pushBack(2);
    print(); // 0 1 2

    insertAfterValue(1, 99);
    print(); // 0 1 99 2

    // Clean up manually - no destructor magic here, just like raw `new`.
    ListNode* cur = head;
    while (cur)
    {
        ListNode* next = cur->next;
        delete cur;
        cur = next;
    }
}

// ----------------------------------------------------------------------------
// std::deque<T> ("double-ended queue")
//
// - Random access O(1) like vector (though slightly slower in practice due
//   to indirection through internal "map of blocks").
// - O(1) push/pop at BOTH the front and the back (vector is only O(1) at
//   the back).
//
// Python equivalent: collections.deque - literally the same concept and
// even the same name:
//
//      from collections import deque
//      dq = deque([1, 2, 3])
//      dq.appendleft(0)   # O(1)
//      dq.append(4)       # O(1)
//      dq[2]              # O(1) random access
// ----------------------------------------------------------------------------
void Lesson4_Deque()
{
    std::cout << "\n=== Lesson 4: std::deque<T> (like Python's collections.deque) ===\n";

    std::deque<int> dq = { 1, 2, 3 };
    dq.push_front(0); // O(1), unlike std::vector which has no push_front
    dq.push_back(4);  // O(1)
    Print("dq after push_front(0) & push_back(4)", dq);

    std::cout << "random access dq[2] = " << dq[2] << " (O(1), like a Python deque's dq[2])\n";
}

// ----------------------------------------------------------------------------
// std::map<K, V>
//
// - Ordered associative container, implemented as a balanced binary search
//   tree (typically red-black tree).
// - Keys are ALWAYS kept sorted (by operator< or a custom comparator).
// - Lookup/insert/erase are O(log n).
//
// Python's built-in dict does NOT keep keys sorted - it preserves
// INSERTION order (since Python 3.7), not key order. The truest equivalent
// to std::map's "always sorted by key" behaviour is a sorted structure, e.g.
// the third-party 'sortedcontainers.SortedDict', or manually calling
// sorted(d.items()) each time you need ordered iteration:
//
//      d = {}
//      d["banana"] = 1
//      d["apple"] = 4
//      for k, v in sorted(d.items()):   # sorted() needed to mimic std::map
//          print(k, v)
// ----------------------------------------------------------------------------
void Lesson5_Map()
{
    std::cout << "\n=== Lesson 5: std::map<K,V> (like a Python dict, but kept SORTED by key) ===\n";

    std::map<std::string, int> fruitCounts;
    fruitCounts["banana"] = 1;
    fruitCounts["apple"] = 4;
    fruitCounts["orange"] = 3;

    // Iterating a std::map ALWAYS yields keys in sorted order - no need to
    // sort explicitly, unlike Python's dict.
    for (const auto& entry : fruitCounts)
    {
        std::cout << "  " << entry.first << " -> " << entry.second << "\n";
    }

    auto it = fruitCounts.find("apple");
    if (it != fruitCounts.end())
    {
        std::cout << "found apple -> " << it->second << " (O(log n) lookup)\n";
    }
}

// ----------------------------------------------------------------------------
// std::unordered_map<K, V>
//
// - Hash table. No ordering guarantees whatsoever (order can even change
//   between insertions as the table rehashes/grows).
// - Average O(1) lookup/insert/erase (worst case O(n) with hash collisions).
//
// Python equivalent: dict - Python's built-in dict IS a hash map under the
// hood, so this is the TRUEST match of any container pairing in this lesson:
//
//      d = {}
//      d["banana"] = 1
//      d["apple"] = 4
//      d["orange"] = 3
//      d["apple"]        # average O(1) lookup, just like unordered_map
// ----------------------------------------------------------------------------
void Lesson6_UnorderedMap()
{
    std::cout << "\n=== Lesson 6: std::unordered_map<K,V> (the truest match: Python's dict) ===\n";

    std::unordered_map<std::string, int> fruitCounts;
    fruitCounts["banana"] = 1;
    fruitCounts["apple"] = 4;
    fruitCounts["orange"] = 3;

    // Iteration order here is UNSPECIFIED - do not rely on it, just like you
    // shouldn't rely on hash-based ordering in most other languages either.
    std::cout << "Iteration order is unspecified (may differ across runs/compilers):\n";
    for (const auto& entry : fruitCounts)
    {
        std::cout << "  " << entry.first << " -> " << entry.second << "\n";
    }

    auto it = fruitCounts.find("apple");
    if (it != fruitCounts.end())
    {
        std::cout << "found apple -> " << it->second << " (average O(1) lookup)\n";
    }
}

// ----------------------------------------------------------------------------
// std::unordered_map<K, V> - UNDER THE HOOD (manual pointer logic)
//
// A hash table is really just: an array of "buckets" (an array of
// pointers), plus a hash function that maps a key to a bucket index.
//
// - bucket index = hash(key) % bucketCount
// - Each bucket is the HEAD of a small linked list (a "chain"). Multiple
//   keys that hash to the same bucket index just get appended to that
//   bucket's chain - that's a "collision".
// - find(key): hash the key -> jump DIRECTLY to that bucket (O(1)) -> then
//   walk the (hopefully short) chain comparing keys until you find a match.
// - So there's no single direct reference straight to an element from
//   outside - you always go bucket-first, then chain. Average O(1) assumes
//   chains stay short (good hash + enough buckets); worst case (everything
//   collides into one bucket) degrades to O(n).
// ----------------------------------------------------------------------------
struct HashNode
{
    std::string key;
    int value;
    HashNode* next; // next node in THIS bucket's collision chain
};

void Lesson6b_UnorderedMapPointerLogic()
{
    std::cout << "\n=== Lesson 6b: std::unordered_map<K,V> under the hood (raw pointer logic) ===\n";

    const int bucketCount = 4; // deliberately tiny so collisions are visible
    HashNode* buckets[bucketCount] = { nullptr, nullptr, nullptr, nullptr };

    auto bucketIndex = [&](const std::string& key)
    {
        std::size_t h = std::hash<std::string>{}(key);
        return static_cast<int>(h % bucketCount);
    };

    auto insert = [&](const std::string& key, int value)
    {
        int idx = bucketIndex(key);
        for (HashNode* cur = buckets[idx]; cur; cur = cur->next)
        {
            if (cur->key == key) { cur->value = value; return; } // update existing
        }
        // prepend new node to the front of this bucket's chain
        buckets[idx] = new HashNode{ key, value, buckets[idx] };
    };

    auto find = [&](const std::string& key) -> HashNode*
    {
        int idx = bucketIndex(key);
        for (HashNode* cur = buckets[idx]; cur; cur = cur->next)
        {
            if (cur->key == key) return cur; // direct pointer to the matching node
        }
        return nullptr;
    };

    insert("banana", 1);
    insert("apple", 4);
    insert("orange", 3);

    for (int i = 0; i < bucketCount; ++i)
    {
        std::cout << "  bucket[" << i << "] = ";
        for (HashNode* cur = buckets[i]; cur; cur = cur->next)
        {
            std::cout << "(" << cur->key << "->" << cur->value << ") ";
        }
        std::cout << "\n";
    }

    if (HashNode* found = find("apple"))
    {
        std::cout << "found apple -> " << found->value
                   << " (jumped to bucket " << bucketIndex("apple") << " directly)\n";
    }

    // Clean up every chain.
    for (int i = 0; i < bucketCount; ++i)
    {
        HashNode* cur = buckets[i];
        while (cur)
        {
            HashNode* next = cur->next;
            delete cur;
            cur = next;
        }
    }
}

void RunContainersLesson()
{
    std::cout << "############################################\n";
    std::cout << "#         C++ CONTAINERS LESSON            #\n";
    std::cout << "#   (compared against Python containers)   #\n";
    std::cout << "############################################\n";

    Lesson1_Array();
    Lesson2_Vector();
    Lesson2b_VectorPointerLogic();
    Lesson3_List();
    Lesson3b_ListPointerLogic();
    Lesson4_Deque();
    Lesson5_Map();
    Lesson6_UnorderedMap();
    Lesson6b_UnorderedMapPointerLogic();

    std::cout << "\nDone! Key takeaways:\n";
    std::cout << "  std::array          <-> Python tuple (fixed-size)\n";
    std::cout << "  std::vector         <-> Python list\n";
    std::cout << "  std::list           <-> Python collections.deque (linked-list semantics)\n";
    std::cout << "  std::deque          <-> Python collections.deque\n";
    std::cout << "  std::map            <-> Python dict, but SORTED (Python dict is insertion-ordered)\n";
    std::cout << "  std::unordered_map  <-> Python dict (truest match - both are hash maps)\n";
}
