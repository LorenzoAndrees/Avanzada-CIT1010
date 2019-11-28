#include <iostream>
#include <stack>

#define EXIT_PROGRAM return 0;

using namespace std;

bool esBalanceado(string s){
	stack <char> p;
	for(int i= 0; i < s.length(); i++){
		
		if(s[i] == '(' || s[i] == '[' || s[i] == '{' ){
			p.push(s[i]);
		}
		
		else if(s[i] == ')' ){
			if(!p.empty() && p.top() == '('){
				p.pop();
			}
			else{
				return false;
			}
		}
		
		else if(s[i] == ']' ){
			if(!p.empty() && p.top() == '['){
				p.pop();
			}
			else{
				return false;
			}
		}
		
		else if(s[i] == '}' ){
			if(!p.empty() && p.top() == '{'){
				p.pop();
			}
			else{
				return false;
			}
		}
		
	}
	return p.empty();
}


int main() {
	cout << esBalanceado("()") << endl;
	cout << esBalanceado("(]") << endl;
	cout << esBalanceado("((") << endl;
	cout << esBalanceado("({[]}[])") << endl;
	cout << esBalanceado("{{{{}}") << endl;
	EXIT_PROGRAM;
}

