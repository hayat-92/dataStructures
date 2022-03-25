#include<iostream>
#include<string>
#include<stack>
using namespace std;


bool isBalanced(string expression) 
{
    stack<char> s;
    for(int i=0; i<expression.size(); i++){
        if(expression[i]=='('){
            s.push(expression[i]);
        }
        if(expression[i]==')'){
            if(!s.empty() && s.top()=='('){
                s.pop();
            }else{
                return false;
            }
        }
    }

    return s.empty();

}

int main(){
    string str="()()(()";
    cout<<isBalanced(str)<<endl;
    return 0;
}