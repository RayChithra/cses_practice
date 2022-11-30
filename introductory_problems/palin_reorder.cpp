# include <iostream>
#include <string>

using namespace std;

#define a 65

int main()
{
    string str;
    char temp, arr[1000001];
    int len, hash[26], cnt1, len_ctr;
    cnt1 = 0;
    len_ctr = 0;
    for(int i = 0; i< 26; i++)
        hash[i] = 0;
    getline(cin, str);
    len = str.length();
    for(int i = 0;i < len; i++)
    {
        temp = str.at(i);
        int index;
        index = (int)temp - a;
        hash[index]++;
    }
    for(int i = 0; i < 26; i++)
        if((hash[i] %2) != 0)
            cnt1++;
    if((cnt1 != 1) && (cnt1 != 0))
        cout << "NO SOLUTION\n";
    else
    {
        for(int j = 0; j < 26; j++)
        {
            temp = 65 + j;
            if((hash[j] % 2) == 1)
            {
                arr[(len/2)]  = temp;
                hash[j]--;
            }
            while(hash[j] != 0)
            {
                arr[len_ctr] = temp;
                arr[len - len_ctr - 1] = temp;
                len_ctr++;
                hash[j] -= 2;
            }
        }
    }
    arr[len] = '\0';
    for(int i = 0; i < len; i++)
        cout << arr[i];
    cout << "\n";
    return 0;
}