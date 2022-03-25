#include <iostream>
#include<algorithm>
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

class BSTDeleteReturn{
    // private:
    public:
    BinaryTreeNode<int> *root;
    bool deleted;

    // public:
    BSTDeleteReturn(BinaryTreeNode<int> *root, bool deleted){
        this->root=root;
        this->deleted=deleted;
    }
};


class Custom_BST_Class
{
private:
    BinaryTreeNode<int> *root;
    int size;
    bool isPresentHelper(BinaryTreeNode<int> *root, int x){
        if(root==NULL){
            return false;
        }

        if(root->data==x){
            return true;
        }

        if(x<root->data){
            return isPresentHelper(root->left, x);
        }else{
            return isPresentHelper(root->right, x);
        }
    }
    void printTreeHelper(BinaryTreeNode<int> *root){
        if(root==NULL){
            return;
        }

        cout<<root->data<<":";
        if(root->left!=NULL){
            cout<<"L"<<root->left->data<<", ";
        }
        if(root->right!=NULL){
            cout<<"R"<<root->right->data;
        }
        cout<<endl;
        printTreeHelper(root->left);
        printTreeHelper(root->right);
    }

    BinaryTreeNode<int> *insertHelper(BinaryTreeNode<int> *root, int x){
        if(root==NULL){
            BinaryTreeNode<int>* newRoot=new BinaryTreeNode<int>(x);
            return newRoot;
        }

        if(x>=root->data){
            root->right=insertHelper(root->right, x);
        }else{
            root->left=insertHelper(root->left, x);
        }
        return root;
    }

    int minimum(BinaryTreeNode<int> *root){
        if(root==NULL){
            return INT_MAX;
        }
        int largestLeft=minimum(root->left);
        int largestRight=minimum(root->right);
        return min(root->data, min(largestLeft, largestRight));

    }

    BSTDeleteReturn* deleteDataHelper(BinaryTreeNode<int> *root, int x){
        if(root==NULL){
            return new BSTDeleteReturn(NULL, false);
        }

        if(root->data<x){
            BSTDeleteReturn *outputRight=deleteDataHelper(root->right, x);
            root->right=outputRight->root;
            outputRight->root=root;
            return outputRight;
        }

        if(root->data>x){
            BSTDeleteReturn *outputLeft=deleteDataHelper(root->left, x);
            root->left=outputLeft->root;
            outputLeft->root=root;
            return outputLeft;

        }

        if(root->left==NULL && root->right==NULL){
            return new BSTDeleteReturn(NULL, true);
        }

        if(root->left!=NULL && root->right==NULL){
            return new BSTDeleteReturn(root->left, true);
        }

        if(root->left==NULL && root->right!=NULL){
            return new BSTDeleteReturn(root->right, true);
        }

        int rightMax=minimum(root->right);
        root->data=rightMax;
        BSTDeleteReturn *outputRight=deleteDataHelper(root->right, rightMax);
        root->right=outputRight->root;
        return new BSTDeleteReturn(root, true);
    }



public:
    bool isPresent(int x)
    {
        return isPresentHelper(root, x);
    }

    void insert(int x)
    {
        root=insertHelper(root, x);
    }

    bool deleteData(int x)
    {
        BSTDeleteReturn *output=deleteDataHelper(root, x);
        root=output->root;
        if(output->deleted){
            size--;
        }
        return output->deleted;

    }

    void printTree()
    {
        printTreeHelper(root);
    }
};

int main()
{
    Custom_BST_Class *b=new Custom_BST_Class();
    b->insert(5);
    b->insert(2);
    b->insert(7);
    b->insert(1);
    b->insert(3);
    b->insert(6);
    b->insert(8);

    b->printTree();
    cout<<b->isPresent(5)<<endl;
    b->deleteData(5);
    cout<<b->isPresent(5)<<endl;
    b->printTree();

    return 0;
}