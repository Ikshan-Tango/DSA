#include<iostream>
using namespace std;
 
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
 
node* insertBST(node* root,int val)
{
    if(root==NULL)
    {
        node* n= new node(val);
        return n;
    }

    if(val>root->data)
    {
        //go to right subtree

        //make the right child as the new root

        root->right = insertBST(root->right,val);
    }
    else{
        // got left subtree
        root->left = insertBST(root->left,val);
    }

    return root;//when all the operations are done and the call stack comes back to level 1 then we want to return the original root of the tree

}

node* SearchinBST(node* root,int val)
{
    if(root==NULL)
    {
        cout<<"Node does not exist!";
        return NULL;
    }
    if(val == root->data)
    {
        cout<<"This value exists in the BST";
        return root;
    }
    if(val<root->data)
    {
        //go to the left subtree to seach the element
        root->left = SearchinBST(root->left,val);
    }
    else{
        root->right = SearchinBST(root->right,val);
    }
    return root;
}

void inorder(node* root)
{
    if(root== NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    node* root = NULL;

    root = insertBST(root,5);
    insertBST(root,1);
    insertBST(root,4);
    insertBST(root,3);
    insertBST(root,2);
    insertBST(root,7);

    inorder(root);

    SearchinBST(root,0);

    return 0;
}