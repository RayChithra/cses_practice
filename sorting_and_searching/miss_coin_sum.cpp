#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, arr[200001], ans = 1;
    cin >> n;
    for(long long int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    for(long long int i = 0; i < n; i++)
    {
        if(ans < arr[i])
            break;
        else
            ans += arr[i];
    }
    cout << ans << "\n";
}