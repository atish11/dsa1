




#include<iostream>
#include "Third.h"
#include<string.h>

void postfix(char infix[],int k);

void infix(char main[])
{
	cout<<"Infix = "<<main;
}

void prefix(char prefix[])
{
char prefix1[50];
int i,j;  

int a=strlen(prefix)-1;
for(i=0,j=a;i<a,j>=0;i++,j--)
{
	prefix1[j] = prefix[i];
}
postfix(prefix1,0);
}


int prece(char x)
 {
	if(x=='(')
	{
	    return(0);
	}
	else if(x=='/' || x=='*')
	{
		return(2);
	}
	else if(x=='+' || x=='-')
	{
		return(1);
}
	else
	{
		return(-1);
	}
 }

 void evapostfix(char str[],int key,int a)
 {
 
			if(key == 1)
			{
			cout<<"\nPostfix = ";
			for(int i=0;i<=a-1;i++)
			{
				cout<<str[i];
			}
			}
			else if(key == 0)
			{
			cout<<"\nPrefix = ";
			for(int i=a-1;i>=0;i--)
			{
				cout<<str[i];
			}
			}
 }

		void postfix(char infix[],int k)
		{
			char token;
			char x;
			work st;
			int j=0;
			char postfix[30];



			for(int i=0;i<=strlen(infix)-1;i++)
			{

				token = infix[i];

				if((token>='a' && token<='z')||(token>='A' && token<='Z'))
				{
					postfix[j]=token;
				j++;
				}
				else if(token == '(')
				{
					st.push('(');
				}
				else if(token == ')')
				{
				while((x=st.pop())!='(')
					{
						postfix[j]=x;
						j++;
					}
					}

				else
				{
					x=st.pop1();

				int a = prece(token);
				int b = prece(x);
				while(a <= b && st.empty() == 1)
				{
					x=st.pop();
					postfix[j]=x;
					j++;
				}
				st.push(token);
			      }


		postfix[j] = '\0';
}
			while(st.empty() == 1)
		{
			x= st.pop();
			postfix[j]=x;
			j++;
		}
		int a = strlen(infix);
	       evapostfix(postfix,k,a);
	}

int main()
{


	int choice;
	char exp[50];
	cout<<"Enter the expression to convert = ";
	cin>>exp;

 do{
cout<<"\n\n ===============MENU============="<<endl;
 cout<<"1.Print Infix"<<endl;
cout<<"2.Convert infix expression to prefix expression. "<<endl;
 cout<<"3.Convert infix expression to postfix expression. "<<endl;
 cout<<"4.Exit program."<<endl;

 cout<<"\nEnter your choice = ";
 cin>>choice;

 switch(choice)
 {
 case 1:
	{
	infix(exp);
	break;
	}
 case 2:
	{
	prefix(exp);
	break;
	}
 case 3:
	{
	postfix(exp,1);
	break;
	}
 case 4:
       {
       break;
       }
}
}while(choice != 4);

return 0;
}

