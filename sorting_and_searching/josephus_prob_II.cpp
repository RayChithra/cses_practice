#include <bits/stdc++.h>

using namespace std;

vector<long long int> children;

int main()
{
    long long int n , k, start = 0, size, edit_index;
    cin >> n >> k;
    for(long long int  i = 1; i <= n; i++)
        children.push_back(i);
    while(children.size() > 0)
    {
        size = children.size();
        edit_index = (start + k) % size;
        cout << children[edit_index] << " ";
        children.erase(children.begin() + edit_index);
        start = edit_index;
    }
    cout << "\n";
}