#include<iostream>
using namespace std;
 
void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int pivoting(int arr[],int l,int r)
{
    int pivot = arr[r];

    int i=l-1;
    for(int j=l;j<r;j++)
    {
        if(arr[j]<pivot)
        {
            i++;//SABSE PEHLE i KO AAGE BADHANA HAI THEN SWAP
            swap(arr,i,j);
        }
    }

    swap(arr,i+1,r);
    return i+1;// returning the new index of the pivot
}

void Quicksort(int arr[],int l,int r)
{
    if(l<r)
    {
        int pi = pivoting(arr,l,r);

        Quicksort(arr,l,pi-1);
        Quicksort(arr,pi+1,r);
    }
}
 

int main()
{
    int arr[]={9,6,2,6,8,1,2};
    Quicksort(arr,0,6);

    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}