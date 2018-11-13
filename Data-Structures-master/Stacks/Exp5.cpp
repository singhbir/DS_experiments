#include<iostream>
using namespace std;
class stackenter{
	int *arr;
	int size,top;
	public:
		stackenter()
		{
			top=-1;
			cout<<"Enter size\n";
			cin>>size;
			arr=new int[size];
		}
		void push(int item)
		{
			if(top==(size-1))
				cout<<"Stack overflow\n";
			else
			{
				top++;
				arr[top]=item;
			}
		}
		int pop()
		{
			int temp;
			if(top==-1)
				cout<<"Stack underflow\n";
			else
			{
				temp=arr[top];
				top--;
			}
			return temp;
		}
		void peek()
		{
			cout<<arr[top]<<endl;
		}
};
int main()
{
	stackenter s;
	int a,ch;
	cin>>ch;
	while(ch!=0)
	{
		switch(ch)
		{
			case 1:
				cin>>a;
				s.push(a);
				break;
			case 2:
				cout<<s.pop();
				break;
			case 3:
				s.peek();
		}
		cin>>ch;
	}
	return 0;
}
