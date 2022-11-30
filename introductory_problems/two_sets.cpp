#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long int n;
    cin >> n;
    if((n % 4 != 0) && (n%4 != 3))
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        if(n % 4 == 3)
        {
            cout << (n/2) + 1 << "\n";
            for(int i = 1; i <= (n/2); i+=2)
                cout << i << " " << (n - i) <<" ";
            cout << "\n" << n/2 << "\n" << n << " ";
            for(int i = 2; i <= (n/2); i+=2)
                cout << i << " " << (n - i) << " ";
            cout << "\n";
        }
        if(n % 4 == 0)
        {
            cout << n/2 << "\n";
            for(int i = 1; i <= (n/2); i+=2)
                cout << i << " " << (n - i + 1) <<" ";
            cout << "\n" << (n/2) << "\n";
            for(int i = 2; i <= (n/2); i+=2)
                cout << i << " " << (n - i + 1) << " ";
            cout << "\n";
        }
    }
    return 0;
}