#include <bits/stdc++.h>

using namespace std;

bool sort_conditions(const tuple<long long int, long long int, long long int> a, const tuple<long long int, long long int, long long int> b)
{
    if(get<0>(a) == get<0>(b))
        return (get<1>(a) < get<1>(b));
    return get<0>(a) < get<0>(b);
}

int main()
{
    
    return 0;
} 