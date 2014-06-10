#include "iostream"
using namespace std;
/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 *
 * @author Chase Geigle
 * @date (created) Fall 2011
 * @date (modified) Spring 2012, Fall 2012
 *
 * @author Jack Toole
 * @date (modified) Fall 2011
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
template <class T>
List<T>::~List()
{
    /// @todo Graded in MP3.1
	clear();
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear()
{
    /// @todo Graded in MP3.1
if(length==0)
	return ;
else
	{
		ListNode *temp=head;
		while(head!=tail)
		{
			temp=temp->next;
			head->prev=NULL;
			head->next=NULL;
			delete head;
			head=temp;
		}
		delete head;

	}
	
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const & ndata)
{
    /// @todo Graded in MP3.1
ListNode * temp= new ListNode(ndata);
//temp->data=ndata;
if(head==NULL)
	{
		head=temp;
		tail=head;
		length++;
		head->prev=NULL;
		head->next=NULL;
			
	}
else
	{
				
		temp->next=head;
		head->prev=temp;
		head=temp;
		length++;
	}
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack( const T & ndata )
{
    /// @todo Graded in MP3.1
ListNode * temp= new ListNode(ndata);
if(head==NULL)
	{
		head=temp;
		tail=head;
		head->prev=NULL;
		head->next=NULL;
		length++;
			
	}
else
	{
		tail->next=temp;
		temp->next=NULL;
		temp->prev=tail;
		tail=temp;
		
		length++;
	}

}


/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse()
{	//tail=NULL;
    reverse(head, tail);
     
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <class T>
void List<T>::reverse( ListNode * & startPoint, ListNode * & endPoint )
{
    /// @todo Graded in MP3.1
//ListNode *temp2=head->next;
	if(startPoint==NULL || endPoint==NULL)
		return;
	ListNode *t2;
	ListNode *t3=endPoint->prev;
	ListNode * startPoint1=startPoint;
	ListNode * endPoint1= endPoint;
	ListNode * start_point=startPoint;
	int count=1;
	int start=0;
	int end_point=0;
	t2=head;
	int flag=-1;
	if(startPoint==tail && endPoint==head)
	{
		startPoint1=endPoint;
		endPoint1=startPoint;
		//start_point=endPoint;
		flag=6;
	}
	if(startPoint==head && endPoint==tail)
		flag=1;
	if(startPoint==head && endPoint!=tail)
		flag=2;
	if(startPoint!=head && endPoint!=tail && startPoint!=tail && endPoint!=head)
	     {  	
		flag=3;
		end_point=-1;
	     }
	if(startPoint!=head && endPoint==tail)
		flag=4;
	if(startPoint==endPoint)
	   	flag=5;
	if(startPoint!=head)
	{
		while(t2->next!=startPoint)
		{
			t2=t2->next;
			start++;
		}
	}
	t2=head;
	if(endPoint!=head)
	{
		while(t2!=endPoint)
		{
			t2=t2->next;
			end_point++;
		}
	}
	if(flag==6){
		t2=head;
		end_point=0;
		while(t2!=tail){
			t2=t2->next;
			end_point++;
		}
		start=0;	
		t2=endPoint;
	}
	//cout<<start<<end_point<<"endpoint"<<endPoint<<endl;
	for(int i=start;i<end_point;i++)
	{	//cout<<count++<<endl;
		ListNode * temp=startPoint1->prev;
		startPoint1->prev=startPoint1->next;
		startPoint1->next=temp;
		if(startPoint1->prev!=NULL)
			{
				t2=startPoint1;		
				startPoint1=startPoint1->prev;
				//cout<<"startPoint"<<startPoint<<endl;			
			}
		
		
	}
	
	if(flag==1)
	{
		startPoint1->next=t2;
		t2->prev=startPoint1;
		
		while(endPoint1->next!=NULL)
			endPoint1=endPoint1->next;
		startPoint1->prev=NULL;
		//t3=startPoint1->next;
		
		head=startPoint1;
		tail=endPoint1;
		startPoint=startPoint1;
		endPoint=endPoint1;
		//cout<<"Head tail\n";
			
	}
	if(flag==2){
		if(startPoint1->next!=NULL)
		{
			startPoint1->prev=NULL;
			ListNode* temp=startPoint1->next;
			start_point->next=temp;
			temp->prev=start_point;
		}		
		startPoint1->next=t2;
		head=startPoint1;
		startPoint=startPoint1;
		endPoint=start_point;
		//cout<<"head not tail\n";
	}
	if(flag==3)
	{
		ListNode *temp=startPoint1->next;
		ListNode *start_temp=start_point->next;
		start_temp->next=startPoint1;
		start_point->next=temp;
		temp->prev=start_point;
		startPoint1->prev=start_temp;
		startPoint1->next=t2;
		endPoint=start_point;
		startPoint=startPoint1;
		//cout<<"middle \n";
			
	}
	if(flag==4)
	{
		ListNode *start_temp=start_point->next;
		start_temp->next=startPoint1;
		start_point->next=NULL;
		startPoint1->next=t2;
		startPoint1->prev=start_temp;
		tail=startPoint;
		endPoint=start_point;
		startPoint=startPoint1;
		//cout<<"mid and tail\n";
	}
		if(flag==6)
	{
		startPoint1->next=t2;
		while(endPoint1->next!=NULL)
			endPoint1=endPoint1->next;
		tail=startPoint1;
		head=endPoint1;
		startPoint=endPoint1;
		endPoint=startPoint1;
		//cout<<"Head tail\n";
			
	}
	//ListNode * change= startPoint;
	//startPoint=endPoint;
	//endPoint=change;
	//display(tail);
}
template <class T>
void List<T>:: display(ListNode * & start){
ListNode *temp= tail;
cout<<"display\n";
while(temp!=head){
cout<<temp->data<<" ";
temp=temp->prev;
}
//cout<<endl;
}
/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <class T>
void List<T>::reverseNth( int n )
{
    /// @todo Graded in MP3.1
	if(n>=length)
		reverse(head,tail);
	else if(length>=1)
	{
	 	int no_segments;
		ListNode *start=head;
		ListNode *end_ptr=head;
		if(length%n==0)
			no_segments=length/n;
		else
			no_segments=(length/n)+1;
		for(int i=0;i<no_segments;i++)
		{	//cout<<"segments="<<no_segments<<endl;
			for(int j=0;j<n-1;j++)
			{
				if(end_ptr->next!=NULL)
				end_ptr=end_ptr->next;
			}
			if(start!=end_ptr)	
			reverse(start,end_ptr);
			if(end_ptr->next!=NULL)
			end_ptr=end_ptr->next;
			start=end_ptr;
		}
		
	}

	//reverse(head,head->next->next);
	//reverse(head->next->next->next,head->next->next->next->next->next);
	//reverse(head->next->next->next->next->next->next,tail);
}


/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall()
{
    /// @todo Graded in MP3.1
	ListNode * curr =head;
	ListNode * curr_next;
	while(curr!=tail)
	{	ListNode * curr_prev=curr;
		if(curr->next!=NULL)	
		curr=curr->next;
		if(curr->next!=NULL)
		{	curr_next=curr->next;
			curr->prev=tail;
			curr->next=NULL;
			tail->next=curr;
			tail=curr;
			curr_next->prev=curr_prev;
			curr_prev->next=curr_next;
			curr=curr_next;
		}
		else
			tail=curr;	

	}
}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <class T>
List<T> List<T>::split(int splitPoint)
{
    if (splitPoint > length)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode * secondHead = split(head, splitPoint);

    int oldLength = length;
    if (secondHead == head)
    {
        // current list is going to be empty
        head = NULL;
        tail = NULL;
        length = 0;
    }
    else
    {
        // set up current list
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        length = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head = secondHead;
    ret.tail = secondHead;
    if (ret.tail != NULL)
    {
        while (ret.tail->next != NULL)
            ret.tail = ret.tail->next;
    }
    ret.length = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint)
{
    /// @todo Graded in MP3.2
	//if(splitPoint!=1)
	//{
	//cout<<"current split"<<splitPoint<<endl;
	ListNode * temp=start;
	
	

	if(temp!=NULL){
	for(int i=0;i<splitPoint-1;i++)
		{
			if(temp->next!=NULL)
				temp=temp->next;
		}
	ListNode * new_start= temp->next;
	temp->next=NULL;
	tail=temp;
	if(new_start!=NULL)
	new_start->prev=NULL;
	//cout<<"end\n";
	return new_start;
	}
	//cout<<"end other\n";
	return start;
}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T> & otherList)
{
    // set up the current list
    head = merge(head, otherList.head);
    tail = head;

    // make sure there is a node in the new list
    if(tail != NULL)
    {
        while (tail->next != NULL)
            tail = tail->next;
    }
    length = length + otherList.length;

    // empty out the parameter list
    otherList.head = NULL;
    otherList.tail = NULL;
    otherList.length = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <class T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode * second)
{
    /// @todo Graded in MP3.2
	ListNode * temp_first=first;
	ListNode * temp_sec=second;
	int i=0;
	//cout<<"seg";
	while((temp_first!=NULL) && (temp_sec!=NULL)){
		
	if((temp_first->data<temp_sec->data) && !(temp_sec!=NULL && temp_first->next==NULL))
	{	
		temp_first=temp_first->next;		
	}
	else
	{	if(!(temp_first->data<temp_sec->data))
		{
			ListNode *temp_first_prev= temp_first->prev;
			ListNode *temp_sec_next;
			if(temp_sec->next!=NULL)
				temp_sec_next=temp_sec->next;
			else
				temp_sec_next=NULL;
			ListNode * temp_sec2=temp_sec;
			temp_sec2->next=temp_first;
			temp_sec2->prev=temp_first_prev;
			if(temp_first_prev!=NULL)
				temp_first_prev->next=temp_sec2;
			else
				first=temp_sec2;			
			temp_first->prev=temp_sec2;
			if(temp_sec->next!=NULL)
				temp_sec=temp_sec_next;
			else
				temp_sec=NULL;
		}
		else
		{
			ListNode *temp_first_next= temp_first->next;
			ListNode *temp_sec_next;
			if(temp_sec->next!=NULL)
				temp_sec_next=temp_sec->next;
			else
				temp_sec_next=NULL;
			ListNode * temp_sec2=temp_sec;
			temp_sec2->prev=temp_first;
			temp_first->next=temp_sec2;
			temp_sec2->next=temp_first_next;
			temp_sec=temp_sec_next;
		}
	}
	
	}
    return first; // change me!
}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <class T>
void List<T>::sort()
{	
    if (empty())
        return;
    head = mergesort(head, length);
    tail = head;

    while (tail->next != NULL)
        tail = tail->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode * List<T>::mergesort(ListNode * start, int chainLength)
{	ListNode *left;
	ListNode *right;
	
    /// @todo Graded in MP3.2
	//cout<<"current length"<<chainLength<<endl;
	if(chainLength<=1)
	{	
		//cout<<"called base case\n";
		return start;
		
	}
	else
	{
		int mid=chainLength/2;
		
		
		left=start;
		if(mid!=0)
		right=split(left,mid);
		left=mergesort(left,mid);
		right=mergesort(right,chainLength-mid);
		return merge(left,right);
		
	}
	return merge(left,right);
	
    
}
