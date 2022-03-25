#include<iostream>
#include<stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    if(input.empty()){
        return;
    }

    int temp=input.top();
    input.pop();
    reverseStack(input, extra);
    while(!input.empty()){
        int val=input.top();
        input.pop();
        extra.push(val);
    }

    input.push(temp);
    while(!extra.empty()){
        int val=extra.top();
        extra.pop();
        input.push(val);
    }

}

int main(){
    return 0;
}