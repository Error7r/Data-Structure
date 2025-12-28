#include <iostream>
using namespace std;

#define size 5
int queue[size];
int f = -1 , r = -1;


void Insert()
{
    if(r == size -1)
        cout<<"The queue is full\n";
    else 
        {
            int value;
            cout<<"Enter the value: "; cin>>value;
            queue[++r] = value;
        }

    if(f==-1) f = 0;
}


void Delete()
{
    if(f == -1)
        cout<<"The queue is empty\n";
    else if(f == r)
        f = r = -1;
    else
        f++;
}


void Print()
{
    if(f == -1)
        cout<<"The queue is empty\n";
    else
    {
        cout<<"The queue is: ";
        for(int i = f ; i <= r ; i++)
            cout<<queue[i]<<' ';
        cout<<endl;
    }
}


int main()
{
    int x;
    while(true)
    {
        cout<<"1.Insert 2.Delete 3.Print\n";
        cout<<"Index: "; cin>>x;

        if(x == 1)
            Insert();
        else if(x == 2)
            Delete();
        else if(x == 3)
            Print();
    }
}