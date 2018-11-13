#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
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
			node *newnode;
			newnode=new struct node;
			newnode->data=a;
			newnode->next=newnode;
			head=newnode;
		}
		void insertatbeg(int a)
		{
			if(head==NULL)
				create(a);
			else
			{
				node *nm,*ptr;
				ptr=head;
				nm=new node;
				nm->data=a;
				while(ptr->next!=head)
					ptr=ptr->next;
				nm->next=head;
				ptr->next=nm;
				head=nm;
		    }
		}
		void insertatend(int a)
		{
			if(head==NULL)
				create(a);
			else
			{
				node *nm,*ptr;
				ptr=head;
				nm=new node;
				nm->data=a;
				while(ptr->next!=head)
					ptr=ptr->next;
				ptr->next=nm;
				nm->next=head;
			}
		}
		void insertatloc(int a,int loc)
		{
			if(head==NULL)
				create(a);
			else if(head->next==NULL && loc!=1)
			{
				insertatend(a);
			}
			else if(loc==1)
			{
				insertatbeg(a);
			}
			else
			{
				node *temp;
				temp=head;
				for(int i=1;i<loc-1;i++)
				{
					temp=temp->next;
				}
				node *newnode;
				newnode=new struct node;
				newnode->data=a;
				newnode->next=temp->next;
				temp->next=newnode;
			}
		}
		void deleteNode(int key) 
		{ 
    		if (head == NULL) 
        		return;
    		struct node *curr = head, *prev; 
    		while (curr->data != key) 
    		{ 
        		if (curr->next == head) 
        		{ 
            		cout<<"\nGiven node is not found in the list!!!"; 
            		break; 
        		} 
        		prev = curr; 
        		curr = curr -> next; 
			} 
    		if (curr == head) 
    		{ 
       			prev = head; 
        		while (prev -> next != head) 
            		prev = prev -> next; 
        		head = curr->next; 
        		prev->next = head; 
    		}
    		else if (curr -> next == head) 
    		{ 
        		prev->next = head;
    		} 
    		else
    		{ 
        		prev->next = curr->next;
    		} 
		}
		void search(int num)
		{
			node *ptr=head;
			do{
				if(ptr->data==num)
					cout<<"Number found";
				else
					ptr=ptr->next;
			}
			while(ptr!=head);
			if(head->data!=num && ptr==head)
				cout<<"Number not present";
		}
		void traverse()
		{
			node *curr;
			for(curr=head;curr->next!=head;curr=curr->next)
			{
				cout<<"The data is "<<curr->data<<endl;
			}
			cout<<"The data is "<<curr->data<<endl;
		}
};
int main()
{
	list l;
	int n,a,p;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		l.insertatend(a);
	}
	int ch;
	cin>>ch;
	while(ch!=0){
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
			l.deleteNode(a);
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
