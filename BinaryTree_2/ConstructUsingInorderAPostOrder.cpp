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

BinaryTreeNode<int>* helper(int *postorder, int postSt, int postEd, int* inorder, int InSt, int InEd){
    if(postSt>postEd || InSt> InEd){
        return NULL;
    }

    int rootElem=postorder[postEd];
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootElem);
    int index=0;
    for(int i=InSt; i<=InEd; i++){
        if(inorder[i]==rootElem){
            index=i;
            break;
        }
    }

    root->left=helper(postorder, postSt, postSt+(index-InSt)-1, inorder, InSt, index-1);
    root->right=helper(postorder, postSt+(index-InSt), postEd-1,inorder, index+1, InEd);
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    return helper(postorder, 0, postLength-1, inorder, 0, inLength-1);
}
int main(){

return 0;
}