#include<iostream>
using namespace std;
int main(){
	int n,c,i,x=0;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>c;
	for(i=0;i<n;i++){
		if(c==a[i]){
			c=i;
			x++;
			break;
		}	
	}
	if(x==1){
		cout<<"Number Found at position:"<<c;
	}
	else{
		cout<<"Not found";
	}	
}
