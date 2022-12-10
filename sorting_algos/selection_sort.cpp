#include<iostream>
using namespace std;

//find the minimum element in the array and then swap it to the beginning


void swaping(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void selectionsort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min=arr[i];

        for(int j=i+1;j<n-1;j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
            }
        }
        if(min!=arr[i])
        {
            int temp=min;
            min=arr[i];
            arr[i]=temp;
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<< " ";
    }
}

 
int main()
{
    int arr[]={5,4,7,31,3,2,1};
    selectionsort(arr,7);
    return 0;
}