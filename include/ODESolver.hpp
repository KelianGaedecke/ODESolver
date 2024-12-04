#ifndef ODES_HPP
#define ODES_HPP

#include <iostream>
#include <vector>
#include <functional>

class ODES {
public:
    virtual void solve(std::function<double(double,double)> f, double y0, double t0, double tf, double dt) = 0;
};

class RK4 : public ODES {
public:
    void solve(std::function<double(double, double)> f, double y0, double t0, double t_end, double dt) override;
};

class Verlet : public ODES {
public:
    void solve(std::function<double(double, double)> f, double y0, double t0, double t_end, double dt) override;
};

#endif