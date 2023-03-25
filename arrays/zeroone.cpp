#include<bits/stdc++.h>
using namespace std;
 
void sort(vector<int> &arr){
    int start=0;
    for(int i=0;i<arr.size();i++){

        if(arr[i]==0){
            swap(arr[i],arr[start]);
            start++;
        }
        i++;
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
 
int main()
{
    vector<int> arr={0,1,0,1,0,0,1,1,1,0};

    sort(arr);

    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}