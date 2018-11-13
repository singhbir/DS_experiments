#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	node *left,*right;
	int info;
}*root;
class bst{
	public:
		void insert(node *ptr,int num)
		{
			if(root==NULL)
			{
				node *nn=new node;
				nn->info=num;
				nn->left=NULL;
				nn->right=NULL;
				root=nn;
				return;
			}
			else
			{
				if(num<ptr->info)
				{
					if(ptr->left!=NULL)
						insert(ptr->left,num);
					else
					{
						node *nn=new node;
						ptr->left=nn;
						nn->info=num;
						nn->left=NULL;
						nn->right=NULL;
						cout<<num<<" is left child of "<<ptr->info<<endl;
						return;
					}
				}
				else if(num>ptr->info)
				{
					if(ptr->right!=NULL)
						insert(ptr->right,num);
					else
					{
						node *nn=new node;
						ptr->right=nn;
						nn->info=num;
						nn->left=NULL;
						nn->right=NULL;
						cout<<num<<" is right child of "<<ptr->info<<endl;
						return;
					}
				}
				else if(num==ptr->info)
					return;
			}
		}
		void inorder(node *ptr)
		{
			if(ptr==NULL)
				return;
			if(ptr->left!=NULL)
				inorder(ptr->left);
			cout<<ptr->info<<" ";
			if(ptr->right!=NULL)
				inorder(ptr->right);
		}
		void preorder(node *ptr)
		{
			if(ptr==NULL)
				return;
			cout<<ptr->info<<" ";
			if(ptr->left!=NULL)
				preorder(ptr->left);
			if(ptr->right!=NULL)
				preorder(ptr->right);
		}
		void postorder(node *ptr)
		{
			if(ptr==NULL)
				return;
			if(ptr->left!=NULL)
				postorder(ptr->left);
			if(ptr->right!=NULL)
				postorder(ptr->right);
			cout<<ptr->info<<" ";
		}
		node *min(node *ptr)
		{
			while(ptr->left!=NULL)
				ptr=ptr->left;
			return ptr;
		}
		node* del(node *ptr,int num)
		{
			if(ptr==NULL)
				return ptr;
			if(num<ptr->info)
				ptr->left=del(ptr->left,num);
			else if(num>ptr->info)
				ptr->right=del(ptr->right,num);
			else
			{
				if(ptr->left==NULL)
				{
					node *ptr1=ptr->right;
					free(ptr);
					return ptr1;
				}
				else if(ptr->right==NULL)
				{
					node *ptr1=ptr->left;
					free(ptr);
					return ptr1;
				}
				node *ptr1=min(ptr->right);
				ptr->info=ptr1->info;
				ptr->right=del(ptr->right,ptr1->info);
			}
			return ptr;
		}
};
int main()
{
	bst b;
	int n,num;
	cin>>n;
	root=NULL;
	while(n!=0)
	{
		switch(n)
		{
			case 1:
				cin>>num;
				b.insert(root,num);
				break;
			case 2:
				cin>>num;
				root=b.del(root,num);
				break;
			case 3:
				cout<<"Inorder: ";
				b.inorder(root);
				cout<<endl<<"Preorder: ";
				b.preorder(root);
				cout<<endl<<"Postorder: ";
				b.postorder(root);
				cout<<endl;
				break;
		}
		cin>>n;
	}
}
