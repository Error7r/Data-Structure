#include <iostream>
using namespace std;

#define size 5
int top = -1;
int arr[size];

void push()
{
    
    if(top == size -1)
    {
        cout<<"The stack is FULL!\n";
        return;
    } 
        
    
    int value;
    cout<<"Enter a num: ";cin>>value;

    top++;
    arr[top] = value;   
    
}

void pop()
{   
    if(top == -1) cout<<"The stack is empty!\n";
    else 
    {
        top--;
        cout<<"Pop done!\n";
    }
}

void print()
{
    if(top  == -1)
    {
        cout<<"The stack is Empty!\n";
        return;
    }

    cout<<"The stack: ";
    for(int i = 0 ; i <= top ; i++)
        cout<<arr[i]<<' ';
    cout<<endl;
}


int main()
{
    int x;
    while(true)
    {
        cout<<"Enter 1.Push or 2.Pop : ";
        cin>>x;

        if(x == 1) push();
        else if(x == 2) pop();
        print();
    }
}