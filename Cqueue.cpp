#include <iostream>
using namespace std;

#define size 4
int Cqueue[size];
int r= -1;
int f=-1;

void Insert()
{
    if((r + 1) % size == f) // or (f == 0 && r == size -1) || r = f-1
    {
        cout<<"The Cqueue is FULL!\n";
        return;
    }

    int value;
    cout<<"Enter the value: ";
    cin>>value;
    
    if (f == -1)
        f = r = 0;
    else
        r = (r + 1) % size;

    Cqueue[r] = value;
}
void Delete()
{
    if(f == -1)
        cout<<"The queue is Empty!\n";
    else if(f == r)
        r = f = -1;
    else 
        f = (f + 1) % size;
}

void Print()
{
    if(f == -1)
    {
        cout<<"The Cqueue is Empty!\n";
        return;
    }

    cout<<"The Cqueue is: ";
    if(r < f)
    {
        for(int i = f; i<size;i++)
            cout<<Cqueue[i]<<' ';

        for(int i = 0; i<=r;i++)
            cout<<Cqueue[i]<<' ';
    }
    else
        for(int i = f;i <=r;i++)
            cout<<Cqueue[i]<<' ';
    cout<<endl;
}

int main()
{
    int x;
    while(true)
    {
        cout<<"Enter 1.Insert or 2.Delete : ";
        cin>>x;

        if (x == 1) Insert();
        else if(x == 2) Delete();
        Print();
    }
}
