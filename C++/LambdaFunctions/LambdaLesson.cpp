// ============================================================================
// LambdaLesson.cpp
//
// Implementation of the step-by-step lambda lessons declared in
// LambdaLesson.h, ending with the exact pattern used in the Athene codebase:
//
//      static const auto cache = []() { ... }();
//
// Note: this project targets C++14, so C++17 structured bindings
// (e.g. "for (const auto& [k, v] : map)") are NOT used here - we access
// .first / .second on the pair instead.
// ============================================================================

#include "LambdaLesson.h"

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>

// ----------------------------------------------------------------------------
// Helper used later to simulate an "expensive" data source, similar to
// CSxDbAccess::GetThirdPartyDomicileValues(...) in the real codebase.
// ----------------------------------------------------------------------------
namespace
{
    void GetThirdPartyDomicileValuesSimulated(std::set<std::string>& domiciles)
    {
        std::cout << "  [GetThirdPartyDomicileValuesSimulated] Simulating an expensive DB call...\n";
        domiciles = { "FR", "US", "GB", "DE" };
    }
}

void Lesson1_BasicLambdaSyntax()
{
    std::cout << "\n=== Lesson 1: Basic lambda syntax ===\n";

    // A lambda is an unnamed function object you can define inline.
    // Anatomy:  [captures](parameters) -> returnType { body }
    //
    // - [captures]  : what from the surrounding scope the lambda can access
    // - (parameters): just like a normal function's parameter list
    // - -> returnType: optional; usually the compiler infers it for you
    // - { body }    : the code that runs when the lambda is called

    auto add = [](int a, int b) -> int
    {
        return a + b;
    };

    std::cout << "add(2, 3) = " << add(2, 3) << "\n";

    // The return type is almost always omittable; the compiler deduces it
    // from the return statement(s).
    auto multiply = [](int a, int b)
    {
        return a * b;
    };

    std::cout << "multiply(4, 5) = " << multiply(4, 5) << "\n";
}

void Lesson2_Captures()
{
    std::cout << "\n=== Lesson 2: Captures ([...]) ===\n";

    int threshold = 10;

    // [=] captures everything used in the body BY VALUE (a copy is made).
    auto isAboveByValue = [=](int x)
    {
        return x > threshold;
    };

    // [&] captures everything used in the body BY REFERENCE.
    auto isAboveByRef = [&](int x)
    {
        return x > threshold;
    };

    std::cout << "isAboveByValue(15) = " << std::boolalpha << isAboveByValue(15) << "\n";

    threshold = 20; // Mutate the outer variable AFTER capturing.

    // Because isAboveByValue captured threshold BY VALUE at creation time,
    // it still uses the OLD value (10), even though 'threshold' is now 20.
    std::cout << "After threshold changed to 20:\n";
    std::cout << "isAboveByValue(15) [captured old value] = " << isAboveByValue(15) << "\n";

    // isAboveByRef captured threshold BY REFERENCE, so it sees the NEW value (20).
    std::cout << "isAboveByRef(15)   [sees current value] = " << isAboveByRef(15) << "\n";

    // You can also capture individual variables explicitly:
    int a = 1, b = 2;
    auto explicitCapture = [a, &b]()
    {
        // 'a' is a copy, 'b' is a reference.
        std::cout << "explicitCapture: a=" << a << ", b=" << b << "\n";
    };
    b = 99;
    explicitCapture(); // prints a=1 (unchanged copy), b=99 (reference sees the update)
}

void Lesson3_LambdasAsAlgorithmCallbacks()
{
    std::cout << "\n=== Lesson 3: Lambdas as callbacks for STL algorithms ===\n";

    std::vector<int> values{ 5, 2, 8, 1, 9, 3 };

    // std::sort with a custom comparator lambda: sort descending.
    std::sort(values.begin(), values.end(), [](int lhs, int rhs)
    {
        return lhs > rhs;
    });

    std::cout << "Sorted descending: ";
    for (int v : values) std::cout << v << " ";
    std::cout << "\n";

    // std::count_if with a predicate lambda.
    int countAboveFour = static_cast<int>(std::count_if(values.begin(), values.end(), [](int v)
    {
        return v > 4;
    }));
    std::cout << "Count of values > 4: " << countAboveFour << "\n";
}

void Lesson4_ImmediatelyInvokedLambda()
{
    std::cout << "\n=== Lesson 4: Immediately Invoked Lambda (IIFE) ===\n";

    // Sometimes you need several statements (loops, temporaries, branching)
    // to compute the value of a variable you'd like to be 'const'.
    // You CANNOT do this directly:
    //
    //     const int result = { for(...) ... };   // ILLEGAL - not an expression
    //
    // But a lambda body CAN contain multiple statements, and calling it
    // immediately (note the trailing "()") turns the whole thing into a
    // single expression, whose result initializes the const variable.

    const int sumOfSquaresUpTo5 = [] // <-- capture nothing
    {
        int total = 0;
        for (int i = 1; i <= 5; ++i)
        {
            total += i * i;
        }
        return total;
    }(); // <--- called immediately right here

    std::cout << "sumOfSquaresUpTo5 (1^2+2^2+...+5^2) = " << sumOfSquaresUpTo5 << "\n";

    // This is exactly the same trick used to build a std::unordered_map
    // in a single const-initializer, which brings us to the final lesson.
}

// ----------------------------------------------------------------------------
// Lesson 5 recreates (in simplified form) the exact pattern from the Athene
// codebase:
//
//      const std::unordered_map<std::string, long>& GetDomicileCache()
//      {
//          static const auto cache = []() {
//              std::unordered_map<std::string, long> result;
//              std::set<std::string> domiciles;
//              CSxDbAccess::GetThirdPartyDomicileValues(domiciles);
//
//              long code = 1;
//              for (const auto& d : domiciles) {
//                  result[d] = code++;
//              }
//              return result;
//          }();
//          return cache;
//      }
//
// Why combine "static" + a lambda IIFE?
//   1. LAZY INIT     - the "expensive" work only happens the first time this
//                       function is called, not at program startup.
//   2. THREAD SAFETY - since C++11, initialization of a function-local
//                       'static' variable is guaranteed thread-safe: if two
//                       threads call this function at the same time, the
//                       lambda body runs EXACTLY ONCE, and the other thread
//                       just waits for it to finish.
//   3. CACHED FOREVER - after the first call, we simply return a reference
//                       to the already-built map; no recomputation.
//   4. CONST-CORRECT  - the map can be declared 'const' because it is built
//                       entirely inside the lambda and never mutated after.
// ----------------------------------------------------------------------------
namespace
{
    const std::unordered_map<std::string, long>& GetDomicileCache()
    {
        static const auto cache = []()
        {
            std::cout << "  [GetDomicileCache] Building cache for the first (and only) time...\n";

            std::unordered_map<std::string, long> result;
            std::set<std::string> domiciles; // std::set keeps entries sorted & unique

            GetThirdPartyDomicileValuesSimulated(domiciles);

            // Assign sequential codes starting at 1, in sorted order (because
            // std::set is ordered), giving a deterministic, repeatable mapping.
            long code = 1;
            for (const auto& d : domiciles)
            {
                result[d] = code++;
            }

            return result; // this becomes the value of 'cache'
        }(); // <-- immediately invoked, exactly once, thread-safely

        return cache;
    }
}

void Lesson5_LazyStaticCachePattern()
{
    std::cout << "\n=== Lesson 5: The real-world pattern - lazy static cache via lambda ===\n";

    std::cout << "First call to GetDomicileCache():\n";
    const auto& cache1 = GetDomicileCache();
    for (const auto& entry : cache1)
    {
        std::cout << "    " << entry.first << " -> " << entry.second << "\n";
    }

    std::cout << "Second call to GetDomicileCache() (notice: no 'Building cache...' message this time):\n";
    const auto& cache2 = GetDomicileCache();
    std::cout << "    cache2 has " << cache2.size() << " entries (same object, not rebuilt).\n";

    // Proof it's genuinely the same cached object:
    std::cout << "    &cache1 == &cache2 ? " << std::boolalpha << (&cache1 == &cache2) << "\n";
}

void RunLambdaLesson()
{
    std::cout << "############################################\n";
    std::cout << "#           C++ LAMBDA LESSON              #\n";
    std::cout << "############################################\n";

    Lesson1_BasicLambdaSyntax();
    Lesson2_Captures();
    Lesson3_LambdasAsAlgorithmCallbacks();
    Lesson4_ImmediatelyInvokedLambda();
    Lesson5_LazyStaticCachePattern();

    std::cout << "\nDone! Try tweaking the lessons above and re-running to build intuition.\n";
}
