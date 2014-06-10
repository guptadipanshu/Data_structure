#include "dictionary.h"
#include<iostream>
using namespace std;
template <class K, class V>
Dictionary<K, V>::Dictionary()
{
	root=NULL;
}

template <class K, class V>
void Dictionary<K, V>::insert(const K & key, const V & value)
{
	
	if(keyExists(key))
		return ;
	else	
		insert(root,key,value);
		check.insert(make_pair(key, value));
		my_print(root);
		//cout<<"\n";
}


template <class K, class V>
void Dictionary<K, V>::remove(const K & key)
{
	if(keyExists(key))
	{
		//cout<<"remove key "<<key<<"\t";
		//while(root->key!=key)
		splay(root,key);
		
		
		
		//my_print(root);
		remove_helper(root,key);
		check.erase(key);
		
		//cout<<"\nafter do remove"<<"\n";
		//my_print(root);
		//cout<<"\n";
	}	
}

template <class K, class V>
V Dictionary<K, V>::find(const K & key)
{
	//cout<<"root "<<root->key<<"\n";
	V k;
	if(root!=NULL && keyExists(key))
   	{ 
   		//my_print(root);
   		//cout<<"\n";
   		splay(root,key);
   		find(root,key,k);
		return k;
	}
	else 
	 return V();
}

template <class K, class V>
bool Dictionary<K, V>::keyExists(const K & key)
{
 	if(check.find(key)==check.end())
    	return false;
    	else
    	return true;
}

template <class K, class V>
bool Dictionary<K, V>::isEmpty() const
{
    if(check.size()>0)
    return false;
    else
    return true;
}




/*********************PRIVATE FUNCTIONS**************************************************************************/

template <class K, class V>
void Dictionary<K, V>::my_print(Node * node)
{
	if(node!=NULL)
	{
		
		//cout<<" "<<node->key<<"\t";
		my_print(node->left);
		my_print(node->right);
		
	}	
}


template <class K, class V>
void Dictionary<K, V>::remove_helper(Node * & node,const K & key)
{
	if(node!=NULL)
	{
		if(node->key==key)
		{
			doremove(node);
			return;
			//cout<<"after splay on remove "<<node->key<<"\n";
		}
		remove_helper(node->left,key);
		remove_helper(node->right,key);	
	}
}

template <class K, class V>
void Dictionary<K, V>::doremove(Node * & node)
{
		if(node->left==NULL && node->right==NULL)
		{
			//cout<<"delete "<<node->key<<"\n";
			delete node;
			node=NULL;
		}
		else if(node->left!=NULL && node->right!=NULL)	
		{
			twoChildremove(node);
		}
		else
		{
			onechildRemove(node);
		}
}			

template <class K, class V>
void Dictionary<K, V>::onechildRemove(Node * & node)
{
	Node * temp=node;
				
	if(node->left==NULL)
	{
		node=node->right;
	}
	else if(node->right==NULL)
	{
		node=node->left;
		//cout<<node->key<<"\n";
	}
	delete temp;
			
}

template <class K, class V>
void Dictionary<K, V>::twoChildremove(Node * & node)
{
	Node * & iop=IOP(node);
	node->key=iop->key;
	node->value=iop->value;
	//cout<<"node lefts "<<node->left->key<<"\n";
	doremove(iop);
}

template <class K, class V>
typename Dictionary<K, V>::Node * & Dictionary<K, V>::IOP(Node * & node)
{
	return rmc(node->left);
}


template <class K, class V>
typename Dictionary<K, V>::Node * & Dictionary<K, V>::rmc(Node * & node)
{
	if(node->right==NULL)
		return node;
	else
	return	rmc(node->right);	
}





template <class K, class V>
void Dictionary<K, V>::rotateLeft(Node * & t)
{
	
    Node * pre = t->right;
    	if(pre!=NULL)
    	{
		t->right = pre->left;
		pre->left = t;
		t = pre;
	}
    
}



template <class K, class V>
void Dictionary<K, V>::rotateRight(Node * & t)
{
	
    Node * pre=t->left;
    if(pre!=NULL)
    {
    	t->left=pre->right;
    	pre->right=t;    
 	t = pre;
    }
}

template <class K, class V>
void Dictionary<K, V>::splay(Node * & node, K key)
{
	Node N, *l, *r, *y;
	if (node == NULL) 
    	 	return ;
    	N.left = N.right = NULL;
    	l = r = &N;
    	while(1)
    	{
    		if (key < node->key) 
    		{
			if (node->left == NULL) 
				break;
			if (key < node->left->key) 
			{
				rotateRight(node);
				if(node->left==NULL)
					break;
			}
			r->left = node;                               // link right /
			r = node;
	        	node = node->left; 
	    	}
	    	else if (key> node->key)
	    	{
	    		if (node->right == NULL) 
				break;
			if (key < node->right->key) 
			{
				rotateLeft(node);
				if(node->right==NULL)
					break;
			}
			l->right = node;                               // link left /
			l = node;
	        	node = node->right;
	    	}
	    	else
	    		break;
	    		
	    	
    	}
    l->right = node->left;                                // assemble /
    r->left = node->right;
    node->left = N.right;
    node->right = N.left;
   	
   	
}

template <class K, class V>
void  Dictionary<K, V>::insert(Node* & node, const K & key, const V & value)
{
	if(node==NULL)// our subtree is empty
	{
		node = new Node(key, value);
		return;
	}
	Node * temp=new Node(key,value);
	splay(node,key);
	if(key< node->key)
	{
		temp->left=node->left;
		temp->right=node;
		node->left=NULL;
		node=temp;
	}
	else if(key > node->key)
	{
		temp->right=node->right;
		temp->left=node;
		node->right=NULL;
		node=temp;	
	}
	temp=NULL;
}

template <class K, class V>
void Dictionary<K, V>::find(Node *  node, K key,V & val)
{
	if(node!=NULL)
	{	//cout<<"reached "<<node->key<<"\n";
		if(node->key==key)
		{
			//cout<<"i"<<node->value<<"\t";
			val= node->value;
			return;
		}	
		 find(node->left,key,val);
		 find(node->right,key,val);
	}
	
	
}



/*=======================BIG THREE==========================================*/
template <class K, class V>
Dictionary<K, V>::~Dictionary()
{
	clear(root);
}


template <class K, class V>
void Dictionary<K, V>::clear()
{
	clear(root);
	root = NULL;
}


template <class K, class V>
Dictionary<K, V>::Dictionary(const Dictionary & other)
{
	root=copy(other.root);
	check=other.check;
}
template <class K, class V>
void Dictionary<K, V>::clear(Node * subRoot)
{
	//cout<<"delete called\n";
	if (subRoot == NULL)
		return;

	clear(subRoot->left);
	clear(subRoot->right);
	delete subRoot;
}


template <class K, class V>
const Dictionary<K, V> & Dictionary<K, V>::operator=(const Dictionary & rhs)
{
	//cout<<"why";
	if (this != &rhs)
	{
		clear(root);
		root = copy(rhs.root);
		check=rhs.check;
		
	}
	return *this;
}

template <class K, class V>
typename Dictionary<K, V>::Node* Dictionary<K, V>::copy(const Node * subRoot)
{
	if (subRoot == NULL)
	{ 
		//cout<<"did not copy";
		return NULL;

	}
	// Copy this node and its children    
	Node * newNode = new Node(subRoot->key, subRoot->value);
	//cout<<"copy"<<subRoot->key;
	newNode->left  = copy(subRoot->left );
	newNode->right = copy(subRoot->right);
	return newNode;
}




