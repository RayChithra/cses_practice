#include <bits/stdc++.h>

using namespace std;

long long int check_max(long long int max_len, long long int curr_len)
{
    if(max_len > curr_len)
        return max_len;
    return curr_len;
}

long long int n;

int main()
{
    long long int max_len = -1, curr_len, beg = 0, arr[200001];
    map<long long int, long long int> playlist;
    cin >> n;
    for(long long int i = 0; i < n; i++)
        cin >> arr[i];
    for(long long int end = 0; end < n; end++)
    {
        auto loc = playlist.find(arr[end]);
        if((loc == playlist.end()) || (playlist[arr[end]] < beg))
            playlist[arr[end]] = end;
        else
        {
            beg = playlist[arr[end]] + 1;
            playlist[arr[end]] = end;
        }
        curr_len = end - beg + 1;
        max_len = check_max(max_len, curr_len);
    }
    cout << max_len << "\n";
    return 0;
}