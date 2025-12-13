#include <iostream>
using namespace std;


struct Node{
    int value;
    Node* next;
};
typedef Node* nodeptr;


void CreatClink(nodeptr &plist)
{
    plist = new Node;
    cout<<"Enter the first value: ";
    cin>>plist->value;

    plist->next = plist;
}

void InsertClink(nodeptr &plist)
{
    if(plist == 0)
    {
        CreatClink(plist);
        return;
    }
    nodeptr p = new Node;
    cout<<"Enter the value: ";
    cin>>p->value;


    p->next = plist->next;
    plist->next = p;
}

void DeleteClink(nodeptr &plist)
{
    if(plist == 0 ||plist->next == plist)
    {
        plist = 0;
        return;
    }
    nodeptr p;
    p = plist->next;
    plist->next = p->next;
    delete(p);
}

void PrintClink(nodeptr &plist)
{
    if(plist == 0)
    {
        cout<<"Clinklist is empty\n";
        return;
    }
    nodeptr temp = plist->next;
    cout<<"The Clinklist is: ";
    for(temp = plist->next ; temp != plist ; temp = temp->next)
        cout<<temp->value<<' ';
    cout<<plist->value<<' ';
    cout<<endl;
}
int main()
{
    nodeptr plist;
    CreatClink(plist);
    int x;
    while(true)
    {
        cout<<"1.Insert 2.Delete\n";
        cout<<"Enter one of the following: ";
        cin>>x;
        if(x == 1)
            InsertClink(plist);
        else if(x == 2)
            DeleteClink(plist);
        PrintClink(plist);
    }
    return 0;
}