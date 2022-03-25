#include<iostream>
#include<algorithm>
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

class BTnode{
    public:
    int height;
    bool isBalanced;
};

int height(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }

    return 1+max(height(root->left), height(root->right));
}

bool isBalancedBT(BinaryTreeNode<int> *root){
    if(root==NULL){
        return true;
    }

    int Lheight=height(root->left);
    int Rheight=height(root->right);

    if(abs(Lheight-Rheight)>1){
        return false;
    }
    bool isLeftBalanced=isBalancedBT(root->left);
    bool isRightBalanced=isBalancedBT(root->right);

    return isLeftBalanced && isRightBalanced;

}

BTnode* isBalancedOptimized(BinaryTreeNode<int> *root){
    if(root==NULL){
        BTnode *node=new BTnode();
        node->height=0;
        node->isBalanced=true;
        return node;
    }

    BTnode *Loutput=isBalancedOptimized(root->left);
    BTnode *Routput=isBalancedOptimized(root->right);
    bool isBal=true;
    int height=1+max(Loutput->height, Routput->height);

    if(abs((Loutput-Routput)>1)){
        isBal=false;
    }

    if(!Loutput->isBalanced || !Routput->isBalanced){
        isBal=false;
    }

    BTnode *ans=new BTnode();

    ans->height=height;
    ans->isBalanced=isBal;
    return ans;


    
}


int main(){

return 0;
}