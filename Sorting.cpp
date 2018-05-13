//Jayendhra 110117037
//Shiva 110117037
//Sorting in ascending order
#include<iostream.h>
#include<conio.h>
const int s=40;
void bubblesort(int a[s],int n)
{ 
  int temp;
  for(i=0;i<n;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(a[j>=a[j+1])
      temp=a[j];
      a[j]=a[j+1];
      a[j+1]=temp;
    }
  }
  
  for(int k=0;k<n;k++)
  {cout<<a[k]<<" ";}
}

void main()
{
  int a[s],n;char ch;
  cout<<"Welcome";
  cout<<"\nProgram to sort the integers inputted by user in ascending order";
  
  do{
    do{
    cout<<"\nEnter the number of elements:";
    cin>>n;
    if(n==1||n==0)
    {
      cout<<"Minimum two numbers are required for sorting !!";
       break;
    }
    }while(n!=1||n!=0);
  for(int k=0;k<n;k++)
  {
    cout<<"Element "<<k+1<<":";
    cin>>a[k];
  }
  bubblesort(a,n);
  cout<<"Do you wanna try again(y/n)?:";
  cin>>ch;
  }while(ch=='Y'||ch=='y');
}
