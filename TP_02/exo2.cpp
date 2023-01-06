#include<iostream>
using namespace std;
template <typename T>

T powiter(T a, int n) 
{
    T power = 1;
    while (n > 0)
    {
        if (n % 2 == 1) 
        {
            power *= a;
        }
        a *= a;
        n /= 2;
    }
    return power;
}

template<typename T>
T powerec(T a, int n) {
  if (n == 0) return 1;
  T half = powerec(a, n / 2);
  if (n % 2 == 0) return half * half;
  else return a * half * half;
}



int main()
{
    cout << powiter(2,3) << '\n';
    cout << powiter(1.2,3) <<'\n';
    cout << powerec(2,3) <<'\n';
    cout << powerec(1.2,3) <<'\n';
    
}