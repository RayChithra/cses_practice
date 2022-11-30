#include <bits/stdc++.h>

using namespace std;

#define ll long long int

bool sortbyfif(const tuple<ll, ll, ll, ll, ll>& a, const tuple<ll, ll, ll, ll, ll>& b)
{
    return (get<4>(a) < get<4>(b));
}

bool check_intersection(ll c_x_1, ll c_y_1, ll r1, ll c_x_2, ll c_y_2, ll r2)
{
    double d1, d2;
    d1 = sqrt(pow(((double)c_x_1 - (double)c_x_2), 2) - pow(((double)c_y_1 - (double)c_y_2), 2));
    d2 = r1 + r2;
    if(d1 <= d2)
        return true;
    return false;
}

int main()
{
    vector<tuple<ll, ll, ll, ll, ll>> circles;
    ll n, fin_end = -1, c_x, c_y, r, ctr = 0;
    cin >> n;
    for(ll i = 0; i < n; i++)
    {
        cin >> c_x >> c_y >> r;
        circles.push_back(make_tuple(c_x, c_y, r, r - c_x, r + c_x));
    }
    sort(circles.begin(), circles.end(), sortbyfif);
    for(ll i = 0; i < circles.size(); i++)
    {
        if(get<3>(circles[i]) >= fin_end)
        {
            fin_end = get<4>(circles[i]);
            ctr++;
        }
        else
        {
            if(!check_intersection(get<0>(circles[i-1]), get<1>(circles[i-1]), get<2>(circles[i-1]), get<0>(circles[i]), get<1>(circles[i]), get<2>(circles[i])))
            {
                fin_end = get<4>(circles[i]);
                ctr++;
            }
        }
    }
    cout << n - ctr << "\n";
    return 0;
}