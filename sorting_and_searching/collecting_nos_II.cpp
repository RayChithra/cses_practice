#include <bits/stdc++.h>

using namespace std;

long long int arr[200001], n, pos[200001];

void switch_positions(long long int pos1, long long int pos2)
{
    long long int temp;
    temp = pos[arr[pos1]];
    pos[arr[pos1]] = pos[arr[pos2]];
    pos[arr[pos2]] = temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

long long int find_rounds()
{
    long long int ans = 1;
    for(long long int i = 1; i < n; i++)
        {
            if(pos[i+1] < pos[i])
                ans++;
        }
    return ans;
}

long long int decr_ans(long long int pos1, long long int pos2, long long int curr_ans)
{
    long long int i = arr[pos1], j = arr[pos2];
    // checking for i
    if((pos[i] < pos[i-1]) && (i != 1))
        curr_ans--;
    if((pos[i+1] < pos[i]) && (i != n))
        curr_ans--;
    // checking for j
    if((pos[j] < pos[j-1]) && (i != j-1) && (j != 1))
        curr_ans--;
    if((pos[j+1] < pos[j]) && (i != j+1) && (j != n))
        curr_ans--;
    return curr_ans;
}

long long int incr_ans(long long int pos1, long long int pos2, long long int curr_ans)
{
    long long int i = arr[pos1], j = arr[pos2];
    // checking for i
    if((pos[i] < pos[i-1]) && (i != 1))
        curr_ans++;
    if((pos[i+1] < pos[i]) && (i != n))
        curr_ans++;
    // checking for j
    if((pos[j] < pos[j-1]) && (i != j-1) && (j != 1))
        curr_ans++;
    if((pos[j+1] < pos[j]) && (i != j+1) && (j != n))
        curr_ans++;
    return curr_ans;
}

int main()
{
    long long int m, pos1, pos2, ans, new_ans;
    cin >> n >> m;
    for(long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    ans = find_rounds();
    new_ans = ans;
    for(long long int i = 0; i < m; i++)
    {
        cin >> pos1 >> pos2;
        pos1--;
        pos2--;
        new_ans = decr_ans(pos1, pos2, new_ans);
        switch_positions(pos1, pos2);
        new_ans = incr_ans(pos1, pos2, new_ans);
        cout << new_ans << "\n";
    }
    return 0;
}