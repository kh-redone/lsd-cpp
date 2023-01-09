#include <iostream>
#include <vector>

using namespace std;



template<typename T>
vector<vector<T>> matrix_multiplication(vector<vector<T>> a, vector<vector<T>> b)
{
    vector<vector<T>> s(a.size(), vector<T>(b[0].size()));
    for ( int i=0; i< a.size(); i++)
    {
        for ( int j=0; j< b[0].size() ; j++)
        {
            for ( int k=0; k< a[0].size(); k++)
            {
                s[i][j]+=a[i][k] * b[k][j];
            }
        }
    }
    return s;
}

template<typename T>
void print_matrix(vector<vector<T>> a)
{
    for (vector<T> row : a)
    {
        for (T element : row)
        {
            cout << element << ' ';
        }
        cout << '\n';
    }
}


template <typename T>
vector<vector<T>> matpow(vector<vector<T>> a, int k)
{
    vector<vector<T>> power(a.size(), vector<T>(a.size()));
    for (int i = 0; i < a.size(); i++)
    {
        power[i][i] = 1;
    }

    vector<vector<T>> aux(a);
    while (k > 0)
    {
        if (k % 2 == 1)
        {
            power = matrix_multiplication(power, aux);
        }

        aux = matrix_multiplication(aux, aux);
        k=k/2;
    }

    return power;
}

template <typename T>
vector<vector<T>> matpownaive(vector<vector<T>> a, int k)
{
    vector<vector<T>> power(a.size(), vector<T>(a.size()));
    for (int i = 0; i < a.size(); ++i)
    {
        power[i][i] = 1;
    }
    
    for (int i=0;i<k;i++)
    {
        power = matrix_multiplication(power, a);
    }
    
    return power;
}






int main()
{
    vector<vector<int>> a{{1, 1}, {1, 1}};
    print_matrix(matpownaive(a,4));
    print_matrix(matpow(a,2));
    
    
    return 0;
}