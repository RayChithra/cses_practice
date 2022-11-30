#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    string str;
    long long int ctr, max, len;
    ctr = 1;
    max = -1;
    getline(cin, str);
    len = str.length();
    for( int i = 1; i < len; i++)
    {
        if(str[i] == str[i - 1])
            ctr++;
        else
        {
            if(ctr > max)
                max = ctr;
            ctr = 1;
        }
    }
    if(ctr > max)
        max = ctr;
    cout << max << "\n";
    return 0;
}