// PyBind.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// The installed Python distribution only ships release import libraries
// (no python3xx_d.lib). Temporarily undefine _DEBUG so Python.h doesn't
// request the debug-suffixed library when building this project in Debug mode.
#ifdef _DEBUG
#define PYBINDAIRY_RESTORE_DEBUG
#undef _DEBUG
#endif
#include <Python.h>
#ifdef PYBINDAIRY_RESTORE_DEBUG
#define _DEBUG
#undef PYBINDAIRY_RESTORE_DEBUG
#endif

#include <pybind11.h>
#include <numpy.h>
#include <complex>
#include <embed.h>

using namespace std::complex_literals;
namespace py = pybind11;
int main()
{
	// Py_SetPythonHome is deprecated since Python 3.11; the interpreter can
	// locate its own installation automatically, so we no longer set it explicitly.
	pybind11::scoped_interpreter guard{};
	pybind11::exec("print('hello world')");

	PyRun_SimpleString("import scipy");
	py::object SciPy = py::module_::import("scipy.special");
	py::function airy = SciPy.attr("airy");

    //double input
    py::object airyval = airy(1.0);
    py::object Val = airyval.attr("__getitem__")(0);
    py::object Val2 = airyval.attr("__getitem__")(1);
    double Vald = Val.cast<double>();
    double Val2d = Val2.cast<double>();
    
    //get first 2 values
    std::cout << "Val 1 = " << Vald <<std::endl;  //0.13529241631288147
    std::cout << "Val 2 = " << Val2d << std::endl; //-0.15914744129679328

  // Python output
  // special.airy(1)
  /*  (0.13529241631288147,
        -0.15914744129679328,
        1.2074235949528715,
        0.9324359333927756)*/

    //complex input
    std::complex<double> z4 = 1. + 2i;
    py::object airyvalcomplex = airy(z4);
    py::object Val3 = airyvalcomplex.attr("__getitem__")(0);
    std::complex<double> Val3c = Val3.cast<std::complex<double>>();
    std::cout << "Val 3 = " << Val3c << std::endl;

    //Python output
    //special.airy(complex(1, 2))
    /*((-0.21938625498142755 - 0.17538591140810947j),
        (0.1704449781789148 + 0.3876224394132943j),
        (0.04882203245306146 + 0.13327405799174857j),
        (-0.8572392586053617 + 0.49550633630956675j))*/

   // Py_Finalize();  

}
