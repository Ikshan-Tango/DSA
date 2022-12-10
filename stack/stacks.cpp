#include<iostream>
using namespace std;

class stack{
    public:
        int top;
        int len;
        int *arr;

        stack(int n)
        {
            len=n;
            arr = new int[len];
            top=-1;
        }

        void push(int data)
        {
            if(top==len-1)
            {
                cout<<"Stack overflow";
                return;
            }
            else
            {
                top+=1;
                arr[top]=data;
            }
        }

        void pop()
        {
            if(top==-1)
            {
                cout<<"Stack underflow!";
                return;
            }
            else
            {
                cout<<arr[top]<<endl;
                top--;
            }
        }

        void disp()
        {
            for(int i=0;i<top+1;i++)
            {
                cout<<arr[i]<<" ";
            }
        }
};

int main()
{
    stack *obj = new stack(5);
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    return 0;
}