#include<iostream>
using namespace std;

void selection(int A[], int size)
{
	// this is unused code for selection sort
	// for(int i=0;i<size;i++)  
	// {
	// 	int j=i;
	// 	int k=i;
	// 	while(j<=size)
	// 	{
	// 		j+=1;
	// 		if(A[j]<A[k])
	// 		{
	// 			k=j;
	// 		}
	// 	}
	// 	int temp=A[i];
	// 	A[i]=A[k];
	// 	A[k]=temp;
	// }

   for(int i=0;i<size;i++)
{
    int k=i;
    int j=i;
    while(j<size)
    {
        j+=1;
        if(A[j]<A[k])
        {
          
            k=j;
        }
    }
    int temp=A[i];
	A[i]=A[k];
	A[k]=temp;
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
//int A[]={1,100,12312,3124324,54354,0};
int n;
cin>>n;
int A[n];
for(int i=0;i<n;i++)
{
	cin>>A[i];
}

selection(A,n);
Display(A,n);
return 0;	
}
