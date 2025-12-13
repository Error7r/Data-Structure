#include <iostream>
using namespace std;

struct node{
    int value;
    node * next;
};
#define nodeptr node* 

void CreatLinklist(nodeptr &plist)
{
    plist = new node;
    cout<<"Enter the fisrt value in LinkList: ";
    cin>>plist->value;
    plist->next = NULL;
}

void PrintLinkList(nodeptr &plist)
{
    if(plist == NULL)
        cout<<"The LinkList is empty!\n"; 
    else
    {
        cout<<"The LinkList is: ";
        for(nodeptr p = plist; p != NULL ; p = p->next)
            cout<<p->value<<" ";
        cout<<endl;
    }
}

void InsertBegin(nodeptr &plist)
{
    nodeptr p = new node;
    cout<<"Enter the value to insertBegin: ";
    cin>>p->value;

    p->next = plist;
    plist = p;
    
}

void InsertMid(nodeptr &plist)
{
    int I;
    cout<<"Enter the Index of linklist: ";cin>>I;

    nodeptr p = new node;
    cout<<"Enter the value to insertMid: ";
    cin>>p->value;

    nodeptr q = plist;

    // ... new_node I ... | IF the condetion I - 1
    // ... I new_node ... | IF the condetion I
    for(int i = 1;i < I; i++)
        q = q->next;
    
    p->next = q->next;
    q->next = p;
}

void InsertEnd(nodeptr &plist)
{
    nodeptr p = new node;
    cout<<"Enter the value to insertEnd: ";
    cin>>p->value;

    nodeptr q;
    for(q = plist;q->next != NULL;q = q->next);
    q->next = p;
    p->next = NULL;
}

void DeleteBegin(nodeptr &plist)
{
    if(plist == NULL)
    {
        cout<<"There are no linklist\n";
        return;
    }
    nodeptr p = plist;
    plist = plist->next;
    delete(p);
}

void DeleteMid(nodeptr &plist)
{
    int I;
    cout<<"Enter the Index of linklist: ";cin>>I;

    nodeptr p= plist;
    nodeptr q;
    for(int i = 1;i < I;i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    delete(p);
}

void DeleteEnd(nodeptr &plist)
{
    nodeptr q = plist;
    nodeptr p;
    for(p = plist; p->next != NULL;p= p->next)
        q = p;

    delete(p);
    q->next = NULL;
}


int main()
{
   nodeptr plist;
    CreatLinklist(plist);
    int x;
    while(true)
    {
        cout<<"1.Insert 2.Delete\n";
        cout<<"Enter one of the following: ";
        cin>>x;
        if(x == 1)
        {
            cout<<"1.Insert Begin 2.InsertMid 3.InsertEnd\n";
            cout<<"Enter one of the following: ";
            cin>>x;

            if(x == 1)
                InsertBegin(plist);
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
                DeleteBegin(plist);
            else if(x == 2)
                DeleteMid(plist);
            else if(x == 3)
                DeleteEnd(plist);
        }

        PrintLinkList(plist);
    }
    return 0;
}