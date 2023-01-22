#include <bits/stdc++.h>

using namespace std;

bool sortConditions(const tuple<long long int, long long int> a, const tuple<long long int, long long int> b)
{
    return (get<0>(a) < get<0>(b));
}

int main()
{
    long long int n, reqdSum, input1;
    vector<tuple<long long int, long long int>> arr;
    cin >> n >> reqdSum;
    for(long long int i = 0; i < n; i++)
    {
        cin >> input1;
        arr.push_back(make_tuple(input1, i+1));
    }
    
    sort(arr.begin(), arr.end(), sortConditions);
    
    long long int currSum = 0;
    for(long long int i = 0; i < n; i++)
    {
        for(long long int j = i+1, k = n-1; j < k; j++)
        {
            currSum = (get<0>(arr[i]) + get<0>(arr[j]) + get<0>(arr[k]));
            while(currSum > reqdSum)
            {
                k--;
                currSum = (get<0>(arr[i]) + get<0>(arr[j]) + get<0>(arr[k]));
            }
            if((currSum == reqdSum) && (j < k))
            {
                cout << get<1>(arr[i]) << " " << get<1>(arr[j]) << " " << get<1>(arr[k]) << "\n";
                exit(0);
            }
        }
    }    
    cout << "IMPOSSIBLE\n";
    return(0);
}