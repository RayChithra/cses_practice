#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, reqdSum, input1;
    vector<long long int> arr;
    multimap<long long int, tuple<long long int, long long int>> sums;
    cin >> n >> reqdSum;
    for(long long int i = 0; i < n; i++)
    {
        cin >> input1;
        arr.push_back(input1);
    }
    for(long long int i = 0; i < n-1; i++)
    {
        for(long long int j = i+1; j < n; j++)
        {
            long long int currSum = arr[i] + arr[j];
            sums.insert(pair<long long int, tuple<long long int, long long int>>(currSum, make_tuple((i),(j))));
        }
    }
    for(long long int i = 0; i < n-1; i++)
    {
        for(long long int j = i+1; j < n; j++)
        {
            long long int minorSum = reqdSum - (arr[i] + arr[j]);
            auto itr = sums.equal_range(minorSum);
            if(itr.first == sums.end())
                continue;
            else
            {
                for(auto itr2 = itr.first; itr2 != itr.second; itr2++)
                {
                    tuple<long long int, long long int> k;
                    k = itr2->second;
                    if((i != get<0>(k)) && (i != get<1>(k)) && (j != get<0>(k)) && (j != get<1>(k)))
                    {
                        cout << i+1 << " " << j+1 << " " << get<0>(k)+1 << " " << get<1>(k)+1 << "\n";
                        exit(0);
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return(0);
}