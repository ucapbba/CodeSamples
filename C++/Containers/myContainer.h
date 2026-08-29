#pragma once
#include <memory>
class myContainer
{
public: 
	myContainer() 
	{
		data = std::make_unique<int[]>(capacity);
	}
	
	~myContainer() 
	{
	}

	void add_to_end(int value) 
	{
		if (size == capacity)
		{
			capacity = capacity * 2;
			auto newData = std::make_unique<int[]>(capacity);
			for (int i = 0; i < size; i++) 
			{
				newData[i] = data[i];
			}
			data = std::move(newData);
		}

		// add value to the end of the container
		data[size] = value;
		size++;
	}

	int operator[](int index)
	{
		if (index > size - 1 || index < 0)
			return -1;
	    return data[index];
	}

	private :
		std::unique_ptr<int[]> data;
		int size = 0;
		int capacity = 10;
		myContainer(const myContainer&) = delete;
		myContainer& operator=(const myContainer&) = delete;

};

