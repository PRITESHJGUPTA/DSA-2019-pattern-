/*
	   NAME :: PRITESH GUPTA
	ROLL NO :: 38
                                Practical No: 07
	Title: A C++ Program to check whether the given Graph is Connected Graph or Not.
	Input : A Graph (04 Cities/Nodes and 05 Edges)
	Outputs:
		a) Represent Graph using Adjacency Matrix
		b) Represent Graph using Adjacency List
		c) To check whether the given Graph is Connected Graph or Not.
*/

#include<iostream>
using namespace std;

int adjmtx[4][4];
int row=4;
int col=4;	

struct Node
{
	char data;
	Node *down,*next;
}*head;
	
char vertex(int val)
{
	if(val == 0)
		return 'A';
	if(val == 1)
		return 'B';
	if(val == 2)
		return 'C';
	else
		return 'D';
}

void create()
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<"\n Is Edge from vertex "<<vertex(i)<<" to "<<vertex(j)<<" ? : ";
			cin>>adjmtx[i][j];
		}
	}
}

void display()
{
	for(int i=0;i<row;i++)
	{
		cout<<"\n";
		for(int j=0;j<col;j++)
		{
			cout<<"\t"<<adjmtx[i][j];
		}
	}
}
void create_List()
{
	Node *nnode,*move,*p;
	int nodes;
	int edges;
	cout<<"\n\n How many Vertices in Graph :: ";
	cin>>nodes;
	
	for(int i=0;i<nodes;i++)
	{
		nnode = new Node;
		nnode->data = vertex(i);
		nnode->down = NULL;
		nnode->next= NULL;
		if(head == NULL)
		{
			head = nnode;
			move = head;
		}
		else
		{	
			move->down = nnode;
			move= move->down;
		}
	}
	move=head;
	p=head;
	while(move != NULL)
	{
		cout<<"How Many Adjacent vetices for "<<move->data<<" :: ";
		cin>>edges;
		
		for(int i=0;i<edges;i++)
		{
			nnode = new Node;
			cout<<"\n\t Enter an Adjacent Vertex :: ";
			cin>>nnode->data;
			nnode->down = NULL;
			nnode->next = NULL;
			
			p->next = nnode;
			p=p->next;
		}
		move =move->down;
		p=move;
	}
}
void display_List()
{
	Node *move,*p;
	cout<<"\n\t ::HEAD::";
	move= head;
	while(move != NULL)
	{
		cout<<"\n\t | "<<move->data<<" |--> ";
		p=move->next;
		while(p != NULL)
		{
			cout<<p->data<<" --> ";
			p = p->next;
		}
	cout<<"NULL";
	move = move->down;
	p = move;
	}
}			
void check()
{
	int i;
	int nonzero;
	i=0;
	do
	{
		nonzero = 0;
		for(int j=0; j<col; j++)
		{
			if(adjmtx[i][j] != 0)
			nonzero++;
		}
		i++;
	}
	while(i < row && nonzero >= 1);
	if(i == row)
		cout<<"\n\n\t The Given Graph is Connected Graph";
	else
		cout<<"\n\n\t The Given Graph is Not Connected Graph";
}
int main()
{
	cout<<"*************************ASSIGNMENT GROUP C-2*************************"<<endl;
	cout<<"\n\t 1.Representation of Graph using Adjacency Matrix"<<endl;
	create();
	cout<<"\n\t  :: Adjacency Matrix ::";
	display();
	cout<<endl;
	cout<<"\n\t 2.Representation of graph using Adjacency Matrix"<<endl;
	create_List();
	cout<<"\n\t  :: Adjacency List ::";
	display_List();
	cout<<endl;
	cout<<"\n\t 3.Checking whether the Graph is Connected or not"<<endl;
	check();
	cout<<endl;
	return 0;
}	
	
	
	
	
	
	
