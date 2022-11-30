#include <iostream>

using namespace std;

int main()
{
    long long int n, arr[200000], ans, temp;
    ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 1;i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            temp = (arr[i - 1] - arr[i]);
            arr[i] += temp;
            ans += temp;
        }
    }
    cout << ans << "\n"; 
    return 0;
}