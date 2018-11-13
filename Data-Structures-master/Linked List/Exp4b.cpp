#include<iostream>
using namespace std;
struct node
{
	node *prev,*next;
	int data;
};
class list{
	node *head;
	public:
		list()
		{
			head=NULL;
		}
		void create(int a)
		{
			node *nn;
			nn=new node;
			nn->data=a;
			nn->prev=NULL;
			nn->next=NULL;
			head=nn;
		}
		void insertatbeg(int a)
		{
			if(head==NULL)
			{
				create(a);
			}
			else
			{
				node *nn;
				nn=new node;
				nn->data=a;
				nn->next=head;
				head->prev=nn;
				nn->prev=NULL;
				head=nn;
			}
		}
		void insertatend(int a)
		{
			if(head==NULL)
			{
				create(a);
			}
			else
			{
				node *temp,*nn;
				nn=new node;
				nn->data=a;
				nn->next=NULL;
				temp=head;
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=nn;
				nn->prev=temp;
			}
		}
		void insertatloc(int a,int loc)
		{
			if(head==NULL)
			{
				create(a);
			}
			else if(head->next==NULL)
			{
				if(loc==1)
					insertatbeg(a);
				else
					insertatend(a);
			}
			else
			{
				node *temp,*nn;
				int i=1;
				temp=head;
				nn=new node;
				nn->data=a;
				while(temp!=NULL && i<loc-1)
				{
					temp=temp->next;
					i++;
				}
				if(temp==NULL)
					cout<<"This position is not present in this linked list\n";
				else if(loc==1)
				{
					insertatbeg(a);
				}
				else
				{
					node *q=temp->next;
					q->prev=nn;
					nn->prev=temp;
					nn->next=temp->next;
					temp->next=nn;
				}
				
			}
		}
		void delelement(int a)
		{
			node *temp,*q;
			temp=head;
			while(temp!=NULL && temp->data!=a)
			{
				q=temp;
				temp=temp->next;
			}
			if(temp==NULL)
				cout<<"This element is not present in this linked list\n";
			else{
				node *p=temp->next;
				q->next=p;
				p->prev=temp->prev;
			}
		}
		void search(int num)
		{
			node *ptr=head;
			while(ptr!=NULL)
			{
				if(ptr->data==num){
					cout<<"Element found in list";
					break;
				}
				ptr=ptr->next;
			}
			if(ptr==NULL)
				cout<<"Element not found";
		}
		void traverse()
		{
			node *temp;
			temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<endl;
				temp=temp->next;
			}
		}
};
int main()
{
	list l;
	int a,n,p;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		l.insertatend(a);
	}
	int ch;
	cin>>ch;
	while(ch!=0)
	{
		switch(ch)
	{
		case 1:
			cout<<"Enter elements to insert:";
			cin>>a;
			l.insertatbeg(a);
			cin>>a;
			l.insertatend(a);
			cin>>a>>p;
			l.insertatloc(a,p);
			break;
		case 2:
			cout<<"Enter element to delete:";
			cin>>a;
			l.delelement(a);
			break;
		case 3:
			cout<<"Enter element to search:";
			cin>>a;
			l.search(a);
			break;
		case 4:
			l.traverse();
	}
	cin>>ch;
	}
	return 0;
}
