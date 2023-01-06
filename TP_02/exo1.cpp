#include<iostream>

template <typename T>

T multiply(T x,int y)
{
    T result = T(x*y);
    return result;
}
int main ( )
{
    std::cout << multiply (5,3) <<  '\n' ;
    std::cout << multiply (2.,4) << '\n';
    return 0 ;
}
