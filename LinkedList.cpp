// LinkedList.cpp
// Spencer Romberg
// COSC 2030, Fall Semester
// 9/24/18
// Definition of methods for the List class.

#include "LinkedList.h"

#include <utility>


List::List()
	: first_(NULL)
{
}


List::List(const List & other)
	: first_(clone(other.first_))
{
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}

const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
	}

	return *this;
}

bool List::operator==(const List &rhs){
  /*  if(size() == 0 && rhs.size() == 0){return true;}//both empty
    if(size() != rhs.size()){return false;}//sizes not the same
    Node * lptr = this->next_;
    Node * rptr = rhs->next_;
		Double lEntry = lptr->entry_;
    Double rEntry = rptr->entry_;
		while (lptr != NULL && rptr != NULL)
		{
      if(lEntry != rEntry){
        return false;
      }
      lptr = lptr->next_;
      rptr = rptr->next_;
      lEntry = lptr->entry_;
      rEntry = rptr->entry_;
		}
*/
  	return true;
}


bool List::empty() const
{
	return first_ == NULL;
}


void List::insertAsFirst(double x)
{
	first_ = new Node(x, first_);
}


double List::removeFirst()
{
	double item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	return item;
}




void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";
}

double List::size()
{
	double list_size = 0.0;
	if (first_ != NULL)               //if the first entry is equal to null, merely add the value as part of the szie (prevents errors where the first value is not considered)
	{
		list_size++;
	}
	Node * ptr = first_->next_;       //grab the position after the first one
	while (ptr != NULL)               //while any part of the list is not equal to null, increase the size by one
	{
		ptr = ptr->next_;             //move to the next part of the list
		list_size++;
	}
	return list_size;
}

double List::sum()
{
	double list_sum = 0.0;
	Node * ptr1 = first_;
	if (first_ != NULL)               //if the first entry is equal to null, merely add the value (prevents errors where the first value is not considered)
	{
		list_sum += ptr1->entry_;     //move to the next part of the list
	}
	Node * ptr = first_->next_;       //grab the position after the first one    
	while (ptr != NULL)               //while any part of the list is not equal to null, add that value to the sum
	{
		list_sum += ptr->entry_;      //move to the next part of the list
		ptr = ptr->next_;
	}
	return list_sum;
}

void List::insertAsLast(double x)
{
	Node * ptr = first_;
	while (ptr != NULL)                      //if the position is not null
	{
		if (ptr->next_ == NULL)              //if the next position in the list is null, make the next position last in the list
		{
			ptr->next_ = new Node(x, NULL);
			break;
		}
		ptr = ptr->next_;                    //move to the next position
	}

	
}



// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}


//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}
