#include <bits/stdc++.h>

using namespace std;

multiset<long long int> ticket_price;

long long int* find_lower(long long int x)
{

}

int main()
{
    long long int ticket_no, customer_no, temp;
    ticket_price.clear();
    cin >> ticket_no >> customer_no;
    ticket_price.insert(-1);
    for(int i = 0; i < ticket_no; i++)
    {
        cin >> temp;
        ticket_price.insert(temp);
    }
    cout << "\n";
    for(int i = 0; i < customer_no; i++)
    {
        for( auto j : ticket_price)
            cout << j << " ";
        cout << "\n";
        cin >> temp;
        auto lower = ticket_price.lower_bound(temp);
        if((temp != *(lower)) && (lower != ticket_price.begin()))
            lower--;
        cout << *(lower) << "\n";
        if(*(lower) != -1)
            ticket_price.erase(lower);
    }
    return 0;
}