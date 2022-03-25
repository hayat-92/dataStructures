#include <iostream>
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

BinaryTreeNode<int> *helper(int *preorder, int pst, int pend, int *inorder, int Ist, int Iend)
{
    if(pst>pend || Ist>Iend){
        return NULL;
    }

    int elem=preorder[pst];
    BinaryTreeNode<int> *node=new BinaryTreeNode<int>(elem);
    int index=0;
    for(int i=Ist; i<=Iend; i++){
        if(inorder[i]==elem){
            index=i;
            break;
        }
    }

    BinaryTreeNode<int> *Ltree=helper(preorder, pst+1, pst+(index-Ist),inorder, Ist, index-1);
    BinaryTreeNode<int> *Rtree=helper(preorder, pst+(index-Ist)+1, pend, inorder, index+1, Iend);
    node->left=Ltree;
    node->right=Rtree;
    return node;
}

BinaryTreeNode<int> *buildTree(int *preorder, int preLength, int *inorder, int inLength)
{
    // Write your code here
    return helper(preorder, 0, preLength - 1, inorder, 0, inLength - 1);
}
int main()
{

    return 0;
}