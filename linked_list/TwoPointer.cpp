#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the length of array:";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    //DONT FORGET TO SORT THE ARRAY AT FIRST , IN THIS PROGRAM I AM TAKING A DEFAULT SORTED ARRAY

    //Two pointer -> 3 sum problem

    int target;
    cout<<"enter target:";
    cin>>target;

    bool ans=false;

    //set one element and compare rest of them

    for(int i=0;i<n;i++)
    {
        int lo=i+1,hi=n-1;
        
        while(lo<hi)
        {
            int current =arr[i]+arr[lo]+arr[hi];
            
            if(current==target)
            {
                ans=true;
            }
            
            if(current<target)
            {
                lo++;
            }
            else{
                hi--;
            }
        }
    }

    if(ans)
    {
        cout<<"true";

    }
    else{
        cout<<"false";
    }
}