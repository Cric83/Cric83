#include<iostream>
//#include vector;
using namespace std;


void countsort(int A[], int size)
{
	int max=A[0];
//	int count=0;
	for(int i=0;i<size;i++)
	{
		if(A[i]>max)
		{
			max=A[i];
		}
	}
	int *B;
	B=new int[max+1];
	for(int i=0;i<max+1;i++)
	{
		B[i]=0;
	}
	for(int i=0;i<size;i++)
	{
		B[A[i]]++;
	}
	
	int j=0;
	int i=0;
	while(i<max+1)
	{
		if(B[j]>0)
		{
			A[i++]=j;
			B[j]--;
		}
		else
		{
			j++;
		}	
		
	}
	/*for(int i=0;i<=max;i++)
	{
		if(B[i]>0)
		{
	
			while(B[i]>0)
			{
				A[j++]=i;
				B[i]--;
			}
			
		}
	}*/
}

void Display(int A[], int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<A[i]<<" ";
	}
}

int main()
{
	
	int A[]={6,3,9,10,15,6,8,12,3,6};
	countsort(A,10);
	Display(A,10);
}