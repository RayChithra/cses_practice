#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, x, weights[200001], ctr = 0;
    cin >> n >> x;
    for( int i = 0; i < n; i++)
        cin >> weights[i];
    sort(weights, weights+n);
    for(int i = 0, j = (n-1); i <= j; )
    {
        if(i == j)
        {
            ctr++;
            break;
        }
        else if((weights[i] + weights[j]) <= x)
        {
            ctr++;
            i++;
            j--;
        }
        else
        {
            ctr++;
            j--;
        }
    }
    cout << ctr << "\n";
    return 0;
}