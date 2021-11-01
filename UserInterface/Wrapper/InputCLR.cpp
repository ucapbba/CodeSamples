
//Entity.cpp
#include "InputCLR.h"
namespace OrbitFinderCLR
{
	Input::Input(float _omega, float Up, float E1g, float E2g, float E2e, float p_max, float p_min, float dp,
		float p_perp_max, float p_perp_min, float dp_perp)
		: ManagedObject(new OrbitFinderCore::Input(_omega, Up, E1g, E2g,  E2e, p_max, p_min,  dp, p_perp_max, p_perp_min, dp_perp))
	{}
	double Input::Omega()
	{
		return m_Instance->Omega();
	}
	double Input::Up()
	{
		return m_Instance->Up();
	}
	double Input::E1g()
	{
		return m_Instance->E1g();
	}
	double Input::E2g()
	{
		return m_Instance->E2g();
	}
	double Input::E2e()
	{
		return m_Instance->E2e();
	}
	double Input::p_Min()
	{
		return m_Instance->p_Min();
	}
	double Input::p_Max()
	{
		return m_Instance->p_Max();
	}
	double Input::dp()
	{
		return m_Instance->dp();
	}
	double Input::p_Min_Perp()
	{
		return m_Instance->p_Min_Perp();
	}
	double Input::p_Max_Perp()
	{
		return m_Instance->p_Max_Perp();
	}
	double Input::dp_Perp()
	{
		return m_Instance->dp_Perp();
	}
}