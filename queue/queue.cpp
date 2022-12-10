#include<iostream>
using namespace std;
 
class queue{
    public:

    int front,rear;
    int* arr;

    int len;

    queue(int n)
    {
        len=n;
        arr = new int[n];
        front=rear=-1;
    }

    void enqueue(int data)
    {
        if(rear==len-1)
        {
            cout<<"QUEUE OVERFLOW!";
            return;
        }

        rear+=1;
        arr[rear]=data;
        if(front==-1)
        {
            front=0;
        }
    }

    void dequeue()
    {
        if(front==-1)
        {
            cout<<"STACK UNDERFLOW!";

            return;
        }

        cout<<arr[front]<<endl;
        front+=1;   
        if(front>rear)
        {
            front=rear=-1;
        }
    }

    void disp()
    {
        for(int i=front;i<rear+1;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};
 
int main()
{
    queue *n=new queue(5);

    n->enqueue(1);
    n->enqueue(2);
    n->enqueue(3);
    n->enqueue(4);
    n->enqueue(5);

    n->dequeue();
    n->disp();
    
    n->dequeue();
    n->disp();
    
    n->dequeue();
    n->disp();
    
    n->dequeue();
    n->disp();
    
    n->dequeue();
    
    n->dequeue();

    return 0;
}