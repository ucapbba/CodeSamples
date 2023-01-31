#pragma once
class Pulse
{
public:
	Pulse(double _up0, double _phi, double _nCycle) : up0(_up0), phi(_phi) , nCycle(_nCycle) {}
	double GetAField(double t);
	double GetUp0() {return up0;}
	double GetPhi() { return phi; }
	double GetCycle() { return nCycle; }

private:
	double up0;
	double phi;
	double nCycle;
};

