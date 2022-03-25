#include <iostream>
#include<utility>
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

TreeNode<int> *maxNode=new TreeNode<int>(INT_MIN);
TreeNode<int> *minNode=new TreeNode<int>(INT_MIN);

void helper(TreeNode<int> *root){
    if(root==NULL){
        return;
    }

    
    if(root->data>maxNode->data){
        minNode=maxNode;
        maxNode=root;
    }else if(root->data>minNode->data && root->data<maxNode->data){
        minNode=root;
    }


    for(int i=0; i<root->numChildren(); i++){
        helper(root->getChild(i));
        
    }
}

TreeNode <int>* secondLargest(TreeNode<int> *root) {
    // Write your code here
    helper(root);
    return minNode;

}
int main()
{

    return 0;
}