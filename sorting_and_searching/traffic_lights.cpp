#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<long long int> points;
    multiset<long long int> lengths;
    long long int x, n, light_pos, prev_pos, next_pos;
    points.insert(0);
    cin >> x >> n;
    points.insert(x);
    lengths.insert(x);
    for(long long int i = 0; i < n; i++)
    {
        cin >> light_pos;
        points.insert(light_pos);
        auto itr = points.find(light_pos);
        prev_pos = *(prev(itr));
        next_pos = *(next(itr));
        lengths.erase(lengths.find(next_pos - prev_pos));
        lengths.insert(light_pos - prev_pos);
        lengths.insert(next_pos - light_pos);
        cout << *(lengths.rbegin()) << "\n";
    }
    return 0;
}