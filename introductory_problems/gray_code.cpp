#include <iostream>
#include <vector>

using namespace std;

vector<string> get_ans(long long int n)
{
    vector<string> final, temp;
    if(n == 1)
    {
        final.push_back("0");
        final.push_back("1");
        return final;
    }
    temp = get_ans(n - 1);
    for(int i = 0; i < (int)temp.size(); i++)
    {
        string str;
        str += '0';
        str += temp[i];
        final.push_back(str);
    }
    for(int i = ((int)temp.size() - 1); i >=0; i--)
    {
        string str;
        str += '1';
        str += temp[i];
        final.push_back(str);
    }
    return final;
}

int main()
{
    long long int n, line_no;
    cin >> n;
    vector<string> ans;
    ans = get_ans(n);
    for(string i : ans)
        cout << i << "\n";
    return 0;
}