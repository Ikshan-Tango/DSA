// code to find the max height of a binary tree
#include<iostream>
using namespace std;

// code of a binary tree
class node{
    public:

    int data;
    node* left;
    node* right;

    node(int val)
    {
        data=val;
        left=right=NULL;
    }
};

node* insertion(node* root,int val)
{
    
    node* n= new node(val);
    
       

    return root;//when all the operations are done and the call stack comes back to level 1 then we want to return the original root of the tree

}


int max_height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left_height = max_height(root->left);
    int right_height = max_height(root->right);
    return max(left_height,right_height)+1;
}

int main()
{
    node* root = NULL;
    root = insertion(root,5);
    insertBST(root,1);
    insertBST(root,4);
    insertBST(root,3);
    insertBST(root,2);
    insertBST(root,7);
    cout<<max_height(root);
    return 0;
}
//
//
// Path: BinaryTree/Max_Height.cpp