#include<iostream>
using namespace std;
template<class T>

class BinaryTreeNode
{
    public:
    T data;
    BinaryTreeNode<T> left;
    BinaryTreeNode<T> right;
    BinaryTreeNode(T data){
        this->data=data;
    }
};


int main(){
    BinaryTreeNode<int> root(1);
    BinaryTreeNode<int> rootLeft(2);
    BinaryTreeNode<int> rootRight(3);
    root.left=rootLeft;
    root.right=rootRight;


    BinaryTreeNode<int> twoRight=BinaryTreeNode<int>(4);
    BinaryTreeNode<int> threeLeft=BinaryTreeNode<int>(5);

    rootLeft.right=twoRight;
    rootRight.left=threeLeft;
    return 0;
}



