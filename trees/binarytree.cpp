/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

/**
 * @return The height of the binary tree. Recall that the height of a binary tree
 *  is just the length of the longest path from the root to a leaf, and that the
 *  height of an empty tree is -1.
 */
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
int BinaryTree<T>::height() const
{
	// Call recursive helper function on root
	return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node * subRoot) const
{
	// Base case
	if (subRoot == NULL)
        return -1;
	
	// Recursive definition
	return 1 + max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that node
 *  itself, and everything to the right of a node will be printed out after that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
	// Call recursive helper function on the root
	printLeftToRight(root);

	// Finish the line
	cout << endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node * subRoot) const
{
	// Base case - null node
	if (subRoot == NULL)
		return;

	// Print left subtree
	printLeftToRight(subRoot->left);

	// Print this node
	cout << subRoot->elem << ' ';

	// Print right subtree
	printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
template <typename T>
void BinaryTree<T>::mirror()
{
	// your code here
	reverse(root);
	
}
template <typename T>
typename BinaryTree<T>::Node * BinaryTree<T>::reverse(Node * node)

{
	
	if (node != NULL){
	// Recursive definition
	Node *temp=node->left;
	node->left=node->right;
	node->right=temp;
	reverse(node->left);
	reverse(node->right);
	}
	return node;
}

/**
 * @return True if an in-order traversal of the tree would produce a nondecreasing list
 *  output values, and false otherwise. This is also the criterion for a binary tree to be
 *  a binary search tree.
 */
bool val=true;
template <typename T>
bool BinaryTree<T>::isOrdered() const
{
    // your code here
	
	//inorder(root,root->elem,root->elem,1);
	val= check_bst(root,-1,1024);
	return val;
}
/*
template <typename T>
void BinaryTree<T>::inorder(const Node * node,T elem2, T max,int flag)	const
{	
	if(node!=NULL)
	{	
		if(node->left!=NULL)
		{
			if(node->left->elem > node->elem)
			{			
				val=false;
				//cout<<"val false for"<<node->left->elem<<"\n";
			}	
		}
		if(node->elem==max)
			flag=-1;
		if(flag==1 && node->elem>max)
		{
			val=false;
			//cout<<"val false for"<<node->elem<<"\n";
		}
		if(flag==-1 && node->elem<max)
		{
			val=false;
			//cout<<"val false for"<<node->elem<<"\n";		
		}		
		if(node->right!=NULL)
		{	if(node->right->elem < node->elem)
			{
				val=false;
				//cout<<"val false for"<<node->right->elem<<"\n";
			}
		}
		
		inorder(node->left,node->elem,max,flag);
		inorder(node->right,node->elem,max,flag);
	}
	//cout<<"val is"<<val<<"\n";
}
*/
template <typename T>
bool BinaryTree<T>:: check_bst(const Node * node, int min, int max) const
{
    if(node == NULL)
        return true;

    if(node->elem > min && node->elem < max)
    {
        if( check_bst(node->left, min, node->elem) && check_bst(node->right, node->elem, max) )
            return true;
    }
    //
    	return false;
}
/**
 * Prints out all the possible paths from the root of the tree to any leaf node.
 * That is, all sequences starting at the root node and continuing downwards, ending at a
 *  leaf node. Paths ending in a left node should be printed before paths ending in a node
 *  further to the right.
 */
template <typename T>
void BinaryTree<T>::printPaths() const
{   std::vector<T> myvector;

   findpaths(root,myvector);
}
template <typename T>
void BinaryTree<T>:: findpaths(const Node * node, vector<T> myvector) const //do not pass vector by reference to avoid removal of extra element
{	
		
	if(node!=NULL)
	{
		myvector.push_back(node->elem);	
		if(node->left==NULL && node->right==NULL)
		{
			cout<<"Path:";
			for (vector<int>:: iterator it=myvector.begin(); it<myvector.end(); it++)
   			 cout << ' ' << *it;
			cout<<"\n";	
		}	
		findpaths(node->left,myvector);
		findpaths(node->right,myvector);
	}
	
	
}
/**
 * Each node in a tree has a distance from the root node - the depth of that node,
 *  or the number of edges along the path from that node to the root. This function returns
 *  the sum of the distances of all nodes to the root node (the sum of the depths of all
 *  the nodes). Your solution should take O(n) time, where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{	std::vector<T> myvector;
    // your code hereFAILED:
	int sum=0;
	findSum(root,myvector, sum);
   	return sum;
}
template <typename T>
void BinaryTree<T>:: findSum(const Node * node, vector<T> myvector,int & sum) const
{
	if(node!=NULL)
	{
		if(node!=root)
		myvector.push_back(1);	
		for (vector<int>:: iterator it=myvector.begin(); it<myvector.end(); it++)
   		sum+=*it;
		//cout<<sum<<"\n";					
		findSum(node->left,myvector,sum);
		findSum(node->right,myvector,sum);
	}

}
