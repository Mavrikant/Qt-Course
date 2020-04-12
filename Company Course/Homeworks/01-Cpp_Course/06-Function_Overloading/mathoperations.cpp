#include "mathoperations.h"

MathOperations::MathOperations()
{

}

float MathOperations::absolute(float f)
{
    if (f < 0) {
        f = -f;
    }
    return f;
}

int MathOperations::absolute(int i)
{
    if (i < 0) {
        i = -i;
    }
    return i;
}

int MathOperations::sum(int i1, int i2)
{
    return i1 + i2;
}

double MathOperations::sum(double d1, double d2)
{
    return d1 + d2;
}
