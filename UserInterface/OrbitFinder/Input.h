#ifndef  _INPUT_
#define _INPUT_

#include <vector>
#include <complex>
namespace OrbitFinderCore
{
	class Input
	{
	public:
		Input(double _omega, double Up, double E1g, double E2g, double E2e, double p_max, double p_min, double dp,
			double p_perp_max, double p_perp_min, double dp_perp);

		std::complex<double>& t1short();
		std::complex<double>& t2short();
		std::complex<double>& t3short();
		std::complex<double>& t1long();
		std::complex<double>& t2long();
		std::complex<double>& t3long();
		std::vector<std::complex<double>> AllTimes();

		double Omega() const;
		double Up() const;
		double E1g() const;
		double E2g() const;
		double E2e() const;

		double p_Min();
		double p_Max();
		double dp();
		int p_Range();
		double p_Min_Perp();
		double p_Max_Perp();
		double dp_Perp();
		int p_Range_Perp();

		int nTheta();
		double dTheta();

	private:
		std::vector<double> momRanges;
		std::vector<std::complex<double>> timesShort;
		std::vector<std::complex<double>> timesLong;
		double omega;
		double _Up;
		double _E1g, _E2g, _E2e;
		double _nTheta, _dTheta;
	};
}
#endif // ! _INPUT_PARAMS
