#include<iostream>
using namespace std;


void bubble(int A[], int size)
{
	int flag;
	
	for(int i=0;i<size;i++)
	{
		for(int j=i;j<size;j++)
		{
			flag=0;
			if(A[i]>A[j])
			{
				int temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
			if(flag==1)
			{
				break;
			}
		}
	}
	
	
}



void insertion(int A[], int size)
{
	
	int i=0;
	int j=i+1;
	
	while(i<size-1)
	{
		j=i+1;
		if(A[i]>A[j])
		{
			int temp=A[i];
			A[i]=A[j];
			A[j]=temp;
			j++;
			i++;
		}
		i++;
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
	int A[]={2,12,34,45,3,2,1,0,36};
	bubble(A,9);
	Display(A,9);
	cout<<endl<<"insertion"<<endl;
	insertion(A,9);
	Display(A,9);
	
}