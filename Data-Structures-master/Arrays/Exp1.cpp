#include<iostream>
using namespace std;
int main(){
	int n,i,j,x,t,r,c=0;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>x;
	switch(x){
		case 1: {
			cin>>t;
			cin>>r;
			for(int i=n-1;i>=r;i--)
				a[i+1]=a[i];
			a[r]=t;
			n++;
			break;
		}				
		case 2:{
			cin>>t;
			for(i=0;i<n;i++){
				if(a[i]==t){
				for(j=i;j<n-1;j++){
					a[j]=a[j+1];
				}
				c++;	
				}
			}
			if(c==0){
				cout<<"element not found";
			}
			else
				n--;
			break;
		}
		case 3:{
			cin>>t;
			for(i=0;i<n;i++){
				if(a[i]==t){
					c=i;
					break;
				}
			}
			cout<<"The position is "<<c;
			break;
		}
		case 4:{
			for(i=0;i<n;i++){
				cout<<a[i]<<endl;
			}
			break;
		}	
	}
	
}
