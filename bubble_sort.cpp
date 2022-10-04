#include<iostream>
#include<vector>
using namespace std;


void swap(int a, int b)
{
	int temp=a;
	a=b;
	b=temp;
}

void bubble(int x[], int n)
{
	int flag=0;
	for(int i=0;i<n;i++)             // to reduce tc
	{
		flag=0;
		for(int j=0;j<n-1-i;j++)
		{
			
			if(x[j]>x[j+1])
			{
				int temp=x[j];
				x[j]=x[j+1];
				x[j+1]=temp;
				flag=1;
			}
		
		
		}
			if(flag==0)
		{
			break;
		}
		
	}
	
	
}



int main()
{
	int n;
	cout<<"Enter size"<<endl;
	cin>>n;
	int A[n];
	cout<<"Enter elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	bubble(A,n);
	cout<<"After bubble sort"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
	
	return 0;
}