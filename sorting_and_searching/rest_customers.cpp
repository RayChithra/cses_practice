#include <bits/stdc++.h>

using namespace std;

long long int check_max(long long int ctr, long long int max)
{
    if(ctr > max)
        return ctr;
    return max;
}

int main()
{
    long long int n, ctr = 0, max = -1, temp1, temp2;
    vector<pair<long long int, long long int>> times;
    cin >> n;
    for(long long int i = 0; i < n; i++)
    {
        cin >> temp1 >> temp2;
        times.push_back(make_pair(temp1, 1));
        times.push_back(make_pair(temp2, 0));
    }
    sort(times.begin(), times.end());
    for( auto i : times)
    {
        if(i.second == 1)
            ctr++;
        else
            ctr--;
        max = check_max(ctr, max);
    }
    cout << max << "\n";
    return 0;
}