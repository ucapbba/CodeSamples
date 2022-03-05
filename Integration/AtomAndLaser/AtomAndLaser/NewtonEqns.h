#ifndef NEWTONEQNS_H_
#define NEWTONEQNS_H_
#include <array>
//#include <boost/numeric/ublas/blas.hpp>
#include <boost/numeric/ublas/vector.hpp>
//#include <boost/numeric/ublas/matrix.hpp>
typedef std::vector<double> phase_space;

class NewtonEqns {
public:
    NewtonEqns();

    void operator ()(const phase_space& x, phase_space& dxdt, const double t);

private:
    double Ip, Up, w, rtUp, C;
};

struct potParams {
    potParams(double a1_, double a2_, double a3_, double a4_, double a5_, double a6_);
    double a1, a2, a3, a4, a5, a6;
};
#endif
