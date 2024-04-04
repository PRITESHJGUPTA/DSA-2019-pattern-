#include<iostream>
using namespace std;

char postfix[10];

struct Node
{
	char data;
	Node *left;
	Node *right;
}*root;

Node* stack[5];
int top= -1;

void push(Node* nnode)
{
	top++;
	stack[top]= nnode;
}

Node* pop()
{
	Node *temp;
	temp = stack[top];
	top--;
	return temp;
	
}

Node* create(char val)
{
	Node *nnode;
	
	nnode = new Node;
	
	nnode->data= val;
	nnode->left= NULL;
	nnode->right= NULL;
	
	return nnode;
}

void create_Extree()
{
	int i;
	Node *nnode;
	
	cout<<"\n\t ENTER THE POSTFIX EXPRESSION :: ";
	cin>>postfix;
	
	for(i=0;postfix[i] != '\0';i++)
	{
		if(postfix[i] == 'a' || postfix[i] == 'b' || postfix[i] == 'c' || postfix[i] == 'd')
		{
			nnode = create(postfix[i]);
			push(nnode);
		}
		if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
		{
			nnode =create(postfix[i]);
			nnode->right =pop();
			nnode->left = pop();
			push(nnode);
		}
	}
	if(root == NULL)
	{
		root =pop();
		cout<<"\n\tEXPRESSSION TREE IS READY NOW !!";
	}
}
void preOrder(Node *root)
{
	if(root != NULL)
	{
		cout<<"\t"<<root->data;
		preOrder(root->left);
		preOrder(root->right);
	}
}
void inOrder(Node *root)
{
	if(root != NULL)
	{
		
		inOrder(root->left);
		cout<<"\t"<<root->data;
		inOrder(root->right);
	}
}
void postOrder(Node *root)
{
	if(root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout<<"\t"<<root->data;
	}
}
int main()
{
	cout<<"********** A C++ PROGRAM TO CREATE AND DISPLAY AN EXPRESSION TREE **********"<<endl;
	root=NULL;
	create_Extree();
	 cout<<"\n\n\t\t PREORDER TRAVERSAL :: ";
	 preOrder(root);

	 cout<<"\n\n\t\t INORDER TRAVERSAL :: ";
	 inOrder(root);

 	 cout<<"\n\n\t\t POSTORDER TRAVVERSAL :: ";
 	 postOrder(root);
 	 cout<<endl;
 	 return 0;
	
}									
