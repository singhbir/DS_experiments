#include<iostream>
using namespace std;
struct node
{
    int info;
    struct node *next;
};
struct linked_list
{
    node *front,*rear;
    linked_list()
    {
        front=NULL;
        rear=NULL;
    }
    void insert_beg();
    void display();
    node* createnode(int);
    void del();
};
node* linked_list::createnode(int x)
{
    node *temp=new node;
    temp->info=x;
    temp->next=NULL;
    return temp;
}
void linked_list::insert_beg()
{
    int ele;
    cin>>ele;
    node *p,*ptr;
    p=createnode(ele);
    if(front==NULL)
    {
        front=p;
        rear=p;
    }
    else
    {
        rear->next=p;
        rear=p;
    }
}
void linked_list::display()
{
    rear->next=front;
    node *temp=front;
    if(front==NULL)
    {
        cout<<"Underflow";
        cout<<"\nQueue is empty";
    }
    else
    {
        while(temp->next!=front)
        {
            cout<<temp->info<<"->";
            temp=temp->next;
        }
        cout<<temp->info;
    }
}
void linked_list::del()
{
    if(front==rear)
    {
        cout<<"Deleted element is: "<<front->info<<endl;
        front=NULL;
    }
    else if(front==NULL)
    {
        cout<<"Underflow";
        cout<<"\nQueue is empty";
    }
    else
    {
        cout<<"Deleted element is: "<<front->info<<endl;
        node* temp=front;
        front=front->next;
        delete temp;
    }
}
int main()
{
    int ch,n,count=0;
    linked_list l1;
    cout<<"Enter the size of queue ";
    cin>>n;
    cout<<"\nEnter choice\n1.Insert\n2.Display\n3.Delete\n";
    cin>>ch;
    while(ch)
    {
        if(ch==1 )
        {
            if(count==n)
            {
                cout<<"Overflow";
            }
            else
            {
                l1.insert_beg();
                count++;
            }
        }
        else if(ch==2)
        {
            l1.display();
        }
        else if(ch==3)
        {
            l1.del();
            count--;
        }
        cout<<"\nEnter choice again: ";
        cin>>ch;
    }
}

