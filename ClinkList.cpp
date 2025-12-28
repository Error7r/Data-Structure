#include <iostream>
using namespace std;

struct node
{
    int value;
    node* next;
};
typedef node* nodeptr;
#define null 0

void CreateCLL(nodeptr &plist)
{
    plist = new node;
    cout<<"Enter the first value: ";cin>>plist->value;
    plist->next = plist;
}

void PrintCLL(nodeptr &plist)
{
    if(plist == null)
        cout<<"There is no linklist!\n";
    else
    {
        cout<<"The LinkList: ";
        nodeptr p = plist; 
        do
        {   
            cout<<p->value<<' ';
            p = p->next;
        }
        while(p != plist);
    
        cout<<endl;
    }
}

void InsertBeg(nodeptr &plist)
{
    nodeptr p = new node;
    cout<<"Enter the value: ";cin>>p->value;

    p->next = plist;

    nodeptr q;
    for(q = plist ; q->next != plist ; q = q->next);
    q->next = p; 
    plist = p; 
}

void InsertMid(nodeptr &plist)
{
    nodeptr p = new node;
    cout<<"Enter the value: ";cin>>p->value;

    int I;
    cout<<"Enter the Index: ";cin>>I;

    nodeptr q = plist;
    for(int i = 1; i < I ; i++)
        q = q->next;
    p->next = q->next;
    q->next = p;
}


void InsertEnd(nodeptr &plist)
{
    nodeptr p = new node;
    cout<<"Enter the value: ";cin>>p->value;

    nodeptr q;
    for(q = plist ; q->next != plist; q = q->next);

    q->next = p;
    p->next = plist;
}

void DeleteBeg(nodeptr &plist)
{
    if(plist == null)
        cout<<"There is no Clinklist\n";
    else 
    {
        nodeptr p = plist;
        
        nodeptr q;
        for(q = plist ; q->next != plist ; q = q->next);
        
        plist = plist->next;
        q->next = plist;
        delete(p);
    }
}


void DeleteMid(nodeptr &plist)
{
    if(plist == null)
        cout<<"There is no Clinklist\n";
    else 
    {
        int I;
        cout<<"Enter the Index: ";cin>>I;

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
        cout<<"There is no Clinklist\n";
    else 
    {
        nodeptr p;
        nodeptr q;
        for(p = plist ; p->next != plist; p = p->next)
            q = p;
        q->next = plist;
        delete(p);
    }
}

int main()
{
    nodeptr plist;
    CreateCLL(plist);
    
    int x;
     while(true)
    {
        cout << "1. Insert\n2. Delete\n3. Print\n";
        cout << "Enter your choice: ";
        cin >> x;

        if(x == 1)  
        {
            cout << "1. Insert at Beginning\n2. Insert at Middle\n3. Insert at End\n";
            cout << "Enter your choice: ";
            cin >> x;

            if(x == 1)
                InsertBeg(plist);
            else if(x == 2)
                InsertMid(plist);
            else if(x == 3)
                InsertEnd(plist);
            else
                cout << "Invalid choice!\n";
        }
        else if(x == 2) 
        {
            cout << "1. Delete Beginning\n2. Delete Middle\n3. Delete End\n";
            cout << "Enter your choice: ";
            cin >> x;

            if(x == 1)
                DeleteBeg(plist);
            else if(x == 2)
                DeleteMid(plist);
            else if(x == 3)
                DeleteEnd(plist);
        }
        else if(x == 3)  // Print
            PrintCLL(plist);
        
        
    }
    return 0;
}