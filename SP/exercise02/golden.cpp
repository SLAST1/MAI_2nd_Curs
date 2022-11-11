// Пивницкий М8о-206Б-19
#include "mlisp.h"

extern double a;
extern double b;
extern double tolerance;
extern double total__iterations;
extern double xmin;
extern double mphi;

double fun(double x);
double golden__section__search(double a, double b);
double golden__start(double a, double b);
double __pds__try(double a, double b, double xa, double ya, double xb, double yb);
bool close__enough_Q(double x, double y);

double a = 1.;
double b = 3.;

double fun(double x) {
    x = x - 19. / 20.;
    return 5. * expt(log(expt(atan(x - 2.), 2.)), 4.) - x - 7.;
}

double golden__section__search(double a, double b) {
    {
        double xmin(a < b ? golden__start(a, b) : golden__start(b, a));
        newline();
        return xmin;
    }
}

double golden__start(double a, double b) {
    total__iterations = 0;
    {
        double 
            xa(a + mphi * (b - a)),
            xb(b + (-(mphi * (b - a))));
        return __pds__try(a, b, xa, fun(xa), xb, fun(xb));
    }
}

double mphi = (3. - sqrt(5.)) * (1. / 2.);

double __pds__try(double a, double b, double xa, double ya, double xb, double yb) {
    return close__enough_Q(a, b) ? (a + b) * 0.5 :
        (
            display("+"),
            total__iterations = total__iterations + 1.,
            (ya < yb ? 
            (
                b = xb,
                xb = xa,
                yb = ya,
                xa = a + mphi * (b - a),
                __pds__try(a, b, xa, fun(xa), xb, yb)
            ) :
            (
                a = xa,
                xa = xb,
                ya = yb,
                xb = b - mphi * (b - a),
                __evs__try(a, b, xa, ya, xb, fun(xb))
            )) 
        ); 
}

bool close__enough_Q(double x, double y) {
    return __pds__abs(x - y) < tolerance;
}

double tolerance = 0.001;
double total__iterations = 0.;
double xmin = 0.;

int main() {
    xmin = golden__section__search(a, b);
    display("Interval=\t[");
    display(a);
    display(" , ");
    display(b);
    display("]\n");
    display("Total number of iterations=");
    display(total__iterations);
    newline();
    display("xmin=\t\t");
    display(xmin);
    newline();
    display("f(xmin)=\t");
    display(fun(xmin));
    newline();
    std::cin.get();
    return 0;
}