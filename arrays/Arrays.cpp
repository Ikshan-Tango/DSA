#include<iostream>
using namespace std;
/*
int main()
{
    //FINDING THE LONGEST SUBARRAY HAVING AN AP

    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    //ek iss meh hamne pd krke var lena hai jo prev diff dekhega and cd krke jo current difference dekhega 
    
    int pd,cd=0;

    pd=arr[0]-arr[1];
    int count=2;//THe counter which counts the length of subarray, its value is initialised to 2 because a[0]-a[1]!

    for(int i=0;i<n-1;i++)
    {
        cd=arr[i]-arr[i+1];
        if(pd==cd)
        {
            count++;
        }
        else if(cd>pd){
            count=2;
        }
}

    cout<<"The longest subarrya with a constant AP is :"<<count;
}

*/

//RECORD BREAKING DAY QUESTION

int main()
{
    /*important variables-> 1) max number of visitors till the present day to compare 
    2) */

    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int maxvis=arr[0];
    
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>maxvis && (i==n-1||arr[i]>arr[i+1]))
        {
            maxvis=arr[i];
            cout<<arr[i]<<" ";
        }

        else if(arr[i]>maxvis)
        {
            maxvis=arr[i];
        }
    }

    
}