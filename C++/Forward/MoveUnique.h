#include <iostream>
#include <vector>

//example of using a unique pointer and how you would pass it to a class constructor
//note we are using an rvalue variable so we would have to consider forward when calling this class

struct __declspec(dllexport) SSx_TW_core
{
	std::unique_ptr<std::vector<int>> clauses;
};

class __declspec(dllexport) CSx_TW_model
{
public:
	CSx_TW_model(SSx_TW_core&& _coreData) : coreData(std::move(_coreData)) 
	{}

	SSx_TW_core GetCoreData()
	{
		return std::move(coreData);
	}
private:
	CSx_TW_model() {};
	SSx_TW_core coreData;
};
