#include<iostream>
#include<stack>
#include<string>
using namespace std;


bool checkRedundantBrackets(string expression) {
	// Write your code here
    stack<int> s;
    for(int i=0; i<expression.size(); i++){
        if(expression[i]==')'){
            int count=0;
            while(s.top()!='('){
                count++;
                s.pop();
            }
            s.pop();
            if(count>1){
                return true;
            }
        }else{
            s.push(expression[i]);
        }
    }

    return false;
}

int main(){
    string str="a+(b)+c";
    cout<<checkRedundantBrackets(str)<<endl;
    return 0;
}