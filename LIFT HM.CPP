#include<iostream.h>
#include<conio.h>

const int f=20;
const int cap=25;

class lift
{
	int floor[f],floor_order[f],sum,n;
	int start,enter,exit,present,diff,temp,pos;
	int i,j,k;
	char rep;

	int location1(int floor[f],int n, int start)
	{
		int flag;
		if(start<=floor[1])
		{
			flag=0;
		}
		else if(start>=floor[n-1])
		{
			flag=n;
		}
		else
		{
			for(i=1;i<n-1;i++)
			{
				if(start>=floor[i])
				flag=i+1;
			}
		}
		return flag;
	}

	int location2(int floor[f],int n, int start)
	{
		int flag;
		if(start>=floor[1])
		{
			flag=0;
		}
		else if(start<=floor[n-1])
		{
			flag=n;
		}
		else
		{
			for(i=1;i<n-1;i++)
			{
				if(start<=floor[i])
				flag=i+1;
			}
		}
		return flag;
	}

	void bubblesort1(int floor[f],int n)
	{
		for(i=1;i<n;i++)
		{
			for(j=1;j<n-i;j++)
			{
				if(floor[j]>=floor[j+1])
				{
					temp=floor[j];
					floor[j]=floor[j+1];
					floor[j+1]=temp;
				}
			}
		}

		pos=location1(floor,n,start);

		if(pos==0)
		{
			floor_order[0]=floor[0];
			for(i=1;i<n;i++)
			{
				floor_order[i]=floor[i];
			}

			cout<<"\nFloor Order:";
			for(k=0;k<n;k++)
			{
				cout<<floor_order[k]<<" ";
			}
			sum=0;
			for(k=0;k<n-1;k++)
			{
				sum+=floor_order[k+1]-floor_order[k];
			}
			cout<<"\nTotal Distance:"<<sum;
		}
		else if(pos==n)
		{
			floor_order[0]=floor[0];
			for(i=1,j=n-1;i<n,j>0;i++,j--)
			{
				floor_order[i]=floor[j];
			}

			cout<<"\nFloor Order:";
			for(k=0;k<n;k++)
			{
			  cout<<floor_order[k]<<" ";
			}
			sum=0;
			for(k=0;k<n-1;k++)
			{
				sum+=floor_order[k]-floor_order[k+1];
			}
			cout<<"\nTotal Distance:"<<sum;
		}
		else
		{
			floor_order[0]=floor[0];
			for(i=1,j=pos-1;i<pos,j>=0;i++,j--)
			{
				floor_order[i]=floor[j];
			}
			for(i=pos;i<n;i++)
			{
				floor_order[i]=floor[i];
			}
			cout<<"\nFloor Order:";
			for(k=0;k<n;k++)
			{
			  cout<<floor_order[k]<<" ";
			}
			sum=0;
			for(i=0;i<pos-1;i++)
			sum+=floor_order[i]-floor[i+1];
			for(i=n-2;i>=pos-1;i--)
			sum+=floor_order[i+1]-floor_order[i];
			cout<<"\nTotal Distance="<<sum;
		}
	}

	void bubblesort2(int floor[f],int n)
	{
		for(i=1;i<n;i++)
		{
			for(j=1;j<n-i;j++)
			{
				if(floor[j]<=floor[j+1])
				{
					temp=floor[j];
					floor[j]=floor[j+1];
					floor[j+1]=temp;
				}
			}
		}

		pos=location2(floor,n,start);

		if(pos==0)
		{
			floor_order[0]=floor[0];
			for(i=1;i<n;i++)
			{
				floor_order[i]=floor[i];
			}
			cout<<"\nFloor Order:";
			for(k=0;k<n;k++)
			{
			  cout<<floor_order[k]<<" ";
			}
			sum=0;
			for(k=0;k<n-1;k++)
			{
				sum+=floor_order[k]-floor_order[k+1];
			}
			cout<<"\nTotal Distance:"<<sum;
		}
		else if(pos==n)
		{
			floor_order[0]=floor[0];
			for(i=1,j=n-1;i<n,j>0;i++,j--)
			{
				floor_order[i]=floor[j];
			}

			cout<<"\nFloor Order:";
			for(k=1;k<n;k++)
			{
			  cout<<floor_order[k]<<" ";
			}
			sum=0;
			for(k=0;k<n-1;k++)
			{
				sum+=floor_order[k+1]-floor_order[k];
			}
			cout<<"\nTotal Distance:"<<sum;
		}
		else
		{
			floor_order[0]=floor[0];
			for(i=1,j=pos-1;i<pos,j>=0;i++,j--)
			{
				floor_order[i]=floor[j];
			}
			for(i=pos;i<n;i++)
			{
				floor_order[i]=floor[i];
			}
			cout<<"\nFloor Order:";
			for(k=0;k<n;k++)
			{
			  cout<<floor_order[k]<<" ";
			}
			sum=0;
			for(i=0;i<pos-1;i++)
			sum+=floor_order[i]-floor[i+1];
			for(i=n-2;i>=pos-1;i--)
			sum+=floor_order[i+1]-floor_order[i];
			cout<<"\nTotal Distance="<<-(sum);
		}
	}

	public:
	void floor_choice()
	{
		n=0;
		cout<<"\nEnter your starting floor:";
		cin>>start;
		beginning:
		cout<<"Enter the number of people already present in the lift in this floor:";
		cin>>present;
		cout<<"Enter the number of people entering the lift in this floor:";
		cin>>enter;
		cout<<"Enter the number of people leaving the lift in this floor:";
		cin>>exit;
		diff=present+enter-exit;
		floor[0]=start;
		do{
		cout<<"Enter the next floor you wanna go:";
		cin>>floor[++n];
		cout<<"Do you wanna goto another floor(y/n)?";
		cin>>rep;
		}while(rep=='y'||rep=='Y');
		clrscr();
		if(diff<=25)
		{
			cout<<start<<"\n";
			for(i=0;i<=n;i++)
			cout<<floor[i]<<" ";
			n++;
			bubblesort1(floor,n);
			bubblesort2(floor,n);
		}
		else
		{
			cout<<"\nCapacity exceeded !!!!";
			cout<<"\nRequesting few people to get down. Max. Capacity is 25 !!\n";
			goto beginning;
		}
	}
};

void main()
{
	clrscr();
	char rep1;
	lift l;
	cout<<"Program based on the working of lift";
	do{
	l.floor_choice();
	cout<<"\nDo you wanna try again(y/n)?";
	cin>>rep1;
	}while(rep1=='y'||rep1=='Y');

}