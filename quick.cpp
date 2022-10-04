#include<iostream>
#include <bits/stdc++.h>
using namespace std;


void quick(int A[], int size)
{
	int i=0;  // i moves if get greater number than pivot else stop 
	int j=A[size];  // j moves if get greater numbers than pivot else stops
	int pivot=A[i];
	do{
		
		do{
			i++;
		}while(A[i]<pivot);
		do{
			j--;
		}while(A[j]>pivot);
		
		if(i<j)
		{
			int temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}while(i<j);
	
	if(i>j)
	{
		int temp=pivot;
		pivot=A[j];
		A[j]=temp;
	}
	
}

int partition(int A[], int low,int high)
{
	int pivot=A[low];
	int i=low;
	int j=high;
	
	do{
		do{
			i++;
		}while(A[i]<=pivot);
		
		do{
			j--;
		}while(A[j]>pivot);
		if(i<j)
		{
			int temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}while(i<j);
	
	if(i>j)
	{
		int temp=A[j];
		A[j]=A[low];
		A[low]=temp;
		
	}
	
	return j;
	
}

void quicksort(int A[], int low,int high)
{
	int j;
	if(low<high)
	{
		j=partition(A,low,high);
		quicksort(A,low,j);
		quicksort(A,j+1,high);
		
	}
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
	int A[]={11,13,7,12,16,9,24,5,10,3,INT_MAX};
	quicksort(A,0,10);
	Display(A,10);
}
