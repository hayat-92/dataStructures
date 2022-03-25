#include <iostream>
using namespace std;

template<typename T>
class TreeNode {
	TreeNode<T>** children;
	int childCount;

	public:
	T data;

	TreeNode(T data);	// Constructor
	int numChildren();
	void addChild(TreeNode<T>* child);
	TreeNode<T>* getChild(int index);
	void setChild(int index, TreeNode<T>* child);
};

void helper(TreeNode<int>* root, int k){
    if(root==NULL){
        return;
    }

    root->data=k;
    for(int i=0; i<root->numChildren(); i++){
        helper(root->getChild(i), k+1);
    }
}

void replaceWithDepthValue(TreeNode<int> *root){    
	// Write your code here
    helper(root, 0);
}
int main()
{

    return 0;
}