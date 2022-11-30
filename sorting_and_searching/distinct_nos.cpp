#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, arr[1000000], x, ctr = 1;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    x = arr[0];
    while((upper_bound(arr, arr+n, x) - arr) <= (n-1))
    {
        x = arr[(upper_bound(arr, arr+n, x) - arr)];
        ctr++;
    }
    cout << ctr << "\n";
    return 0;
}