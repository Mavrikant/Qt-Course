#ifndef CALCULATOR_H
#define CALCULATOR_H

template <typename T>
class Calculator
{
public:
    Calculator(){}
    static T sum(T a1,T a2){return a1+a2;}
    static T sub(T a1,T a2){return a1-a2;}
    static T mul(T a1,T a2){return a1*a2;}
    static T div(T a1,T a2){return a1/a2;}
};

#endif // CALCULATOR_H
