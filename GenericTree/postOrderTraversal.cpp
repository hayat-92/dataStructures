#include <iostream>
#include<vector>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

void printPostOrder(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL){
        return;
    }

    for(int i=0; i<root->children.size(); i++){
        printPostOrder(root->children.at(i));
    }

    cout<<root->data<<" ";
}
int main()
{

    return 0;
}