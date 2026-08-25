#include "DynamicBuffer.h"
#include <utility>

DynamicBuffer::DynamicBuffer(std::size_t elementCount)
    : m_data(new double[elementCount]{}), m_count(elementCount)
{
}

// 1. Destructor - releases owned memory
DynamicBuffer::~DynamicBuffer()
{
    delete[] m_data;
}

// 2. Copy constructor - deep copies the buffer
DynamicBuffer::DynamicBuffer(const DynamicBuffer& source)
    : m_data(new double[source.m_count]), m_count(source.m_count)
{
    for (std::size_t i = 0; i < m_count; ++i)
    {
        m_data[i] = source.m_data[i];
    }
}

// 3. Copy assignment operator - deep copies, releasing old memory first
DynamicBuffer& DynamicBuffer::operator=(const DynamicBuffer& source)
{
    if (this != &source)
    {
        double* newData = new double[source.m_count];
        for (std::size_t i = 0; i < source.m_count; ++i)
        {
            newData[i] = source.m_data[i];
        }

        delete[] m_data;
        m_data = newData;
        m_count = source.m_count;
    }
    return *this;
}

// 4. Move constructor - steals the pointer, leaves source empty
DynamicBuffer::DynamicBuffer(DynamicBuffer&& source) noexcept
    : m_data(source.m_data), m_count(source.m_count)
{
    source.m_data = nullptr;
    source.m_count = 0;
}

// 5. Move assignment operator - releases old memory, steals new pointer
DynamicBuffer& DynamicBuffer::operator=(DynamicBuffer&& source) noexcept
{
    if (this != &source)
    {
        delete[] m_data;
        m_data = source.m_data;
        m_count = source.m_count;

        source.m_data = nullptr;
        source.m_count = 0;
    }
    return *this;
}
