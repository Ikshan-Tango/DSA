#include<iostream>
using namespace std;

#define max 1000000

int main() 
{
	int t;
	cin>>t;
	
	if(t>=1 && t<=100)
	{
    	for(int j=0;j<t;j++)
    	{
    	    int n;
    	    cin>>n;
    	    
	        int ans[max]={0};
	        int arr[max]={0};
	        int final_ans=0;
	        //taking input of array
	        
	        for(int i=0;i<n;i++)
	        {
	            cin>>arr[i];
	        }//taking array as the input
	        
	        for(int i=0;i<max;i++)
	        {
	            ans[arr[i]]+=1;
	        }//implementing the answer array
	        
	        for(int i=0;i<max;i++)
	        {
	            if(i==ans[i] && i!=0)
	            {
	                final_ans=i;
	            }
	        }
	        
	        if(final_ans==0)
	        {
	            cout<<-1<<endl;
	        }
	        else
	        {
	            cout<<final_ans<<endl;
	        }
    	    
    	}
	}
	return 0;
}
