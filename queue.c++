#include <iostream>
using namespace std;

#define size 5
int queue[size];

int f = -1;
int r = -1;

void insert()
{
    
    if(r == size -1)
    {
        cout<<"The Cqueue is FULL!\n";
        return;
    }
    
    int value;      
    cout<<"Enter a num: ";cin>>value;
        
    r++;
    queue[r] = value;   
    
        
    if(f == -1)
        f = 0;
        
}


           
void Delete()
{   
    if(f == -1)
        cout<<"The queue is empty!\n";
    else if(f == r)
        f = r = -1;
    else 
        f++;

}

void Print()
{
    if(f == -1)
    {
        cout<<"The queue is Empty!\n";
        return;
    }

    cout<<"The queue: ";
    for(int i = f ; i <= r ; i++)
        cout<<queue[i]<<' ';
    cout<<endl;
}


int main()
{
    int x;
    while(true)
    {
        cout<<"Enter 1.Insert or 2.Delete : ";
        cin>>x;

        if(x == 1) insert();
        else if(x == 2) Delete();
        Print();
    }
}