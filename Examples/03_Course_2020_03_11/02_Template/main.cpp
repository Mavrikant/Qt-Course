#include <iostream>
#include <iomanip>
#include <limits>
template <class T, class U>
U sum (T a, T b){
    return static_cast<U>(a) + static_cast<U>(b);
}

int main()
{
    std::cout.precision(2);

    std::cout << std::scientific << sum<int,int>(1.1, 2.2) << std::endl;
    std::cout << std::scientific << sum<int,double>(1.1, 2.2) << std::endl;
    std::cout << std::scientific << sum<double,int>(1.1, 2.2) << std::endl;
    std::cout << std::scientific << sum<double,double>(1.1, 2.2) << std::endl;


    return 0;
}
