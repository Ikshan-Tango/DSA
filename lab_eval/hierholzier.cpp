#include<bits/stdc++.h>
using namespace std;

void printCircuit(vector<vector<int>> adj){
    //count the number of edges to every vertex
    unordered_map<int,int> edge_count;

    for(int i=0;i<adj.size();i++){
        edge_count[i] = adj[i].size();
    }

    if(adj.size()==0){
        return;
    }

    stack<int> curr_path;
    vector<int> circuit;

    curr_path.push(0);
    int curr_v = 0;

    while(!curr_path.empty()){
        
        if(edge_count[curr_v]){
            curr_path.push(curr_v);

            int next_v = adj[curr_v].back();

            edge_count[curr_v]--; //as we are taking a new vertex from the adj
            adj[curr_v].pop_back();

            curr_v = next_v;
        }
        else{//push it to final answer
            circuit.push_back(curr_v);
            //backtracking

            curr_v = curr_path.top();
            curr_path.pop();
        }

        
    }
    // we've got the circuit, now print it in reverse
    for (int i=circuit.size()-1; i>=0; i--)
    {
        cout << circuit[i];
        if (i)
        cout<<" -> ";
    }
}

int main()
{
    vector< vector<int> > adj1;
 
    // Input Graph 1
    adj1.resize(3);
 
    // Build the edges
    adj1[0].push_back(1);
    adj1[1].push_back(2);
    adj1[2].push_back(0);
    printCircuit(adj1);
    cout << endl;

}