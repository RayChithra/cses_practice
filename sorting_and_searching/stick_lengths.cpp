#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, arr[200001], ans = 0, mid;
    cin >> n;
    mid = n/2;
    for(long long int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    for(long long int i = 0; i < n; i++)
        ans += max((arr[i] - arr[mid]), (arr[mid] - arr[i]));
    cout << ans << "\n";
    return 0;
}