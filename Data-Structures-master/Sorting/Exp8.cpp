#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int temp,j;
	for(int i=1;i<n;i++)
	{
		int flag=0;
		temp=arr[i];
		for(j=i-1;j>=0;j--)
		{
			if(arr[j]>temp)
				arr[j+1]=arr[j];
			else
			{
				flag=1;
				arr[j+1]=temp;
				break;
			}
		}
		if(flag==0)
			arr[0]=temp;
	}
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	int i=0,a;
	cout<<"Enter element to be inserted:";
	cin>>a;
	while(arr[i]<a)
	{
		i++;
	}
	for(int j=n-1;j>=i;j--)
		arr[j+1]=arr[j];
	arr[i]=a;
	for(int i=0;i<n+1;i++)
		cout<<arr[i]<<" ";
}
