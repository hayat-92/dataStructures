#include<iostream>
using namespace std;
template <class T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void printAtDepthK(BinaryTreeNode<int> *root, int k){
    if(root==NULL){
        return;
    }

    if(k==0){
        cout<<root->data<<endl;
        return;
    }
    printAtDepthK(root->left, k);
    printAtDepthK(root->right, k);


}
int main(){

return 0;
}