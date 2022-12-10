#include<iostream>
using namespace std;

//THIS CPP FILES CONTAINS LINKED LISTS FUNCTIONS LIKE INSERT AT HEAD AND INSERT AT TAIL AND DISPLAY

class node
{
    public:

    int data;

    node *next_ptr;
    node(int val)    //whenever an object of node is created a value is assigned to it using this contructor
    {
        next_ptr= NULL;
        data=val;
    }
};

void InsertAtTail(node* &head, int val) 
{
    node *n= new node(val); //created the  dynamic object using pointer jiske ptr meh filhaal null hai

    if(head==NULL) // to make the first node
    {
        head=n;
        return;
    }//instead of this if loop we could have also called InsertAtHead function to make the first node but this method also works fine

    node *temp=head; //temp pointer hmara first node ko point krta hai
    while(temp-> next_ptr!=NULL) //we reach the last node
    {
        temp=temp->next_ptr;
    } 

    temp->next_ptr=n; // jaha null tha pehle waha ab next node ki location aa jayegi
}

void InsertAtHead(node* &head,int val)
{
    node *n=new node(val);
    n->next_ptr=head;
    head=n;
}

void display(node *head) //taken argument by value because we dont want to change the value of head which is pointing towards the first node
{
    node *temp=head;//as we are taking by value and not by reference we can even take head as our traversing entity as its value wont change when we keep moving forward
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next_ptr;
    }

    cout<<"NULL"<<endl;
}

//searching in linked lists
bool search(node* &head,int key)
{
    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            return true;
        }
        temp=temp->next_ptr; //moving the poiter to the next node is very important and it is done through this step
    }
    return false;
}

//deleting a node from an array

void deletion(node* &head,int val)//this case wont work for corner nodes i.e if we want to delete the head itself
{
    if(head==NULL)//if there is no node in linked list 
    {
        return;
    }

    if(head->next_ptr==NULL)//if there is only one node in linked list present
    {
        //DeleteAtHead(head);
    }

    node *temp=head;

    while(temp->next_ptr->data!=val)
    {
        temp=temp->next_ptr;
    }
    //now we have reached that prev key (n-1)th node... we have to attach with (n+1)th node [nth node is to be removed]

    temp->next_ptr=temp->next_ptr->next_ptr;

    //now the nth node is detached, we have to delete it from computer
    node *ToDelete= temp->next_ptr;
    delete ToDelete;
}

void DeleteAtHead(node* &head)
{
    node *todelete=head;
    head=head->next_ptr;//head is a pointer which points towards the node 
    delete todelete;
}

//REVERSING A LINKED LIST
//ITERATIVE WAY

node* reverse(node* &head)//call by reference because head ki value change krni hai
{
    
    node* prevptr=NULL;
    node* currptr=head;
    node* nextpointer;

    while(currptr!=NULL)
    {
        nextpointer=currptr->next_ptr; //curr is at 1st node and nextpointer will point to 2nd node that is 1st node ka next_ptr
        currptr->next_ptr=prevptr;//reversed the link

        prevptr=currptr;
        currptr=nextpointer;
        //next pointer ko hamne change nhi krna as in first line of this code ham next pointer ko badha rhe hai hi!
    }

    return prevptr;//we are returning the new head of our reversed linked list
}

//REVERSAL THROUGH RECURSION
node* reverseRecursive(node* &head)
{
    //see the video for greater explanation!

    if(head==NULL||head->next_ptr==NULL)
    {
        return head;
    }
    //sabse pehle 1->2->3->4->Null ko 1->2<-3<-4 bnana hai
    node* newhead= reverseRecursive(head->next_ptr);

    //now just reverse the direction of 1->2 node , remember head is still pointing at 1

    head->next_ptr->next_ptr=head;
    head->next_ptr=NULL;

    return newhead;
}

node* reversek(node* &head,int k)
{
    //reverse the first k nodes using iterative method
    node* prevptr=NULL;
    node* curptr=head;
    node* nexptr;

    int count=1;

    while(curptr!=NULL && count<=k)
    {
        //reverse the node
        nexptr=curptr->next_ptr;

        curptr->next_ptr=prevptr;

        prevptr=curptr;
        curptr=nexptr;
        count++;
    }

    if(curptr!=NULL && nexptr!=NULL)
    {
        head->next_ptr=reversek(nexptr,k);//recursion pehle krna hai and return baad meh!
        //next ptr hmara 4 ko point kr rha hoga which is the new head of the k reversed list 1->2->||4->3->6->5||
    }

    return prevptr; //as this points towards our new head 
}

bool detectcycle(node* head)
{
    node* slow=head;
    node* fast =head;
    while(fast!=NULL || fast->next_ptr!=NULL)
    {
        slow=slow->next_ptr;
        fast=fast->next_ptr->next_ptr;

        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}

void removecycle(node* head)
{
    node* fast=head;
    node* slow=head;
    node* temp;

    while(fast!=NULL||fast->next_ptr!=nullptr)
    {
        slow=slow->next_ptr;
        fast=fast->next_ptr->next_ptr;

        if(fast==slow)
        {
            fast=head;
            while(fast->next_ptr!=NULL)
            {
                fast=fast->next_ptr;
                slow=slow->next_ptr;
                if(fast->next_ptr==slow->next_ptr)
                {
                    slow->next_ptr=nullptr;
                    break;
                }
            }
            break;
        }
    }
}   

int main()
{
    node *head=NULL;//creating a pointer of an object which has nothing in it shuru meh
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    InsertAtTail(head,6);

    display(head);
    
    cout<<endl<<endl;

    node* newhead= reversek(head,2);
    display(newhead);    
}