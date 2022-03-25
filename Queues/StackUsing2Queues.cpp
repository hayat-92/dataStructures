#include<iostream>
#include<queue>
using namespace std;

class Stack {
	// Define the data members
    queue<int> *q1;
    queue<int> *q2;
   public:
    Stack() {
        // Implement the Constructor
        q1=new queue<int>();
        q2=new queue<int>();

    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return q1->size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return q1->empty();
    }

    void push(int element) {
        // Implement the push() function
        q1->push(element);
    }

    int pop() {
        // Implement the pop() function
        if(isEmpty()){
            return -1;
        }

        while(q1->size()>1){
            q2->push(q1->front());
            q1->pop();
        }

        int ans=q1->front();
        q1->pop();
        queue<int> *temp=q1;
        q1=q2;
        q2=temp;
        return ans;
    }

    int top() {
        // Implement the top() function
        if(isEmpty()){
            return -1;
        }

        while(q1->size()>1){
            q2->push(q1->front());
            q1->pop();
        }

        int ans=q1->front();
        q1->pop();
        q2->push(ans);

        queue<int> *temp=q1;
        q1=q2;
        q2=temp;
        return ans;
        

    }
};