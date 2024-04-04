
#include<iostream>

using namespace std;

int HT1[10];
int HT2[10];

int size = 10 ;

	void init()
	{
		for(int i=0;i<size;i++)
		{
				HT1[i] = 0 ;
				HT2[i] = 0 ;
		}
	}	
	
	
	void Display()
	{
		cout<<"\n\t\t  : : : : HASH TABLE 1: : : :"<<endl;
		cout<<"\t\t _______________________________"<<endl;
		cout<<"\t\t|\tINDEX\t|\tKEY\t|"<<endl;
		cout<<"\t\t|_______________|_______________|"<<endl;
		for(int i = 0 ; i < size ;i++)
		{
			cout<<"\t\t|\t"<<i<<"\t|\t"<<HT1[i]<<"\t|"<<endl;
		}
		cout<<"\t\t|_______________|_______________|"<<endl;
		
		cout<<"\n\t\t  : : : : HASH TABLE 2: : : :"<<endl;
		cout<<"\t\t _______________________________"<<endl;
		cout<<"\t\t|\tINDEX\t|\tKEY\t|"<<endl;
		cout<<"\t\t|_______________|_______________|"<<endl;
		for(int i = 0 ; i < size ;i++)
		{
			cout<<"\t\t|\t"<<i<<"\t|\t"<<HT2[i]<<"\t|"<<endl;
		}
		cout<<"\t\t|_______________|_______________|"<<endl;
	}
	
	
	void insert_SetA (int key)
	{
		 int index;
		 index = key % size; 
		 HT1[index] = key;
	}
	
	void insert_SetB(int key)
	{
		 int index;
		 index = key % size; 
		 HT2[index] = key;
	}
	void search_SetA(int key)
	{
		int index;
		
		index=key%size;
		
			if(HT1[index]==key)
				cout<<"\tKEY :"<<key<<" FOUND AT :"<<index<<endl;
			else
				cout<<"\tKey :"<<key<<" NOT FOUND....!!!"<<endl;
	}
	
	void search_SetB(int key)
	{
		int index;
		
		index=key%size;
		
			if(HT2[index]==key)
				cout<<"\tKEY :"<<key<<" FOUND AT :"<<index<<endl;
			else
				cout<<"\tKey :"<<key<<" NOT FOUND....!!!"<<endl;
	}
	
	int dup(int val)
	{
		int i,dupl = 0;
		
		for(i=0;i<size;i++)
		{
			if(HT1[i]==val)
				dupl = 1;
				return dupl;
				
		}
	}
	
	
	void unionAB()
		{
			int c[10];
			int i,j=0;
			
			for(i=0;i<size;i++)
				{
					if(HT1[i] != 0)
					{
						c[j]=Ht1[i];
						j++;
					}
				}
			for(i=0;i<size;i++)
				{
					if(HT2[i] != 0)
					{
						if(dup(HT2[i] == 0)
							{
								c[j]=HT2[i];
								j++;
							}
					}
				}
				
				cout<<"\tThe UNION OF A AND B IS :";
				for(i=0;i<j;i++)
					{
						cout<<c[i]<<",";
					}
		}
																
	
					
		
	
	
	
int main()
{
	init();
	Display();
	insert_SetA(11);
	insert_SetB(12);
	insert_SetA(9);
	insert_SetB(77);
	
	search_SetA(11);
	
	cout<<"After performing the operations ::"<<endl;
	Display();
	unionAB();
	
	
	return 0;
}		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
				
