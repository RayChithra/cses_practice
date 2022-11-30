#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    int len, ans;
    getline(cin, str);
    len = (int)str.length();
    vector<string> perms;
    sort(str.begin(), str.end());
    perms.push_back(str);
    while(next_permutation(str.begin(), str.end()))
        perms.push_back(str);
    ans = perms.size();
    cout << ans << "\n";
    for( string perm : perms)
        cout << perm << "\n";
    return 0;
}