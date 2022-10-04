#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void insertion(int A[], int size)
{
	int n=size;
	for(int i=0;i<n-1;i++)
	{
		while(A[i]>A[i+1] && i>=0)
		{
			int temp=A[i];
			A[i]=A[i+1];
			A[i+1]=temp;
			i--;
		}
	}
	
}

void Display(int A[], int size)
{
	int n=size;
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
}
int main()
{
	int n;
	int A[n];
	cout<<"Enter size"<<endl;
	cin>>n;
	cout<<"Enter elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	
	//int A[]={12,3,4,5,2,6,7,9,555,4,3};
	insertion(A,8);
	Display(A,8);
	
	return 0;
}