#include<iostream>
using namespace std;
int level= 0;

struct Node
{
	int data;
	Node *left;
	Node *right;
}*root,*parent;

void create_BST(int val)
{
	Node *nnode;
	nnode=new Node;
	nnode->data=val;
	nnode->left=NULL;
	nnode->right=NULL;
	
	if(root== NULL)
	{
		root=nnode;
		cout<<"\n\t\t\tRoot "<<root->data<<" of the BST is ready now !!"<<endl;
	}
	else
	{
		cout<<"The Root already exists !!"<<endl;
	}
}

void preOrder(struct Node *root)
{
	if(root != NULL)
	{
		cout<<"\t"<<root->data;
		preOrder(root->left);
		preOrder(root->right);
	}
}
void inOrder(struct Node *root)
{
	if(root!= NULL)
	{
		inOrder(root->left);
		cout<<"\t"<<root->data;
		inOrder(root->right);
	}
}
void postOrder(struct Node *root)
{
	if(root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout<<"\t"<<root->data;
	}	
								
}			
Node* create_Node(int val)
{
	Node *nnode;
	nnode= new Node;
	
	nnode->data=val;
	nnode->left=NULL;
	nnode->right=NULL;

	return nnode;
}
void insert(Node *current,Node *nnode)
{
	if(current != NULL)
	{
		if(nnode->data <= current->data)
		{
			if(current->left == NULL)
			{
				current->left= nnode;
				cout<<"\t\t\tNewnode "<<nnode->data<<" is inserted as Left Child of "<<current->data<<endl;
			}
			else
			{
				insert(current->left,nnode);
			}
		}
		else
		{
				if(current->right == NULL)
				{
					current->right= nnode;
					cout<<"\t\t\tNewnode "<<nnode->data<<" is inserted as Right Child of "<<current->data<<endl;
				}
				else
				{
					insert(current->right,nnode);
				}
			
		}
	}	
}	
void search(struct Node *root,int key)
{
	if(root != NULL)
	{
		if(key == root->data)
		{
					cout<<"\n\t KEY IS FOUND ON LEVEL "<<level;
		}
		else if(key < root->data)
		{
			level++;
			search(root->left,key);
		}
	
		else
		{
			level++;
			search(root->right,key);
		}
	}
	else
	{
		cout<<"\n\t KEY NOT FOUND !!"<<endl;
	}
}			
															




int main()
{
	cout<<"****************** BINARY SEARCH TREE AND ITS OPERATIONS ******************"<<endl;
	
	Node *nnode;
	int key;
	root= NULL;
	cout<<"\n\t 1.  CREATING A BST "<<endl;
	
	
	create_BST(25);
	cout<<"\n\t 2.  INSERTING NEW NODES IN THE BST "<<endl;
	nnode= create_Node(10);
	insert(root,nnode);
	
	nnode = create_Node(30);
	insert(root,nnode);
	
	nnode = create_Node(5);
	insert(root,nnode);
	
	nnode = create_Node(15);
	insert(root,nnode);
	
	nnode = create_Node(28);
	insert(root,nnode);
	
	nnode = create_Node(35);
	insert(root,nnode);
	cout<<"\n\t 3.DISPLAYING THE BST "<<endl;
	
	cout<<"\n\t\t\t\t :: PREORDER TRAVERAL :: "<<endl;
	cout<<"\t\t";
	preOrder(root);
	
	cout<<"\n\t\t\t\t :: INORDER TRAVERSAL :: "<<endl;
	cout<<"\t\t";
	inOrder(root);
	
	cout<<"\n\t\t\t\t :: POSTORDER TRAVERSAL :: "<<endl;
	cout<<"\t\t";
	postOrder(root);
	cout<<endl;
	cout<<"\n\t 4. SEARCH A KEY IN BST "<<endl;
	cout<<"\n\t\t Enter the key to search : ";
	cin>>key;
	search(root,key);
	return 0;
}	
	
