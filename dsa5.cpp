Assignment 5

#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

class node{
	public:
	char data;
	node* left;
	node* right;
	
};

bool isoperator(char c){
	return(c=='+' || c=='-' || c=='*' || c=='/');
}

node* constructExpressionTreePostfix(string Postfix){
	stack<node*>s;
	for(int i=0;i<Postfix.size();i++){
		char c=Postfix[i];
		
		if(!isoperator(c)){
			node* operandnode=new node;
			operandnode->data=c;
			operandnode->left = operandnode->right = NULL;
			s.push(operandnode);
		}
		
		else{
			node* operandnode=new node;
			operandnode->data=c;
			
			operandnode->right=s.top();
			s.pop();
			
			operandnode->left=s.top();
			s.pop();
			
			s.push(operandnode);
			
		}
	}
	return s.top();
}

node* constructExpressionTreePrefix(string Prefix){
	stack<node*>s;
		for(int i=Prefix.size()-1;i>=0;i--){
			char c=Prefix[i];
			
			if(!isoperator(c)){
		        node* operandnode=new node;
	            operandnode->data=c;
			    operandnode->left = operandnode->right = NULL;
			    s.push(operandnode);
			}
			
			else{
				node* operandnode=new node;
				operandnode->data=c;
				
				operandnode->left=s.top();
				s.pop();
				
			    operandnode->right=s.top();
                s.pop();
                
                s.push(operandnode);

			}		
    }
    return s.top();
}

void preorderRecursive(node *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorderRecursive(root->left);
	preorderRecursive(root->right);
}

void inorderRecursive(node* root){
	if(root==NULL){
		return;
	}
	inorderRecursive(root->left);
	cout<<root->data<<" ";
	inorderRecursive(root->right);
}

void postorderRecursive(node* root){
	if(root==NULL){
		return;
	}
	postorderRecursive(root->left);
	postorderRecursive(root->right);
	cout<<root->data<<" ";
 }
 
void inorderNonrecursive(node* root){
 
	 stack<node*>st;
	 node*current=root;
	 while(current!=NULL || !st.empty()){
	 	while(current!=NULL){
	 		st.push(current);
	 		current=current->left;
		 }
		 current=st.top();
		 st.pop();
		 cout<<current->data<<" ";
		 current=current->right;
	 }
 }

void preorderNonrecursive(node* root){
 
	 stack<node*>st;
	 node*current=root;
	 while(current!=NULL || !st.empty()){
	 	while(current!=NULL){
		 cout<<current->data<<" ";
	 		st.push(current);
	 		current=current->left;
		 }
		 current=st.top();
		 st.pop();
		 current=current->right;
	 }
 }
 
void postorderNonrecursive(node* root){
 
	 stack<node*>st;
	 st.push(root);
	 stack<node*>result;
	 while(!st.empty()){
	 	node* current=st.top();
	 	st.pop();
	 	result.push(current);
	 	if(current->left){
	 		
	 		st.push(current->left);
		 }
		if(current->right){
			st.push(current->right);
		}
	 }
	 while(!result.empty()){
	 	cout<<result.top()->data<<" ";
	 	result.pop();
	 }
}
 
int main(){
	string postfix,prefix;
	cout<<"Enter postfix expression"<<endl;
	cin>>postfix;
	
	cout<<endl<<"Enter Prefix expression : "<<endl;
	cin>>prefix;
	
	node* root1 = constructExpressionTreePostfix(postfix);
	node* root2 = constructExpressionTreePrefix(prefix);
		
	char c;
	do{
    cout<<endl;
	cout<<"****MAINU******"<<endl;
	cout<<"1. Recursive traversals for expression tree from postfix expression "<<endl;
	cout<<"2. Non-Recursive traversals for expression tree from postfix expression "<<endl;
	cout<<"3. Recursive traversals for expression tree from prefix expression "<<endl;
	cout<<"4. Non-Recursive traversals for expression tree from prefix expression "<<endl;

    int choice;
    cout<<"Enter your choice :";
    cin>>choice;
    
    switch(choice){
    	case 1:
            cout<<endl;
        	cout<<"Recursive for postorder"<<endl;
            cout<<"Inoder traversal : ";
            inorderRecursive(root1);
            cout<<endl;
            
			cout<<"preorder Traversal : ";
         	preorderRecursive(root1);
            cout<<endl;
            
    		cout<<"Postorder Traversal : ";
         	postorderRecursive(root1);
         	cout<<endl;
         	
         	break;
        case 2:
        	cout<<endl;
        	cout<<"Nonrecursive for postorder"<<endl;
            cout<<"Inoder traversal : ";
            inorderNonrecursive(root1);
            cout<<endl;
            
			cout<<"preorder Traversal : ";
         	preorderNonrecursive(root1);
            cout<<endl;
            
    		cout<<"Postorder Traversal : ";
         	postorderNonrecursive(root1);
         	cout<<endl;
            break;
            
        case 3:
        	cout<<endl;
        	cout<<"Recursive for prefix"<<endl;
            cout<<"Inoder traversal : ";
            inorderRecursive(root2);
            cout<<endl;
            
			cout<<"preorder Traversal : ";
         	preorderRecursive(root2);
            cout<<endl;
            
    		cout<<"Postorder Traversal : ";
         	postorderRecursive(root2);
         	cout<<endl;
         	break;
         	
        case 4:
        	cout<<endl;
        	cout<<"Nonrecursive for prefix"<<endl;
            cout<<"Inoder traversal : ";
            inorderNonrecursive(root2);
            cout<<endl;
            
			cout<<"preorder Traversal : ";
         	preorderNonrecursive(root2);
            cout<<endl;
            
    		cout<<"Postorder Traversal : ";
         	postorderNonrecursive(root2);
         	cout<<endl;
         	
        default :
        	cout<<endl;
        	cout<<"Enter a valid choice";
}
    cout<<endl;
    cout<<"Do you want to continue(Y/N)?"<<endl;
    cin>>c;
}while(c=='y' || c=='Y');

return 0;
}

 
 


