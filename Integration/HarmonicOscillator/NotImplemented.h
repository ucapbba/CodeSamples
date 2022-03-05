
//class harm_osc {
//
//    double m_gam;
//
//public:
//    harm_osc(double gam) : m_gam(gam) { }
//
//    void operator() (const state_type &x, state_type &dxdt, const double /* t */)
//    {
//        dxdt[0] = x[1];
//        dxdt[1] = -x[0] - m_gam * x[1];
//    }
//};

void NotImplemented()
{

    //[ integration
    //size_t steps = integrate(harmonic_oscillator,
    //    x, 0.0, 10.0, 0.1);
    //]

    //[ integration_class
    //harm_osc ho(0.15);
    //steps = integrate(ho,
    //    x, 0.0, 10.0, 0.1);
    //]

    ////[ define_const_stepper
    //runge_kutta4< state_type > stepper;
    //integrate_const(stepper, harmonic_oscillator, x, 0.0, 10.0, 0.01);
    ////]

    ////[ integrate_const_loop
    //const double dt = 0.01;
    //for (double t = 0.0; t < 10.0; t += dt)
    //    stepper.do_step(harmonic_oscillator, x, t, dt);
    ////]

    ////[ define_adapt_stepper
    //typedef runge_kutta_cash_karp54< state_type > error_stepper_type;
    ////]

    ////[ integrate_adapt
    //typedef controlled_runge_kutta< error_stepper_type > controlled_stepper_type;
    //controlled_stepper_type controlled_stepper;
    //integrate_adaptive(controlled_stepper, harmonic_oscillator, x, 0.0, 10.0, 0.01);
    ////]

    //{
    //    //[integrate_adapt_full 
    //    //TODO check default_error_checker template
    //   /* double abs_err = 1.0e-10, rel_err = 1.0e-6, a_x = 1.0, a_dxdt = 1.0;
    //    controlled_stepper_type controlled_stepper(
    //        default_error_checker< double >(abs_err, rel_err, a_x, a_dxdt));
    //    integrate_adaptive(controlled_stepper, harmonic_oscillator, x, 0.0, 10.0, 0.01);*/
    //    //]
    //}

    ////[integrate_adapt_make_controlled
    //integrate_adaptive(make_controlled< error_stepper_type >(1.0e-10, 1.0e-6),
    //    harmonic_oscillator, x, 0.0, 10.0, 0.01);
    ////]

    ////[integrate_adapt_make_controlled_alternative
    //integrate_adaptive(make_controlled(1.0e-10, 1.0e-6, error_stepper_type()),
    //    harmonic_oscillator, x, 0.0, 10.0, 0.01);
    ////]

}
