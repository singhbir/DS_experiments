#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
int findPivot(int arr[],int first,int last)
{
	int pivot=arr[last];
	int i=first;
	for(int j=first;j<last;j++)
	{
		if(arr[j]<=pivot)
		{
			swap(arr[i],arr[j]);
			i++;
		}
	}
	swap(arr[i],arr[last]);
	return i;
}
void sort(int arr[],int first,int last)
{
	if(first<last)
	{
		int pivot=findPivot(arr,first,last);
		sort(arr,first,pivot-1);
		sort(arr,pivot+1,last);
	}
}
int main()
{
	int size;
	cout<<"Enter size:";
	cin>>size;
	int arr[size];
	for(int i=0;i<size;i++)
		cin>>arr[i];
	sort(arr,0,size-1);
	cout<<"array is:\n";
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
}
