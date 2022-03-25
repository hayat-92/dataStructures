#include <iostream>
#include <algorithm>
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

class IsBSTReturn{
    public:
    int min;
    int max;
    bool isBST;
    IsBSTReturn(int min, int max, bool check){
        this->min=min;
        this->max=max;
        this->isBST=check;
    }

};


IsBSTReturn* isBST(BinaryTreeNode<int>* root){
    if(root==NULL){
        IsBSTReturn *ans=new IsBSTReturn(INT_MAX, INT_MIN, true);
    }

    IsBSTReturn *leftAns=isBST(root->left);
    IsBSTReturn *rightAns=isBST(root->right);
    int minx=min(root->data, min(leftAns->min, rightAns->min));
    int maxx=max(root->data, max(leftAns->max, rightAns->max));
    bool isBst=true;

    if(leftAns->max>=root->data){
        isBst=false;
    }

    if(rightAns->min<root->data){
        isBst=false;
    }

    if(!leftAns->isBST){
        isBst=false;
    }
    if(!rightAns->isBST){
        isBst=false;
    }

    IsBSTReturn *ans=new IsBSTReturn(minx, maxx, isBst);
    return ans;
}

int main()
{

    return 0;
}