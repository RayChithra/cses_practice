#include <iostream>

using namespace std;

long long int fast_exp(long long int pow, long long int mod)
{
    long long int ans, base;
    ans = 1;
    base = 2;
    if(base == 0)
        return 0;
    while(pow > 0)
    {
        if(pow & 1)
            ans = ((ans % mod) * (base % mod)) % mod;
        pow /= 2;
        base = ((base % mod) * (base % mod)) % mod;
    }
    return ans;
}

int main()
{
    long long int n, mod, ans;
    cin >> n;
    mod = 1000000007;
    ans = fast_exp(n, mod);
    cout << ans <<"\n";
    return 0;
}