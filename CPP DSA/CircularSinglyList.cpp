/*
	name = harshwardhan tilekar
	roll no = 23
	title = Design and implement a menu driven program for expression 
			conversion from infix to postfix, postfix to prefix 
			expression and evaluation of postfix expression using stack.
*/


#include<iostream> 
#include<string>
#include<sstream> //stringstream class constructor for ssobj
#define MAX 100

using namespace std; 

class Stack
{ 
	public: 
	string stk[MAX]; 
	int top;
	Stack()
	{ 
		top = -1; 
	} 
	bool full() ;
	bool empty() ;
	void push(string s) ;
	string pop() ;
}; 
bool Stack :: full()
	{ 
	if(top == MAX-1)
	return true; 
	
	else
	return false; 
} 

bool Stack :: empty()
{ 
	if(top == -1)
	return true; 
	
	else
	return false;
} 

void Stack :: push(string s)
{ 
	if(full())
	{
		cout<<"Stack is full "; 
	}
	else
	{
		top++; 
		stk[top] = s; 
	}
} 
string Stack :: pop()
{ 
	if(empty())
	{ 
		cout<<"Stack is empty"; 
	} 
	else
	{ 
		string s = stk[top]; 
		top--; 
		return s; 
	}
}
class expression{ 
	public: 
	string postfix , infix; 
	Stack s; 
	
	bool is_operator(char x) ;
	int prece(string t) ;
	void infix_to_postfix(); 
	void postfix_to_prefix();
	void postfix_evaluation();
};
bool expression:: is_operator(char x)
{ 
	if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^' ) 
	{ 
		return true; 
	} 
	else 
	{ 
		return false; 
	}
} 

int expression:: prece(string t)
{
	if(t == "+" || t == "-")
	return 1; 
	
	else if( t == "*" || t == "/")
	return 2; 
	
	else if(t == "^")
	return 3; 
	
	else
	return 0; 
}

void expression::infix_to_postfix()
{ 
	cout<<"Enter the infix exp: "; 
	cin>>infix; 
	string postfix; 
	
	for(int i = 0 ; i < infix.length() ; i++)
	{ 
		if((infix[i] >= 'a' && infix[i]<='z') || (infix[i] >= 'A' && infix[i] <='Z'))
		postfix = postfix + infix[i];
		
		else if(infix[i] == '(') 
		s.push("("); 
		
		else if(infix[i] == ')')
		{
			while( s.top!= -1 && s.stk[s.top]!="(")
			{ 
				string t = s.stk[s.top]; 
				s.pop(); 
				
				postfix = postfix + t; 
			} 
			if(s.stk[s.top] == "(")
			{ 
				string t = s.stk[s.top]; 
				s.pop(); 
			}
		} 
		else
		{ 
			while(s.top != -1 && prece(string(1,infix[i])) <= prece(s.stk[s.top]))
			{ 
				string t = s.stk[s.top]; 
				s.pop(); 
				postfix = postfix + t; 
			} 
			s.push(string(1,infix[i])); 
		}
	}
	while( s.top != -1 )
	{ 
		string t = s.stk[s.top]; 
		s.pop(); 
		postfix = postfix + t;
	} 
	cout<<"Postfix exp : "<<postfix<<endl; 
}

void expression::postfix_to_prefix()
{ 
	cout<<"\nEnter the postfix exp: "; 
	cin>>postfix; 
	
	for (int i = 0;i<postfix.length();i++) 
	{ 
		if(is_operator(postfix[i])) 
		{ 
			string op1 = s.pop(); 
			string op2 = s.pop();
			string exp = postfix[i] + op2 + op1;
			s.push(exp); 
		} 
		else 
		{ 
			// s.push(postfix[i]);  //error detay so dusra ghetlay =>
			s.push(string(1,postfix[i])); 
		}
	} 
	string prefix = s.pop(); 
	cout<<"\nPrefix exp : "<<prefix<<endl; 
}

void expression::postfix_evaluation()
{
	string postfix; 
	
	cout<<"\nEnter the postfix exp : "; 
	cin>>postfix;
	
	for(int i=0;i<postfix.length();i++)
	{ 
		if(is_operator(postfix[i]))
		{ 
			int ans; 
			int t2,t1; 
			
			string t_2 = s.pop(); 
			string t_1 = s.pop(); 
			stringstream change_2(t_2); 
			stringstream change_1(t_1); 
			change_2>>t2; 
			change_1>>t1; 
			
			if(postfix[i]=='+')
			ans = t1+t2; 
			
			else if(postfix[i]=='-')
			ans = t1-t2; 
			
			else if(postfix[i]=='/')
			ans = t1/t2; 
			
			else if (postfix[i]=='*')
			ans = t1*t2; 
			
			else if(postfix[i]=='^')
			ans = t1^t2; 
			
			ostringstream ans_1; //?
			ans_1<<ans; 
			string ans__1 = ans_1.str(); 
			s.push(ans__1);
		}
		else if(isdigit(postfix[i]))
		{ 
			s.push(string(1,postfix[i])); 
		}
	} 
	string result = s.pop(); 
	cout<<"\nsolution for postfix evaluation : "<<result<<endl; 
}

int main()
{ 
	expression obj; 
	int choice;
	char c='y'; 
	
	while(c=='y')
	{
	
	cout<<"\n------------Select Operation-----------\n";
	cout<<"\n\t1)Infix to postfix\n\t2)Postfix to prefix\n\t3)Postfix evaluation\n\n";
	cout<<"---------------------------------------";
	cout<<"\n\nEnter your choice: ";
	cin>>choice; 
	
	switch(choice) 
	{
		case 1: 
		obj.infix_to_postfix(); 
		break; 
		
		case 2:
		obj.postfix_to_prefix(); 
		break; 
		
		case 3: 
		obj.postfix_evaluation(); 
		break; 
		
		case 4:
		cout<<"\nWrong Choice \n\n" ;	
	}
	cout<<"\npress y to continue : ";
	cin>>c;
	}
	return 0;
}

				//         OUTPUT           //
/*
			
			------------Select Operation-----------
			
			        1)Infix to postfix
			        2)Postfix to prefix
			        3)Postfix evaluation
			
			---------------------------------------
			
			Enter your choice: 1
			Enter the infix exp: a+b+c+d
			Postfix exp : ab+c+d+
			
			press y to continue : y
			
			------------Select Operation-----------
			
			        1)Infix to postfix
			        2)Postfix to prefix
			        3)Postfix evaluation
			
			---------------------------------------
			
			Enter your choice: 2
			
			Enter the postfix exp: ab*cd*+
			
			Prefix exp : +*ab*cd
			
			press y to continue : y
			
			------------Select Operation-----------
			
			        1)Infix to postfix
			        2)Postfix to prefix
			        3)Postfix evaluation
			
			---------------------------------------
			
			Enter your choice: 3
			
			Enter the postfix exp : 23*45*+
			
			solution for postfix evaluation : 26


*/
