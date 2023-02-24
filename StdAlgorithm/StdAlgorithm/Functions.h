#pragma once
bool myfunction(int i, int j) { return (i > j); }

struct Sum
{
	void operator()(int n) { sum += n; }
	int sum{ 0 };
};


class initCondVars {
public:
	initCondVars(int a, int b);
	int variable1;
	int variable2;
};
initCondVars::initCondVars(int a, int b)
{
	variable1 = a;
	variable2 = b;
}
bool myfunctionInit1(initCondVars i, initCondVars j) { return (i.variable1 < j.variable1); }
bool myfunctionInit2(initCondVars i, initCondVars j) { return (i.variable2 > j.variable2); }
bool myfunctionInit3(initCondVars i, initCondVars j) {
	if (i.variable1 != j.variable1)
	{
		return i.variable1 < j.variable1;
	}
	else
	{
		i.variable1 > j.variable1;
	}
}