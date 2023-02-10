// We have populated the solutions for the 10 easiest problems for your support.
// Click on the SUBMIT button to make a submission to this problem.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    
    if(n==0 || k ==0)
        return 0;
    
    vector<int> arr;
    int count=0;
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]%k==0)
        {
            count+=1;
        }
    }
    return count;
}
