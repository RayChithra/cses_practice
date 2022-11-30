#include <iostream>

using namespace std;

int main()
{
    long long int n, cnt5, temp;
    cin >> n;
    cnt5 = 0;
    temp = 5;
    while(temp <= n)
    {
        cnt5 += (n/temp);
        temp *= 5;
    }
    cout << cnt5 << "\n";
}