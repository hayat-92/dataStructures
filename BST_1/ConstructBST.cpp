#include <iostream>
#include<queue>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL){
        return;
    }

    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        BinaryTreeNode<int> *topNode=q.front();
        q.pop();
        // if(q)
        if(topNode==NULL && !q.empty()){
            q.push(NULL);
            cout<<endl;
        }else{
            if(topNode==NULL){
                continue;
            }
            cout<<topNode->data<<" ";
            if(topNode->left!=NULL){
                q.push(topNode->left);
            }

            if(topNode->right!=NULL){
                q.push(topNode->right);
            }
        }
    }
}

BinaryTreeNode<int>* helper(int *input, int n, int start, int end){
    if(start>end){
        return NULL;
    }
    if(start==end){
        BinaryTreeNode<int> *nod=new BinaryTreeNode<int>(input[start]);
        return nod;
    }
    int mid=(start+end)/2;
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(input[mid]);
    BinaryTreeNode<int> *LsubTree=helper(input, n, start, mid-1);
    BinaryTreeNode<int> *RsubTree=helper(input,n, mid+1, end);
    root->left=LsubTree;
    root->right=RsubTree;
    return root;
}

BinaryTreeNode<int> *constructTree(int *input, int n)
{
    // Write your code here
    return helper(input, n, 0, n-1);
}

int main()
{
    int input[]={1, 2, 3, 4, 5, 6, 7};
    BinaryTreeNode<int> *root=constructTree(input, 7);
    printLevelWise(root);

    return 0;
}