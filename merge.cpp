#include<iostream>
using namespace std;

void merge(int A[], int low, int mid, int high)
{
	int i=low;
	int k=low;
	int j=mid+1;
	int B[100];
	while(i<=mid && j<=high)
	{
		if(A[i]<A[j])
		{
			B[k++]=A[i++];
		}
		else
		{
			B[k++]=A[j++];
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

void mergesort(int A[],int size)
{
	int p,low,high,mid,i;
	for(p=2;p<=size;p=p*2)
	{
		for(i=0;i+p-1<size;i=i+p)
		{
			 low=i;
			 high=i+p-1;
			 mid=(low+high)/2;
			merge(A,low,mid,high);
		}
		if(size-i>p/2)
		{
			low=i;
			high=i+p-1;
			mid=(low+high)/2;
			merge(A,low,mid,size-1);
		}
	}
	if(p/2<size)
	{
		merge(A,0,p/2-1,size-1);
	}
}
int main()
{
	int A[]={11,13,7,12,16,9,24,5,10,3,123};
//	int l=0,h=8;
//	int mid=(l+h)/2;
	mergesort(A,11);
	for(int i=0;i<11;i++)
	{
		cout<<A[i]<<" ";
	}

}
