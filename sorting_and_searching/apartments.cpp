#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int apartment_no, applicant_no , flexibility, applicant_size[200000], apartment_size[200000], ctr = 0;
    cin >> applicant_no >> apartment_no >> flexibility;
    for(int i = 0; i < applicant_no; i++)
        cin >> applicant_size[i];
    for(int i = 0; i < apartment_no; i++)
        cin >> apartment_size[i];
    sort(applicant_size, applicant_size+applicant_no);
    sort(apartment_size, apartment_size+apartment_no);
    for(long long int i = 0, j = 0; (i < applicant_no) && (j < apartment_no); )
    {
        if((applicant_size[i] - flexibility) > apartment_size[j])
            j++;
        else if(((applicant_size[i] - flexibility) <= apartment_size[j]) && ((applicant_size[i] + flexibility) >= apartment_size[j]))
        {
            ctr++;
            i++;
            j++;
        }
        else if((applicant_size[i] + flexibility) < apartment_size[j])
            i++; 
    }
    cout << ctr << "\n";
    return 0;
}