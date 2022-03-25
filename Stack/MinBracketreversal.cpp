#include<iostream>
using namespace std;
#include<stack>

int countBracketReversals(string input) {
	// Write your code here
    stack<char> s;
    for(int i=0; i<input.size(); i++){
        if(input[i]=='{'){
            s.push(input[i]);
        }else{
            if(s.empty()){
                s.push(input[i]);
            }else if(s.top()=='{'){
                s.pop();
            }else{
                s.push(input[i]);
            }
        }
    }

    int count=0;

    while(!s.empty()){
        char c1=s.top();
        s.pop();
        if(s.empty()){
            return -1;
        }
        char c2=s.top();
        s.pop();
        if(c1==c2){
            count++;
        }else{
            count+=2;
        }
    }

    

    return count;
}

int main(){

    string str="{{{{}}";
    cout<<countBracketReversals(str)<<endl;
    return 0;
}