#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<long long int> machineTimes;
    long long int numberMachines, reqdProducts, temp, comparison = 1e9;
    cin >> numberMachines >> reqdProducts;
    for(long long int i = 0; i < numberMachines; i++)
    {
        cin >> temp;
        machineTimes.push_back(temp);
    }
    long long int begTime = 0, endTime = 1e18, ans = 1e18, midTime, productsFinished;
    while(begTime <= endTime)
    {
        midTime = ((endTime - begTime)/2) + begTime;
        productsFinished = 0;
        for(long long int i = 0; i < numberMachines; i++)
            productsFinished += min(midTime/machineTimes[i], comparison);
        if(productsFinished >= reqdProducts)
        {
            if(ans > midTime)
                ans = midTime;
            endTime = midTime - 1;
        }
        else
            begTime = midTime + 1;
    }
    cout << ans << "\n";
    return 0;
}