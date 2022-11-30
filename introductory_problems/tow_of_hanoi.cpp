#include <iostream>

using namespace std;

long long int fast_exp(long long int pow)
{
    long long int ans = 1, base = 2;
    while(pow > 0)
    {
        if(pow %2 == 1)
            ans *= base;
        base *= base;
        pow /= 2;
    }
    return ans;
}

void print_hanoi(long long int n, int beg, int mid, int end)
{
    if(n == 1)
        cout << beg << " " << end << "\n";
    else
    {
        print_hanoi(n -1, beg, end, mid);
        print_hanoi(1, beg, mid, end);
        print_hanoi(n - 1, mid, beg, end);
    }
}

int main()
{
    long long int n, ans;
    cin >> n;
    ans = fast_exp(n) - 1;
    cout << ans << "\n";
    print_hanoi(n, 1, 2, 3);
    return 0;
}