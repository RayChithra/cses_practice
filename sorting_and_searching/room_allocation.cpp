#include <bits/stdc++.h>

using namespace std;

bool sortConditions(const tuple<long long int, long long int, long long int> a, const tuple<long long int, long long int, long long int> b)
{
    if(get<0>(a) == get<0>(b))
        return (get<1>(a) < get<1>(b));
    return get<0>(a) < get<0>(b);
}

bool isGreater(long long int exitTime, const tuple<long long int, long long int> setBegin)
{
    return (exitTime > get<0>(setBegin));
}

int main()
{
    vector<tuple<long long int, long long int, long long int>> customerRanges;
    set<tuple<long long int, long long int>> roomsFree;
    long long int numberCustomers, arrivalTime, exitTime, numberRooms = 1, roomAllocation[200001], maxExit = LLONG_MIN;
    roomsFree.insert(make_tuple(maxExit, numberRooms));
    cin >> numberCustomers;
    for(long long int i = 0; i < numberCustomers; i++)
    {
        cin >> arrivalTime >> exitTime;
        customerRanges.push_back(make_tuple(arrivalTime, exitTime, i));
    }
    sort(customerRanges.begin(), customerRanges.end(), sortConditions);
    for(long long int i = 0; i < numberCustomers; i++)
    {
        auto setBegin = *(roomsFree.begin());
        long long int currentexitTime = get<0>(customerRanges[i]);
        if(!isGreater(currentexitTime, setBegin))
        {
            numberRooms++;
            long long int newexitTime = get<1>(customerRanges[i]), customerNo = get<2>(customerRanges[i]);
            roomAllocation[customerNo] = numberRooms;
            roomsFree.insert(make_tuple(newexitTime, numberRooms));
        }
        else
        {
            auto setBegin = *(roomsFree.begin());
            auto iteratorsetBegin = roomsFree.begin();
            roomsFree.erase(iteratorsetBegin);
            long long int freeRoom = get<1>(setBegin);
            long long int newexitTime = get<1>(customerRanges[i]), customerNo = get<2>(customerRanges[i]);
            roomAllocation[customerNo] = freeRoom;
            roomsFree.insert(make_tuple(newexitTime, freeRoom));
        }
    }
    cout << numberRooms << "\n";
    for(long long int i = 0; i < numberCustomers; i++)
        cout << roomAllocation[i] << " ";
    cout << "\n";
    return 0;
} 