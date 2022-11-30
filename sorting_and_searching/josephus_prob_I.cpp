#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<int> numbers, survivors;
    cin >> n;
    for(int i = 1; i <= n; i++)
        numbers.push_back(i);
    while(numbers.size() > 1)
    {
        survivors.clear();
        for(int i = 0; i < numbers.size(); i++)
        {
            if(i % 2 == 1)
                cout << numbers[i] << " ";
            else
                survivors.push_back(numbers[i]);
        }
        if(numbers.size() % 2 == 1)
        {
            survivors.insert(survivors.begin(), survivors.back());
            survivors.pop_back();
        }
        numbers = survivors;
    }
    cout << numbers[0] << "\n";
    return 0;
}