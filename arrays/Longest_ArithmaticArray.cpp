
#include<bits/stdc++.h>
using namespace std;

//Sample test case-> 10,7,4,6,8,10,11
//ans = 4 (4,6,8,10)
int main()
{
    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int pd_count=2;
    int pd=a[0]-a[1];
    int cd;
    int cd_count=2;

    for(int i=0;i<n;i++)
    {
        cd=a[i]-a[i+1];
        if((pd==cd) && (cd_count>=pd_count))//WHen it follows an AP and it has breaked the previous record
        {
            cd_count++;
            pd_count=cd_count;
        }
        else if((pd==cd) && (cd_count<pd_count))//When it follows the AP but not broken the prev record
        {
            cd_count++;
        }
    }

        
        cout<<"The longest subarray length with AP is :"<<pd_count;


}