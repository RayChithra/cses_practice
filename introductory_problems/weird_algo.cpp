#include<stdio.h>
#include<iostream>

using namespace std;

void weird_algo(long long int n)
{
    while(n != 1)
    {
        if ((n % 2) == 0)
            n /= 2;
        else
            n = (n*3) + 1;
        cout << n << " ";
    }
}

int main()
{
    long long int n;
    cin >> n;
    cout<< n << " ";
    if (n != 1)
        weird_algo(n);
    cout<< "\n";
    return 0;
}