/**
 * @file psort.cpp
 */

/**
 * Public wrapper for the parallel sort implementation.
 * @param array The structure to sort
 */
/*
	
*/
#include <iostream>
#include <vector>  
#include <algorithm> 
using namespace std;

template <class T>
void ParallelSort::psort(vector<T>* array)
{	omp_set_nested(0);
	
	if(array->size()>1000)
	{	
	#pragma omp parallel
  		 #pragma omp single
		quick_sort(array,0,array->size()-1);
		
	}
	else
	{
		//#pragma omp parallel
		//#pragma omp single
		swap(array,0,array->size()-1);
	}
}
template <class T>
void ParallelSort::quick_sort(vector<T> *& array,int low,int high)
{	//cout<<"quick called low="<<low<<" high="<<high<<"\n";
	int i=low;
	int j=high;
	T pivot=array->at((low+high)/2);
	//cout<<"pivot="<<pivot<<endl;
		while(i<=j)
		{
			//#pragma omp parallel 
			{
				while(array->at(i)<pivot)
				i++;
				while(array->at(j)> pivot)
				j--;
			}	
			if(i<=j)
			{	//cout<<"swap index i "<<i<<" j "<<j<<endl;
				T temp=array->at(i);
				array->at(i)=array->at(j);
				array->at(j)=temp;
				//std::swap(array->at(i),array->at(j)); 
				i++;
				j--;
			}
			//else
			//cout<<"no swap "<<endl;
		}
	if(high-low<1000)
	{
		swap(array,low,high);
		swap(array,i,high);
	}
	else
	{   
	if(low<j)
	 #pragma omp task shared(array)
		  quick_sort(array,low,j);
		
	if(i<high)
	#pragma omp task shared(array)	
		quick_sort(array,i,high);
	#pragma omp taskwait
	}
}
template <class T>
void ParallelSort::swap(vector<T> *& array, int low, int high)
{
	//cout<<"quick called low="<<low<<" high="<<high<<"\n";
	int i=low;
	int j=high;
	T pivot=array->at((high+low)/2);
	//cout<<"pivot="<<pivot<<endl;
		while(i<=j)
		{
			while(array->at(i)<pivot)
				i++;
			while((array->at(j)> pivot))
				j--;
			if(i<=j)
			{	//cout<<"swap index i "<<i<<" j "<<j<<endl;
				T temp=array->at(i);
				array->at(i)=array->at(j);
				array->at(j)=temp;
				i++;
				j--;
			}
			
		}
		if(low<j)
		swap(array,low,j);
		if(i<high)	
		swap(array,i,high);		
}
	
	

