#include <bits/stdc++.h>
 
using namespace std;

vector<long long int> values, og;

long long int find_lower(long long int x)
{
    long long int l = 0, r = values.size()-1, m;
    while(l <= r)
    {
        m = ((r-l)/2) + l;
        if(values[m] > x)
            r = m-1;
        else if(values[m] <= x)
        {
            if(values[m+1] > x)
                return m;
            l = m+1;
        }
    }
    l = values.size() - 1;
    return l;
}

long long int find_upper(long long int x)
{
    long long int l = 0, r = values.size()-1, m;
    while(l <= r)
    {
        m = ((r-l)/2) + l;
        if(values[m] < x)
            l = m+1;
        else if(values[m] >= x)
        {
            if((values[m-1] < x) || (m == 0))
                return m;
            r = m-1;
        }
    }
    return -1;
}

int main()
{
    long long int n, lower, upper, temp, sum, v1, v2, cnt = 0;
    bool found = false;
    cin >> n >> sum;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        og.push_back(temp);
        values.push_back(temp);
    }
    sort(values.begin(), values.end());
    temp = sum/2;
    lower = find_lower(temp);
    upper = find_upper(temp);
    if(upper < 0)
    {
        upper = n - 1;
        lower--;
    }
    if(upper == lower)
        upper++;
    while(lower >= 0 && upper < n && upper != lower)
    {
        if((values[lower] + values[upper]) == sum)
        {
            v1 = values[lower];
            v2 = values[upper];
            found = true;
            break;
        }
        else if((values[lower] + values[upper]) < sum)
            upper++;
        else
            lower--;
    }
    if(!found)
        cout << "IMPOSSIBLE";
    else
    {
        for(long long int i = 0; i < og.size(); i++)
        {
            if(og[i] == v1 || og[i] == v2)
            {
                cnt++;
                cout << i+1 << " ";
            }
            if(cnt == 2)
                break;
        }
    }
    cout << "\n";
    return 0;
}