#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>

const int s=100;
//const int t=10;

void encrypt(char ch[s],int e)
{
	char en;
	for(int i=0;ch[i]!='\0';i++)
	{
		en=ch[i];
		if(e>0)
		{
		if(en>='a'&&en<='z')
		{
			en+=e;
			if(en>'z')
			en=en-'z'+'a'-1;
		}
		else if(en>='A'&&en<='Z')
		{
			en+=e;
			if(en>'Z')
			en=en-'Z'+'A'-1;
		}
		ch[i]=en;
		}

		else if(e<0)
		{
		if(en>='a'&&en<='z')
		{
			en+=e;
			if(en<'a')
			en=en+'z'-'a'+1;
		}
		else if(en>='A'&&en<='Z')
		{
			en+=e;
			if(en<'A')
			en=en+'Z'-'A'+1;
		}
		ch[i]=en;
		}
	}
	cout<<"\nCiphertext:";
	for(int j=0;ch[j]!='\0';j++)
	{
		cout<<ch[j];
	}

}

void decrypt(char ch[s],int e)
{
	char de;
	for(int i=0;ch[i]!='\0';i++)
	{
		de=ch[i];
		if(e>0)
		{
		if(de>='a'&de<='z')
		{
			de-=e;
			if(de<'a')
			de=de+'z'-'a'+1;
		}
		else if(de>='A'&&de<='Z')
		{
			de-=e;
			if(de<'A')
			de=de+'Z'-'A'+1;
		}
		ch[i]=de;
		}

		else if(e<0)
		{
		if(de>='a'&&de<='z')
		{
			de-=e;
			if(de>'z')
			de=de-'z'+'a'-1;
		}
		else if(de>='A'&&de<='Z')
		{
			de-=e;
			if(de>'Z')
			de=de-'Z'+'A'-1;
		}
		ch[i]=de;
		}
	}

	cout<<"\nPlaintext:";
	for(int j=0;ch[j]!='\0';j++)
	{
		cout<<ch[j];
	}
}


void main()
{
	clrscr();
	char a[s],rep; int key,n,l;
	cout<<"Program to encrypt or decrypt";
	do{
	cout<<"\nEnter '1' for Encryption and '2' for Decryption\n";
	cin>>n;
	/*cout<<"Enter the no. of test cases:";
	cin>>l;*/
	if(n==1)
	{
		cout<<"Enter the message to be encrypted:";
		gets(a);
		do{
		cout<<"Enter your encryption key:";
		cin>>key;
		if(key==0||key==26)
		{
			cout<<"There is no point in encryption !!";
			break;
		}
		else if(key>26)
		{
			cout<<"Your encryption is not based on alphabets only !!";
			break;
		}
		}while(key==0||key>26);
		cout<<"\nPlaintext:";
		for(int j=0;a[j]!='\0';j++)
		{
			cout<<a[j];
		}
		encrypt(a,key);
	}
	else if(n==2)
	{
		cout<<"Enter the message to be decrypted:";
		gets(a);
		do{
		cout<<"Enter your decryption key:";
		cin>>key;
		if(key==0)
		{
			cout<<"There is no point in encryption !!";
			break;
		}
		}while(key==0);
		cout<<"\nCiphertext:";
		for(int j=0;a[j]!='\0';j++)
		{
			cout<<a[j];
		}
		decrypt(a,key);
	}
	cout<<"\nDo you wanna try again(y/n)?:";
	cin>>rep;
	}while(rep=='Y'||rep=='y');
	getch();
}


