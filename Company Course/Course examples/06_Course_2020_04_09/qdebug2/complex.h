#ifndef COMPLEX_H
#define COMPLEX_H
#include <QDebug>

class Complex
{
public:
    Complex(double r=0, double i=0);
    Complex operator+ (Complex const &obj);
    Complex operator- (Complex const &obj);
    bool operator< (Complex const &obj);
    Complex operator+ (double In );
    Complex operator- (double In );

    friend QDebug operator<<( QDebug qdebug, const Complex & Complex);

    void print();

private:
    double real;
    double imag;
};

#endif // COMPLEX_H
