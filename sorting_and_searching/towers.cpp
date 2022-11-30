#include <bits/stdc++.h>

using namespace std;

vector<long long int> towers;
long long int n;

long long int find_upper(long long int x)
{
    long long int l = 0, r = towers.size() - 1, m;
    
    if(towers.size() == 0)
        return -1;
    
    while(l <= r)
    {
        m = (r - l)/2 + l;
        if(towers[m] <= x)
            l = m+1;
        else
        {
            if((towers[m-1] <= x) || (m == 0))
                return m;
            else
                r = m-1;
        }
    }
    return -1;
}

int main()
{
    long long int temp, index;
    cin >> n;
    for(long long int i = 0; i < n; i++)
    {
        cin >> temp;
        index = find_upper(temp);
        if(index == -1)
            towers.push_back(temp);
        else
            towers[index] = temp;
    }
    cout << towers.size() << "\n";
    return 0;
}