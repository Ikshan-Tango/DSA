#include<bits/stdc++.h>
using namespace std;
 


vector<pair<int,int>> Jobseq(vector<int> &start, vector<int> &finish){

    // firstly we need to sort the finish time array in ascending order

    // we need to make sure that we do the first task in finishing array always

    // check whether the next jobs starting time is > finishing time of last task then only we can perform it

    vector<pair<int,int>> ans;

    ans.push_back(pair<int,int>(start[0],finish[0]));
    int finisht = finish[0];
    for(int i=1;i<finish.size();i++){
        if(start[i]>=finisht)
        {
            ans.push_back( pair<int,int>(start[i],finish[i])) ;
            finisht = finish[i];
        }
    }

    return ans;
}


 
int main()
{

    vector<int> start = {10,12,20};
    vector<int> finish = {20,25,30};

    vector<pair<int,int>> toshow = Jobseq(start,finish);

    cout<<endl<<endl;

    for(int i=0;i<toshow.size();i++){
        cout<<toshow[i].first<<" "<<toshow[i].second<<endl;
    }

    return 0;



}