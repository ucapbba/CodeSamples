#pragma once
class __declspec(dllexport) myClassStatic
{
	public:
		static void AppendVariable();
		static double GetVariable();

	private:
		static double variable;

};

