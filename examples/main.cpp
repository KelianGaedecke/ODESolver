#include <iostream>
#include "ODESolver.hpp"

double examplefunction(double t, double y){
    return -2 * y; // "dy/dt = -2y"
}

int main(){
    double y0 = 1.0;
    double t0 = 0.0;
    double tf = 10.0;
    double dt = 0.1;

    RK4 rk_solv ;
    Verlet v_solv ;

    printf("Using Runge-Kutta method: \n");
    rk_solv.solve(y0,t0,tf,dt);

    printf("Using Verlet method: \n");
    v_solv.solve(y0,t0,tf,dt);  

    return 0;
}