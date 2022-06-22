#include <iostream>
#include <cmath>

using namespace std;

typedef double(*FUNC)(double);


double line(double x) {
    return x;
}

double square(double x) {
    return x * x;
}

double cube(double x) {
    return x * x * x;
}
double integrate(double (*f)(double), double a, double b) {
    double sum = 0;
    double delta = .0001;
    double x = a;
    while (x < b) {
        sum += delta * f(x);
        x += delta;
    }
    return sum;
}

int main() {
    cout << "The integral of f(x)=x between 0 and 1 is: " << integrate(line, 0, 1) << endl;     // .5
    cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 0, 5) << endl; // 41.6654
    cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   // 155.994
   // lambda function anonmous functions 
    cout << integrate([](double x) {return (x * x + 1); }, 4, 5) << endl;     // 21.3355
}
