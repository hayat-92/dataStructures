#include <iostream>
#include<vector>
using namespace std;
template <typename T>
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

int numLeafNodes(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL){
        return 0;
    }
    if(root->numChildren()==0){
        return 1;
    }else{
        int count=0;
        for(int i=0; i<root->numChildren(); i++){
            
            count+=numLeafNodes(root->getChild(i));
        }
        return count;
    }
    

}
int main()
{

    return 0;
}