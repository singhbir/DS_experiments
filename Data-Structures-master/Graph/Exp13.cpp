#include<iostream>
#define n1 100
using namespace std;
void create(int n,int a[][n1])
{
	cout<<"Enter graph value:\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
				a[i][j]=0;
			else
				cin>>a[i][j];
		}
	}
}
void insertedge(int n,int a[][n1])
{
	int b,c;
	cout<<"Enter the 2 nodes:\n";
	cin>>b>>c;
	a[b-1][c-1]=1;
	a[c-1][b-1]=1;
}
void deleteedge(int n,int a[][n1])
{
	int b,c;
	cout<<"Enter 2 nodes:\n";
	cin>>b>>c;
	a[b-1][c-1]=0;
	a[c-1][b-1]=0;
}
void display(int n,int a[][n1])
{
	cout<<"The graph matrix is:\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}
void bfs(int n,int adj[][n1],int start)
{
	bool visited[n]={0};
	int queue[n],front=-1,rear=-1;
	queue[0]=start;
	front=rear=0;
	visited[start]=1;
	while(rear>=front)
	{
		start=queue[front];
		cout<<queue[front]<<" ";
		front++;
		for(int i=0;i<n;i++)
		{
			if(adj[start][i]==1 && visited[i]==0)
			{
				visited[i]=1;
				rear++;
				queue[rear]=i;
			}
		}
	}
	cout<<endl;
}
void dfs(int n,int adj[][n1],int start)
{
	bool visited[n]={0};
	int stack[n],top=-1;
	stack[0]=start;
	top++;
	visited[start]=1;
	while(top!=-1)
	{
		start=stack[top];
		cout<<stack[top]<<" ";
		top--;
		for(int i=0;i<n;i++)
		{
			if(adj[start][i]==1 && visited[i]==0)
			{
				visited[i]=1;
				top++;
				stack[top]=i;
			}
		}
	}
	cout<<endl;
}
int main()
{
	int n;
	cout<<"Enter graph size:";
	cin>>n;
	int a[n1][n1];
	create(n,a);
	insertedge(n,a);
	deleteedge(n,a);
	display(n,a);
	bfs(n,a,0);
	dfs(n,a,0);
}
