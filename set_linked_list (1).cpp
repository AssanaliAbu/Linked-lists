#include <iostream>
using namespace std;
#include "set_linked_list.h"

// Copy constructor
set:: set(const set& q):set(){
node*cur = q.head;
while(cur){
insert(cur->value);
cur = cur->next;
}




}

// Initializer list constructor
set:: set (std::initializer_list<int> ilist):set(){
	for(int v : ilist){
	    	insert(v);
		}


}

// Copy assignment
set& set::operator=(const set& q){

	if(this!=&q){
	  clear();

				node*cur = q.head;
				do{
				insert(cur->value);
				cur = cur->next;

	        	}
				while(cur);



		}
			return* this;
		}



// Insert an item into the set.
void set:: insert (int val){

	node * new_node = new node(val);
			if(set_size ==0){
				head = new_node;
				set_size++;
			    head->next = nullptr;
	            head->prev = nullptr;
			}
			else if(val<head->value){
				new_node->next= head;
				head->prev = new_node;
				head = new_node;
				set_size++;
				  head->prev = nullptr;
			}
			else{
				node*cur = head;
			 do{
				 if (!cur->next || cur->next->value>val){
					 break;
				 }
				 cur = cur->next;



						}
			 while(cur);
			 new_node->next = cur->next;
			 if(cur->next){
			 cur->next->prev = new_node;
			 }
			 else{

			 }
			 cur->next = new_node;
			 new_node->prev = cur;
             set_size++;
             if(new_node->prev->value==new_node->value){
            	 erase(new_node);
             }
				}
				}


// Searches for an item in the set.
// If found, returns the node containing val; otherwise returns nullptr.
set::node* set:: find (int val){
	if(set_size==0){
		return NULL;
	}
	node*cur = head;
	do{
		if(val==cur->value){
			return cur;
		}
		cur = cur->next;
	}while(cur);
return NULL;
}

// Erases an item from the set.
// If it is not in the set, does nothing.


// Erases the node "it" from the set.
void set::erase (node *it){
	if(it->next){
	it->next->prev = it->prev;

	}
	else{

	}
	if(it->prev){
	it->prev->next = it->next;
	}
	else{
		head = head->next;

	}
    delete it;


    set_size--;
}

// Remove everything from the set
void set::clear(){

	node*cur = head;
	while(cur){
		delete cur;
		cur = cur->next;
	}
	head = nullptr;
	set_size =0;

}

// Returns the number of items in the set
size_t set::size() const{
	return set_size;

}

// Returns whether or not the set is currently empty
bool set::empty() const{
	if(set_size ==0){
		return true;
	}
	else{
		return false;
	}

}
//q
// Returns a pointer to the first node in the set.
set::node* set::begin () const{
	return head;

}

// Merges the elements of set x into this set,
// and then clears the set x.
// If x is equal to this, does nothing.
// Should work in time O(size of this + size of x).

set::~set(){
	node*cur = head;
	while(cur){
		delete cur;
		cur = cur->next;
	}
	set_size = 0;
	head = nullptr;
}

