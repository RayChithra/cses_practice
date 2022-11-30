#include <iostream>

using namespace std;

int main()
{
    long long int t, a, b, max, min;
    cin >> t;
    for( long long int k = 0; k < t; k++)
    {
        cin >> a >> b;
        if(((a + b) % 3) != 0)
            cout << "NO\n";
        else
        {
            if(a <= b)
            {
                min = a;
                max = b;
            }
            else
            {
                min = b;
                max = a;
            }
            if(max > 2*min)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
    return 0;
}