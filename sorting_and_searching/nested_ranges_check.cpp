#include <bits/stdc++.h>

using namespace std;

bool sort_conditions(const tuple<long long int, long long int, long long int>& a, const tuple<long long int, long long int, long long int>& b)
{
    if(get<0>(a) == get<0>(b))
        return (get<1>(a) > get<1>(b));
    return (get<0>(a) < get<0>(b));
}

int main()
{
    vector<tuple<long long int, long long int, long long int>> ranges;
    long long int n, beg, end, max_bound = 0, min_bound = LLONG_MAX;
    bool contained[200001] = {false}, contains[200001] = {false};
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> beg >> end;
        ranges.push_back(make_tuple(beg, end, i));
    }
    sort(ranges.begin(), ranges.end(), sort_conditions);
    for(int i = 0; i < n; i++)
    {
        if(get<1>(ranges[i]) <= max_bound)
            contained[get<2>(ranges[i])] = true;
        else
            max_bound = get<1>(ranges[i]);
    }
    for(int i = n-1; i >= 0; i--)
    {
        if(get<1>(ranges[i]) >= min_bound)
            contains[get<2>(ranges[i])] = true;
        else
            min_bound = get<1>(ranges[i]);
    }
    for(int i = 0; i < n; i++)
        cout << contains[i] << " ";
    cout << "\n";
    for(int i = 0; i < n; i++)
        cout << contained[i] << " ";
    cout << "\n";
    return 0;
}