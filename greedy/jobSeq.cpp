#include<bits/stdc++.h>
using namespace std;
 
//Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also given that every job takes a single unit of time, so the minimum possible deadline for any job is 1. Maximize the total profit if only one job can be scheduled at a time.


class Jobs{
    public:
        int id;
        int deadline;
        int profit;
};


vector<int> answer(vector<Jobs> ques){
    vector<int> idseq;

    //sort the jobs according to their deadlines in descending order

    //compare the jobs which have the same deadlne and then choose the one which gives the max profit

    int profit = ques[0].profit;
    int idx=0;
    bool flag =0;

    for(int i=0;i<ques.size();i++){
        //check if the prev one and the curr deadline are the same, 
        
        if(i==0){
            //donothin


        }

        //if they are then store a big profit out of the two

        else if(ques[i].deadline==ques[i-1].deadline)
        {
            profit = (ques[i].profit>ques[i-1].profit)?ques[i].profit :profit; 
            idx = (ques[i].profit>ques[i-1].profit)? i :idx;

            if(i==ques.size()-1)    
                flag =1;
        }       

        //if they are not same then update the bigger profit of the prev one and set a new value to this profit var

        else{
            idseq.push_back(ques[idx].id);
            profit = ques[i].profit;
            idx = i;
        }

    }
    if(flag)
        idseq.push_back(ques[idx].id);

        
    return idseq;

}
 
int main()
{

    Jobs obj[5];

    obj[0].id = 1;
    obj[0].deadline = 3;
    obj[0].profit =15 ;

    obj[1].id = 2;
    obj[1].deadline = 2;
    obj[1].profit =27 ;

    obj[2].id = 3;
    obj[2].deadline = 2;
    obj[2].profit =100 ;

    obj[3].id = 4;
    obj[3].deadline = 1;
    obj[3].profit =19 ;

    obj[4].id = 5;
    obj[4].deadline = 1;
    obj[4].profit =30 ;


    vector<Jobs> ques = {obj[0],obj[1],obj[2],obj[3],obj[4]};

    vector<int> id = answer(ques);

    cout<<endl;
    for(int i=0;i<id.size();i++){
        cout<<id[i]<<endl;
    }

    cout<<"answer:"<<" 1 3 5 ";

    
    return 0;
}