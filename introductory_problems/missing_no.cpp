#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, arr[200001], ans;
    cin >> n;
    for(int i = 0; i < (n - 1); i++)
        cin >> arr[i];
    sort(arr, arr + n - 1);
    for(int i = 0; i < (n - 1); i++)
    {
        if(arr[i] != (i + 1))
        {
            ans = i + 1;
            break;
        }
        ans = n;
    }
    cout << ans <<"\n";
    return 0;
}