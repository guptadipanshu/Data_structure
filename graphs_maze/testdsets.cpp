/**
 * @file testdsets.cpp
 * Performs basic tests of DisjointSets.
 * @date April 2007
 * @author Jonathan Ray
 */

#include <iostream>
#include "dsets.h"

using std::cout;
using std::endl;

int main()
{
 /*  DisjointSets s;
   
   s.addelements(50);
   s.setunion(2,3);
   s.setunion(3,5);
   s.setunion(5,7);
   s.setunion(7,2);
   s.setunion(4,6);

   cout << s.find(7) << endl;
   cout << s.find(5) << endl;
   cout << s.find(6) << endl;
    cout << s.find(4) << endl;
   s.addelements(1);
   
   cout << s.find(50) << endl;
   
   s.setunion(50,3);
   
   cout << s.find(50) << endl;
   cout << "Disjoint Sets test complete"<< endl;
   */
   DisjointSets disjSets;
	disjSets.addelements(3);
	
	disjSets.setunion(0, 1);
	//disjSets.setunion(2, 3);
	//disjSets.setunion(6, 5);
	disjSets.setunion(1, 2);
	cout <<  disjSets.find(0) << endl;
	cout <<  disjSets.no_moreDsets() << endl;
	//cout <<  disjSets.find(2) << endl;
	//cout <<  disjSets.find(3) << endl;
	//cout <<  disjSets.find(4) << endl;
	//cout <<  disjSets.find(5) << endl;
	//cout <<  disjSets.find(6) << endl;
   return 0;
}

