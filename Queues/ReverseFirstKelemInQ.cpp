#include<iostream>
#include<queue>
#include<stack>

using namespace std;

queue<int> reverseKElements(queue<int> &input, int k) {
	// Write your code here
    if(input.empty() || k>input.size()){
        return input;
    }

    stack<int> s;
    for(int i=0; i<k; i++){
        s.push(input.front());
        input.pop();
    }

    for(int i=0; i<k; i++){
        input.push(s.top());
        s.pop();
    }

    for(int i=0; i<input.size()-k; i++){
        input.push(input.front());
        input.pop();
    }

    return input;
}

int main(){
    return 0;
}