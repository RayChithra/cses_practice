#include <bits/stdc++.h> // qn uses Kadane's algorithm

using namespace std;

int main()
{
    long long int n, arr[200001], past = 0, ans = LLONG_MIN;
    cin >> n;
    for(long long int i = 0; i < n; i++)
        cin >> arr[i];
    for(long long int i = 0; i < n; i++)
    {
        if((arr[i] + past) > arr[i])
            past += arr[i];
        else
            past = arr[i];
        ans = max(past, ans);
    }
    cout << ans << "\n";
    return 0;
}