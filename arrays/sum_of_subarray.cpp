//Find the  sum of all subarrays in an array
/* e.g-> arr=[1,2,2]
subarrays-> [1],[1,2],[1,2,2] (wiht index as 0)
->[2],[2,2](with index 1)
->[2] with index 2  */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n]; 

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            cout<<sum<<" ";
        }
                
    }
}