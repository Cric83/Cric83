#include<iostream>
using namespace std;

void merge(int A[], int low, int mid, int high)
{
	int i=low,j=mid+1;
	int B[100];
	int k=low;
	while(i<=mid && j<=high)
	{
		if(A[i]>A[j])
		{
			B[k++]=A[j++];
		}
		else
		{
			B[k++]=A[i++];
		}
		
	}
	for(; i<=mid;i++)
	{
		B[k++]=A[i];
	}
	for(;j<=high;j++)
	{
		B[k++]=A[j];
	}
	
	for(int i=low;i<=high;i++)
	{
		A[i]=B[i];
	}
}



void recursive_merge(int A[], int l,int h)
{
	int mid;
	if(l<h)
	{
		mid=(l+h)/2;
		recursive_merge(A,l,mid);
		recursive_merge(A,mid+1,h);
		merge(A,l,mid,h);
		
	}
}




int main()
{
	int A[]={8,2,9,6,5,3,7,4};
	int low=0;
	int high=7;
	int mid=(low+high)/2;
	recursive_merge(A,0,7);
	
	for(int i=0;i<=high;i++)
	{
		cout<<A[i]<<" ";
	}
	
  return 0;	
	
}