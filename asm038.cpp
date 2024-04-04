	
#include<iostream>
#include<cstring>
using namespace std;
int table_size=10;


struct hash
{
   char key[10];
   int val;
}HT1[10],HT2[10];


void init()
{
int i=0;
for(i=0;i<table_size;i++)
{
   strcpy(HT1[i].key,".....");
   HT1[i].val=0;
}
for(i=0;i<table_size;i++)
{
   strcpy(HT2[i].key,".....");
   HT2[i].val=0;
}
}
	int hash_func(char key[])
	{
	int i,index,sum=0;
	for(i=0;key[i]!='\0';i++)
	{
	  sum=sum+key[i];
	}
	index=sum%table_size;
	return index;
	}
		void linear_insert(char cname[],int tele)
		{
		 int i,index;
		 index=hash_func(cname);
			if(strcmp(HT1[index].key,".....")==0)
		 	{
			 	HT1[index].key,cname;
				HT1[index].val=tele;
			}
			else
			{
				while(strcmp(HT1[index].key,".....")!=0)
				{
					index=index+1%table_size;
				}
				HT1[index].key,cname;
				HT1[index].val=tele;
			}
		}

int main()
{
   init();
   char name[10];
   int num1;
   cin>>name;
   cin>>num1;
   linear_insert(name,num1);
   
 
 }
   
 
 



   
