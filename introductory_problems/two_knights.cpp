#include <iostream>

using namespace std;

int main()
{
    long long int n, ans;
    cin >> n;
    for(long long int k = 1; k <= n; k++)
    {
        if(k == 1)
            cout << "0\n";
        else if(k == 2)
            cout << "6\n";
        else
        {
            ans = (((k*k*k*k) - (k*k))/2) - ((4*k*k) - 12*k + 8);
            cout << ans << "\n";
        }
    }
    return 0;
}