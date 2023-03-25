#include<bits/stdc++.h>
using namespace std;
 
vector<int> solve(vector<string> words){
    int l = words.size();
    vector<int> ans;
    for(int i=0;i<l;i++){

        int count =1;
        int sum=0;
        for(int j=1;j<words[i].size();j++){
            if(words[i][j-1]==words[i][j])
            {
                count+=1;
            }
            else{
                sum+=count/2;
                count=1;
            }
        }
        sum+=count/2;
        count=1;

        ans.push_back(sum);
    }

    return ans;
}
 
int main()
{
    vector<string> words = {"addbceee","boook","break"};
    vector<int> ans = solve(words);
    cout<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}