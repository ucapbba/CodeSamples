#ifndef NEWTONEQNS_H_
#define NEWTONEQNS_H_
#include <array>
//#include <boost/numeric/ublas/blas.hpp>
#include <boost/numeric/ublas/vector.hpp>
//#include <boost/numeric/ublas/matrix.hpp>
typedef std::vector<double> phase_space;

class NewtonEqns {
public:
    NewtonEqns(bool isCoulomb, bool isCos7, bool isVolker);

    void operator ()(const phase_space& x, phase_space& dxdt, const double t);

private:
    double Ip, Up, w, rtUp, C;
	bool Coulomb, Cos7, Volker;
	NewtonEqns();
};


#endif
