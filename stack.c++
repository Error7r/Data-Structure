#include <iostream>
using namespace std;

#define size 6
int stack[size];
int top = -1;


void Push()
{
    if(top == size -1 )
        cout<<"The stack is full\n";
    else
    {
        int value;
        cout<<"Etner the value: "; cin>>value;
        stack[++top] = value;
    }
}


void Pop()
{
    if(top == -1)
        cout<<"The stack is empty\n";
    else
        top--;
}


void Print()
{
    if(top  == -1)
        cout<<"The stack is Empty!\n";
    else
    {
        cout<<"The stack is: ";
        for(int i = 0 ; i <= top ; i++)
        cout<<stack[i]<<' ';
        cout<<endl;
    }
}


int main()
{
    int x;
    while(true)
    {
        cout<<"1.push 2.pop 3.print\n";
        cout<<"index: ";cin>>x;

        if(x==1)
            Push();
        else if(x == 2)
            Pop();
        else if(x == 3)
            Print();
    }
}