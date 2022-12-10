#include<iostream>
using namespace std;

//L AND R ARE THE INDEXES HERE

void merge(int arr[],int l,int mid, int r)
{
    //ab yaha hmari array meh l->mid sorted and mid->r sorted hai, bass un dono ko sahi order meh laana hai
    //NOTE: ham same array meh hi values compare and then unhe sahi position pr nhi daal skte, so we need to create 2 temporary arrays

    int n1=mid-l+1;
    int n2=r-mid;
    
    int a[n1];
    int b[n2];

    for(int i=0;i<n1;i++)
    {
        a[i]=arr[l+i];
    }
    
    for(int i=0;i<n2;i++)
    {
        b[i]=arr[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=l; //make sure that this value is initialised with l only and dont take it as 0;

    while(i<n1 || j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            k++;
            i++;
        }
        else{
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        arr[k]=a[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        arr[k]=b[j];
        k++;
        j++;
    }
    

}

void disp(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
 
void mergesort(int arr[],int l,int r)
{
    if(l<r) //if my left == right then it means that there is only one element left
    {
        int mid=(l+r)/2;

        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);

        merge(arr,l,mid,r);
    }
}

int main()
{
    int arr[]={5,4,3,2,1};
    mergesort(arr,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i];
    }
    return 0;
}