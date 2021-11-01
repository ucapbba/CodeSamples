
//Entity.h
#pragma once
#include "ManagedObject.h"
#include "../OrbitFinder/Core.h"
using namespace System;
namespace OrbitFinderCLR
{
	
	public ref class Input : public ManagedObject<OrbitFinderCore::Input>
	{
	public:

		Input(float _omega, float Up, float E1g, float E2g, float E2e, float p_max, float p_min, float dp,
			float p_perp_max, float p_perp_min, float dp_perp);
		double Omega();
		double Up();
		double E1g();
		double E2g();
		double E2e();
		double p_Min();
		double p_Max();
		double dp();
		double p_Min_Perp();
		double p_Max_Perp();
		double dp_Perp();
	};
}