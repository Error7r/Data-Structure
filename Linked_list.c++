#include <iostream>
using namespace std;

struct node
{
    int value;
    node* next;
};

typedef node* nodeptr;
#define null 0 

void CreateLL(nodeptr &plist)
{
    plist = new node;
    cout<<"Enter the frist value: ";cin>>plist->value;
    plist->next = null;
}

void PrintLL(nodeptr &plist)
{
    if(plist == null)
        cout<<"There is no linklist\n";
    else
    {
        cout<<"The LinkList is: ";
        for(nodeptr p = plist; p != null ; p = p->next)
            cout<<p->value<<' ';
        cout<<endl;
    }
}


void InsertBeg(nodeptr &plist)
{
    nodeptr p = new node;
    cout<<"Enter the value: ";cin>>p->value;

    p->next = plist;
    plist = p;
}

void InsertMid(nodeptr &plist)
{
    nodeptr p = new node;
    cout<<"Enter the value: ";cin>>p->value;
    
    int I;
    cout<<"Enter the index: ";cin>>I;
    
    nodeptr q = plist;
    for(int i = 1; i < I; i++)
        q = q->next;

    p->next = q->next;
    q->next = p;
}

void InsertEnd(nodeptr &plist)
{
    nodeptr p = new node;
    cout<<"Enter the value: ";cin>>p->value;
    
    nodeptr q;
    for(q = plist ; q->next != null; q = q->next);

    q->next = p;
    p->next = null;
}

void DeleteBeg(nodeptr &plist)
{
    if(plist == null)
        cout<<"There is no linklist!\n";
    else 
    {
        nodeptr p = plist;
        plist = plist->next;
        delete(p);
    }
} 

void DeleteMid(nodeptr &plist)
{
    if(plist == null)
        cout<<"There is no linklist!\n";
    else
    {
        int I;
        cout<<"Enter the index: ";cin>>I;
        nodeptr q;
        nodeptr p = plist;
        for(int i = 1; i < I ; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete(p);
    }
}


void DeleteEnd(nodeptr &plist)
{
    if(plist == null)
        cout<<"There is no linklist!\n";
    else
    {
        nodeptr p;
        nodeptr q;

        for(p = plist; p->next != null; p = p->next)
            q= p;
        
        q->next = null;
        delete(p);
    }
}

int main()
{
    nodeptr plist;
    CreateLL(plist);

    int x;
    while(true)
    {
        cout<<"1.Insert 2.Delete\n3.Print\n";
        cout<<"Enter one of the following: ";
        cin>>x;
        if(x == 1)
        {
            cout<<"1.Insert Begin 2.InsertMid 3.InsertEnd\n";
            cout<<"Enter one of the following: ";
            cin>>x;

            if(x == 1)
                InsertBeg(plist);
            else if(x == 2)
                InsertMid(plist);
            else if(x == 3)
                InsertEnd(plist);
        }
        else if(x == 2)
        {
            cout<<"1.DeleteBegin 2.DeleteMid 3.DeleteEnd\n";
            cout<<"Enter one of the following: ";
            cin>>x;

            if(x == 1)
                DeleteBeg(plist);
            else if(x == 2)
                DeleteMid(plist);
            else if(x == 3)
                DeleteEnd(plist);
        }
        else if(x == 3)
            PrintLL(plist);
    }
}