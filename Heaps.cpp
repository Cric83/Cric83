#include<iostream>
using namespace std;

void Insert(int A[], int n)  // n is index of element we are going to insert
{
  int temp, i=n;
  temp=A[i];
  
  while(i>1 && temp>A[i/2])
  {
    A[i]=A[i/2];
    i=i/2;	
  }
  A[i]=temp;

}

void Display(int A[])
{
	for(int i=1;i<=8;i++)
	{
		cout<<A[i]<<" ";
	}
}


int main()
{
  int H[]={0,1,2,30,12,45,32,90,5};
  
  for(int i=2;i<=7;i++)
  {
	  Insert(H,i);
  }
  
  Display(H);
 return 0;
 
}