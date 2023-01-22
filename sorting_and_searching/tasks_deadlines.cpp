#include <bits/stdc++.h>

using namespace std;

bool sortConditions(const tuple<long long int, long long int>& a, const tuple<long long int, long long int>& b)
{
    if(get<0>(a) == get<0>(b))
        return (get<1>(a) > get<1>(b));
    return (get<0>(a) < get<0>(b));
}

int main()
{
    long long int n, temp1, temp2, ans = 0;
    vector<tuple<long long int, long long int>> tasks;
    cin >> n;
    for(long long int i = 0; i < n; i++)
    {
        cin >> temp1 >> temp2;
        tasks.push_back(make_tuple(temp1, temp2));
    }
    sort(tasks.begin(), tasks.end(), sortConditions);
    for(long long int i = 0; i < n; i++)
    {
        ans += (get<1>(tasks[i]) - ((n-i)*(get<0>(tasks[i]))));
    }
    cout << ans << "\n";
    return 0;
}