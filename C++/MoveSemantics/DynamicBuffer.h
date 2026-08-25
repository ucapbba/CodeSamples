#pragma once
#include <cstddef>

// Demonstrates the Rule of Five: a resource-owning class must define
// (or explicitly default) all five special member functions if it
// manages a raw resource such as heap memory.
class DynamicBuffer
{
public:
    explicit DynamicBuffer(std::size_t elementCount = 10);

    // 1. Destructor - releases owned memory
    ~DynamicBuffer();

    // 2. Copy constructor - deep copies the buffer
    DynamicBuffer(const DynamicBuffer& source);

    // 3. Copy assignment operator - deep copies, releasing old memory first
    DynamicBuffer& operator=(const DynamicBuffer& source);

    // 4. Move constructor - steals the pointer, leaves source empty
    DynamicBuffer(DynamicBuffer&& source) noexcept;

    // 5. Move assignment operator - releases old memory, steals new pointer
    DynamicBuffer& operator=(DynamicBuffer&& source) noexcept;

    std::size_t count() const noexcept { return m_count; }
    double& at(std::size_t index) { return m_data[index]; }
    double at(std::size_t index) const { return m_data[index]; }

private:
    double* m_data;
    std::size_t m_count;
};