#include <iostream>
using namespace std;

#define size 4
int Cqueue[size];
int f = -1, r = -1;


void Insert()
{
    if( (f == 0 && r == size-1) || (r+1 == f) )
    {
        cout<<"The Cqeueu is Full\n";
        return;
    }

    if(r == size -1)
        r = 0;
    else
        r++;

    int value;
    cout<<"Enter the value: "; cin>>value;
    Cqueue[r] = value;

    if(f == -1) f= 0;
    
}


void Delete()
{
    if(f == -1)
        cout<<"The Cqueue is empty!\n";
    else if(f == r)
        f = r = -1;
    else if(f == size -1)
        f = 0;
    else
        f++;
}


void Print()
{
    if(f == -1)
        cout<<"The Cqueue is empty!\n";
    else
    {
        cout<<"The Cqueue is: ";

        if(r < f)
        {
            for(int i = f ; i < size ; i++)
                cout<<Cqueue[i]<<' ';
                
            for(int i = 0; i <= r; i++)
                cout<<Cqueue[i]<<' ';
        }
        else 
            for(int i = f ; i <= r ; i++)
                cout<<Cqueue[i]<<' ';

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