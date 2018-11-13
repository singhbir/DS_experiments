#include<iostream>
using namespace std; 
int main(){
	int i,j,n,temp,x;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	cin>>x;
	int first=0,last=n-1,mid;
	while(first<last)
	{
		mid=(first+last)/2;
		if(x<a[mid])
		{
			last=mid-1;
		}
		else if(x>a[mid])
		{
			first=mid+1;
		}
		else if(a[mid]==x)
		{
			break;
		}
	}
	if(first<last)
	{
		cout<<"The number is found at "<<mid<<" position";
	}
	else
	{
		cout<<"The number is not present in the array";
	}	
}
