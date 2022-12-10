#include<iostream>
using namespace std;

class node
{
    public:
        node* prev;
        int data;
        node* next;
        node(int x)
        {
            data=x;
            next=NULL;
            prev=NULL;
        }
};

void insertAtTail(node* &head,int val)//1->2->3   ->4 
{
    //Edge case-> if heaad is null
    if(head==NULL)
    {
        node* n=new node(val);
        head=n;
        return; //so that the function doesnt execute further
    }


    node* n=new node(val);

    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    //Now our temp is at the tail

    temp->next=n;
    n->prev=temp;
}

void InsertAtHead(node* &head,int val)
{
    //edge case-> If head= null
    if(head==NULL)
    {
        node* n= new node(val);
        head=n;
        return;
    }

    node* n=new node(val);

    n->next=head;
    head->prev=n;
    head=n;
}

void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

void deletion(node* &head,int del)
{
    if(head->next==NULL)
    {
        delete head;
        return;
    }

    node* temp=head;

    while(temp->data!=del)
    {
        temp=temp->next;
    }
    //SPECIAL CASE
    if(temp==head)//if the node we want to delete is the node which is the head itself 
    {
        head=temp->next;
        delete temp;
        return;
    }
    //if we want to delete the tail node as then we cant access the next pointer so it will give us error 
    if(temp->next==nullptr)
    {
        temp->prev->next=NULL;
        delete temp;
        return;
    }

    //now we have reached the node which we want to delete

    //general case 
    temp->prev->next=temp->next;

    temp->next->prev=temp->prev;

    delete temp;
}

void deleteAtHead(node* &head)
{
    node* temp=head;
}

void kappend(node* & head,int k)
{
    
}

int main()
{
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);
    cout<<endl;

    kappend(head,3);
    display(head);
}