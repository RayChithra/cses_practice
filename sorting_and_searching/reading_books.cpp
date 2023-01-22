#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, input, totalSum = 0, oneBigger;
    vector<long long int> readingTimes;
    cin >> n;
    for(long long int i = 0; i < n; i++)
    {
        cin >> input;
        readingTimes.push_back(input);
        totalSum += input;
    }
    sort(readingTimes.begin(), readingTimes.end(), greater<long long int>());
    oneBigger = 2*readingTimes[0];
    cout << max(totalSum, oneBigger) << "\n";
    return(0);
}