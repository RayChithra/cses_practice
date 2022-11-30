#include <bits/stdc++.h>

using namespace std;

bool sortbysec(const tuple<long long int, long long int>& a, const tuple<long long int, long long int>& b)
{
    return (get<1>(a) < get<1>(b));
}

int main()
{
    vector<tuple<long long int, long long int>> times;
    long long int n, temp1, temp2, fin_end_time = -1, ctr = 0;
    cin >> n;
    for(long long int i = 0;i < n; i++)
    {
        cin >> temp1 >> temp2;
        times.push_back(make_tuple(temp1, temp2));
    }
    sort(times.begin(), times.end(), sortbysec);
    for(long long int i = 0; i < times.size(); i++)
    {
        if(get<0>(times[i]) >= fin_end_time)
        {
            fin_end_time = get<1>(times[i]);
            ctr++;
        }
    }
    cout << ctr << "\n";
    return 0;
}