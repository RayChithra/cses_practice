#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
    int n;
    long long int arr[20], sum_a, sum_b, best = LLONG_MAX;
    cin >> n;
    for( int i = 0; i < n; i++)
        cin >> arr[i];
    for( int i = 0; i < (1 << n); i++)
    {
        sum_a = 0;
        sum_b = 0;
        for( int j = 0; j < n; j++)
        {
            if(i & (1 << j))
                sum_a += arr[j];
            else
                sum_b += arr[j];
        }
        best = min(best, max((sum_a - sum_b), (sum_b - sum_a)));
    }
    cout << best << "\n";
    return 0;
}