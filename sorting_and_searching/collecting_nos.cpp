#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int arr[200001], n, ans = 1, pos[200001];
    cin >> n;
    for(long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    for(long long int i = 1; i <= n; i++)
        cout << pos[i] << " ";
    cout << "\n";
    for(long long int i = 1; i < n; i++)
    {
        if(pos[i+1] < pos[i])
            ans++;
    }
    cout << ans << "\n";
    return 0;
}