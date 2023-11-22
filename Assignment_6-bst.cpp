#include<iostream>
#include<stack>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int data;
    Node(int data)
    {
        data=data;
        left=NULL;
        right=NULL;
    }
};
Node* search(int x, Node* T)
{
  if(T != NULL)
  {
      if(T->data == x)
          return T;
      else if(T->data > x)
          return search(x, T->left);
      else if(T->data < x)
          return search(x, T->right);
  }
  else
      {
        T=NULL;
        return T;
      }
     
}
void inOrderRec(Node * root)  //LNR Recursive in order traversal
{

    if(root==NULL)
        return;
    else
    {
        inOrderRec(root->left);
        cout<<root->data<<" ";
        inOrderRec(root->right);
    }

}
void insert(Node* root, Node* n)
{  
    Node* T=root;
    while(true)
    {
        if(n->data<T->data )
        {
            if(T->left==NULL)
            {
                T->left=n;
                return;
            }
            else
            {
                T=T->left;
            }
        }
        else if(n->data >T->data )
        {
            if(T->right==NULL)
            {
                T->right=n;
                return;
            }
            else
            {
                T=T->right;
            }
        }
        else
        {
        		cout<<"Duplicate data ..."<<endl;
        		break;
        }
    }
     
}
void mirror( Node* root)
{
    if (root == NULL)
        return;
    else {
         Node* temp;
 
        
        mirror(root->left);
        mirror(root->right);
 
        
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

void deletenode(int n,Node* root)
{
	Node* temp = root;
	Node* pre;
	while(temp != NULL)
	{
		if(temp -> data == n)
		{
			//cout<<"Element found "<<endl;
			if(temp -> left == NULL && temp -> right ==NULL)
			{
				if(pre->data > temp->data)
				{
					pre->left = NULL;
					delete temp;
					return;
				}
				else
				{
					pre->right = NULL;
					delete temp;
					return;
				}
			}
			else if(temp -> left == NULL || temp -> right ==NULL)
			{
				if(pre->data > temp->data)
				{
					if(temp->left != NULL)
					{
						pre->left = temp->left;
						delete temp;
						return;
					}
					else
					{
						pre->left = temp->right;
						delete temp;
						return;
					}
					
				}
				else
				{
					if(temp->left != NULL)
					{
						pre->right = temp->left;
						delete temp;
						return;
					}
					else
					{
						pre->right = temp->right;
						delete temp;
						return;
					}
				}
			}
			else
			{
				Node* t =temp;
				Node* tpre;
				t = t->left;
				if(t -> right ==NULL)
				{
					if(pre->data > temp->data)
					{
						pre->left = t;
						t->right = temp->right;
						delete temp;
						return;
					}
					else
					{
						pre->right = t;
						t->right = temp->right;
						delete temp;
						return;
					}
				}
				while(t->right !=NULL)
				{
					tpre = t;
					t = t->right;
				}
				tpre->right = t->left;
				t->right = temp->right;
				t->left = temp->left;
				if(pre->data > temp->data)
				{
					pre->left = t;
					delete temp;
					return;
				}
				else
				{
					pre->right = t;
					delete temp;
					return;
				}
			}
		}
		else if(temp -> data < n)
		{
			pre = temp;
			temp = temp ->right;
			if(temp == NULL)
			{
				cout<<"Element not found :"<<endl;
				return;
			}
		}
		else
		{
			pre = temp;
			temp = temp ->left;
			if(temp == NULL)
			{
				cout<<"Element not found :"<<endl;
				return;
			}
		}
	}
}


void menu()
{
	cout<<"Enter your choice : \n1.insert \n2.search \n3.Display\n4.Mirror Tree \n5.Delete\n6.Exit\n";
}
int main()
{
  
    
    
    cout<<"Enter the root of the tree : "<<endl;
    int r;
    cin>>r;
    Node* root=new Node(r);
    while(true)
    {
		 menu();
		 int q,z;
		 Node* temp;
		 cin>>q;
		 switch(q)
		 {
		 	case 1:
		 		cout<<"Enter data for new node : "<<endl;
		 		cin>>z;
		 		temp=new Node(z);
		 		insert(root,temp);
		 		break;
		 	case 2:
		 		cout<<"Enter key for search : "<<endl;
		 		cin>>z;
		 		if(search(z,root)==NULL)
		 		{
		 			cout<<"Element did not find."<<endl;
		 		}
		 		else
		 		{
		 			cout<<"key found : "<<search(z,root)->data<<endl;
		 		}
		 		break;
		 	case 3:
		 		inOrderRec(root);
		 		cout<<endl;
		 		break;
		 	case 4:
		 		 temp=root;
		 		mirror(temp);
		 		inOrderRec(temp);
		 		break;
		 	case 5:
		 		cout<<"Enter element to delete : "<<endl;
		 		cin>>z;
		 		
		 		deletenode(z,root);
		 		break;
		 	case 6:
				return 0;
				break;		 		
		 }
    }
    return 0;
}
