#include<iostream>
using namespace std;
 
int n=6;

void swap(int &i,int &j)
{
    int temp=i;
    i=j;
    j=temp;
}

void insertionsort(int arr[])
{
    for(int i=1;i<n;i++)
    {
        //check if the element found is smaller than previous 
        //if it is smaller then swap it with previous one untill it goes to  0 index or it reached its right position

        int j=i-1;
        int current= arr[i];

        while(arr[j]>current && j>=0)
        {
            swap(arr[j+1],arr[j]);
            j--;
        }
        arr[j+1]=current;
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}
 
int main()
{
    int arr[6]={12,45,23,51,19,8};
    insertionsort(arr);
    return 0;
}