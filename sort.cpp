#include<iostream>
using namespace std;

void bubble(int A[], int size)
{
for(int i=0;i<size;i++)
{
	
	for(int j=i;j<size;j++)
	{
		if(A[i]>A[j])
		{
			int temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		    //flag=1;	
		}
		
		
	}
}
}

// this is inserton sort
void insertion(int A[], int size)
{
	int i=0;
	int j=0;
	
  for(int i=0;i<size-1;i++)
   {
	 j=i+1;
	 while(j<size)
	 {
		 if(A[i]>A[j])
		 {
			 int temp=A[i];
			 A[i]=A[j];
			 A[j]=temp;
			
		 }
		 j++;
		 
	 }
   }
}

void selection(int A[], int size)  // select position for elements
{
	for(int i=0;i<size;i++)
	{
		int k=i,j=i;
		while(j<size)
		{
			if(A[j]<A[k])
			{
				k=j;
			}
			j++;
		}
		int temp=A[i];
		A[i]=A[k];
		A[k]=temp;
	}
}

int partition(int A[], int low, int high)
{
	int i=low;
    int j=high; 
	int pivot=A[low];
	do
	{
		do{
			i++;
		}while(A[i]<=pivot);
		
		do{
			j--;
		}while(A[j]>pivot);
		
		if(A[i]>A[j])
		{
			int temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}while(i<j);
	
	if(i>j)
	{
		int temp=A[j];
		A[j]=A[l];
		A[l]=temp;
		
	}
	return j;
}

void Quicksort(int A[],int low, int high)
{
	int j;
	
	if(low<high)
	{
		j=partition(A,low,high);
		partition(A,low,j);
		partition(A,j+1,high);
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
  int A[]={12,23,4,5,6,9,8,7,1,INT_MAX};
  bubble(A,9);
  Display(A,9);
  cout<<endl<<"Insertion"<<endl;
  insertion(A,9);
   Display(A,9);
   cout<<endl<<"Selection sort"<<endl;
  selection(A,9);
Display(A,9);  
return 0;
}
