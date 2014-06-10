/**
 * @file dictionary.h
 */
#include <string>
#include <map>
#include <vector>


using namespace std;
#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

/**
 * Implements the dictionary ADT.
 *
 * The implementation is up to you, but you must complete all the given
 *  public functions. You will need to add some member variables and private
 *  helper functions.
 */
template <class K, class V>
class Dictionary
{
	 private:
    	struct Node
        {
            K key;
	    V value;
            Node* left;
            Node* right;
            Node(const K & newKey, const V & newValue)
				: key(newKey), value(newValue), left(NULL), right(NULL)	{ 	}
	    Node()
	    {
	    	left=NULL;
		right=NULL;
	    }
				
		
				
        };
        
    public:
        /**
         * Constructor: creates an empty dictionary.
         */
        Dictionary();

        /**
         * Inserts the given key, value pair into the dictionary.
         * If the key already exists, do nothing.
         *
         * @param key The key to be inserted.
         * @param value The value to be inserted.
         */
        void insert(const K & key, const V & value);

        /**
         * Removes the given key (and its associated data) from the
         *  dictionary.
         *
         * @param key The key to be removed.
         */
        void remove(const K & key);

        /**
         * Finds the value associated with a given key.
         *
         * @param key The key whose data we want to find.
         * @return The value associated with this key, or the default value
         *  (V()) if it was not found.
         */
        V find(const K & key);

        /**
         * Determines if the given key exists in the dictionary.
         *
         * @param key The key we want to find.
         * @return A boolean value indicating whether the key was found.
         */
        bool keyExists(const K & key);

        /**
         * Determines if the dictionary is empty. Should be O(1).
         *
         * @return A boolean value indicating whether the dictionary is
         *  empty.
         */
     
		void my_print(Node * node);
         	~Dictionary();
         	void clear(Node * subRoot);
         	void clear();
        	bool isEmpty() const;
		Node* copy(const Node* subRoot);
		const Dictionary & operator=(const Dictionary & rhs);
        	Dictionary(const Dictionary & other);
		private:
   
        	
       		Node * root;   
       		 map<K, V> check;
		void insert(Node* & node, const K & key, const V & value);
		void rotateRight(Node * & t);
		void rotateLeft(Node * & t) ; 
		void splay(Node * & node, K key);          
		void find(Node *  node, K key ,V & val);
		void remove_helper(Node * & node,const K & key);
		void doremove(Node * & node);
		void onechildRemove(Node * & node);
		void twoChildremove(Node * & node);
		Node * & IOP(Node * & node);
		Node * & rmc(Node * & node);
		

};

#include "dictionary.cpp"
#endif
