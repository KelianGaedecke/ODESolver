#include "ODESolver.hpp"
#include <stdexcept>
#include <fstream>   
#include <iostream> 

void RK4(std::function<double(double, double)> f, double y0, double t0, double tf, double dt) {
    double t = t0;
    double y = y0;

    if (dt <= 0) {
        throw std::runtime_error("dt must be bigger than 0");
    }
    printf("Let's use RK4 method to solve this!")

    std::ofstream outFile("RK4.out");
    if (!outFile.is_open()) {
        throw std::runtime_error("Unable to open output file");
    }

    outFile << "t\ty\n";

    while (t <= tf) {
        double k1 = f(t, y);
        double k2 = f(t + 0.5 * dt, y + 0.5 * k1 * dt);
        double k3 = f(t + 0.5 * dt, y + 0.5 * k2 * dt);
        double k4 = f(t + dt, y + k3 * dt);

        y += (k1 + 2 * k2 + 2 * k3 + k4) * dt / 6.0;
        t += dt;

        outFile << t << "\t" << y << std::endl;
    }

    outFile.close();
}

// Verlet Method
void Verlet(std::function<double(double, double)> f, double y0, double t0, double tf, double dt) {
    double t = t0;
    double y_prev = y0;
    double y = y0;
    double y_next = y0 + dt * f(y, t);

    if (dt <= 0) {
        throw std::runtime_error("dt must be bigger than 0");
    }
    printf("Let's use Verlet method to solve this!")

    std::ofstream outFile("Verlet.out"); 
    if (!outFile.is_open()) {
        throw std::runtime_error("Unable to open output file");
    }

    outFile << "t\ty\n";

    while (t <= tf) {
        y_next = 2 * y - y_prev + dt * dt * f(t, y);
        y_prev = y;
        y = y_next;
        t += dt;

        outFile << t << "\t" << y << std::endl;
    }

    outFile.close();
}

