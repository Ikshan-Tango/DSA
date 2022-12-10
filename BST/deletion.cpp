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

node* inorderSucc(node* root)
{
    node* curr= root;
    while(curr && curr->left!=NULL)
        curr = curr->left;
    
    return curr;
}

node* deleteinbst(node* root,int val)
{
    // 1) Find the element that you want to delete
    // if(root == NULL)
    // {
    //     cout<<"This shit to delete does not even exist bro like wtf!";
    //     return nullptr;
    // }
    if(val<root->data)
    {
        root->left = deleteinbst(root->left,val);
    }
    else if(val>root->data)
    {
        root->right = deleteinbst(root->right,val);
    }

    else{
        //Here in we have found the element to delete

        if(root->left==NULL)
        {
            //Case 2 and even case 1 is handled using this shit
            //interchange the right child node
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            //still case 2
            node* temp = root->left;
            free(root);
            return temp;
        }

        //CASE 3
        //find the inorder succesor and then intercharnge the nodes

        node* temp = inorderSucc(root->right);
        // remember that we literally dont need to swap the nodes, we can just put in the temp->Data there

        root->data = temp->data;
        // now we need to delete the node that we swapped down
        root->right = deleteinbst(root->right,temp->data);
    }
    return root;
}



int main()
{
    node* root = NULL;

    root = insertBST(root,4);
    insertBST(root,2);
    insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,6);

    inorder(root);

    root = deleteinbst(root,3);
    cout<<endl;

    inorder(root);

    return 0;
}