#include "Entry.h"
#include "List.h"

int Node::ncount = 0;
Node::Node(Entry s)
{  
   data = s;
   previous = NULL;
   next = NULL;
   ncount++;
}
Node::~Node()
{
	ncount--;
}

List::~List()
{
	if (!empty()) {
		Node* p = first;
		while (p!=last) {
			Node* nextp = p->next;
			delete p;
			p = nextp;
		}
		delete p;
	}
}

bool List::empty() const
{
	return last == NULL;
}
int List::size() const
{
	int n = 0;
	for (Iterator li = begin(); li!=end(); li++)
		n++;
	return n;
}

void List::push_back(Entry s)
{  
   Node* newnode = new Node(s);
   if (last == NULL) /* list is empty */
   {  
      first = newnode;
      last = newnode;
   }
   else
   {  
      newnode->previous = last;
      last->next = newnode;
      last = newnode;
   }
}

void List::insert(Iterator iter, Entry s)
{  
   if (iter.position == NULL)
   {  
      push_back(s);
      return;
   }

   Node* after = iter.position;
   Node* before = after->previous;
   Node* newnode = new Node(s);
   newnode->previous = before;
   newnode->next = after;
   after->previous = newnode;
   if (before == NULL) /* insert at beginning */
      first = newnode;
   else
      before->next = newnode;
}

Iterator List::erase(Iterator i)
{  
   Iterator iter = i;
   assert(iter.position != NULL);
   Node* remove = iter.position;
   Node* before = remove->previous;
   Node* after = remove->next;
   if (remove == first)
      first = after;
   else
      before->next = after;
   if (remove == last)
      last = before;
   else
      after->previous = before;
   iter.position = after;
   delete remove;
   return iter;
}

Iterator List::begin() const
{  
   Iterator iter;
   iter.position = first;
   iter.last = last;
   return iter;
}

Iterator List::end() const
{  
   Iterator iter;
   iter.position = NULL;
   iter.last = last;
   return iter;
}

Iterator::Iterator()
{  
   position = NULL;
   last = NULL;
}

Entry Iterator::get() const
{  
   assert(position != NULL);
   return position->data;
}

void Iterator::next()
{  
   assert(position != NULL);
   position = position->next;
}

void Iterator::previous()
{  
   if (position == NULL)
      position = last;
   else 
      position = position->previous;
   assert(position != NULL);
}

bool Iterator::equals(Iterator b) const
{  
   return position == b.position;
}
Iterator& Iterator::operator++(int)
{
   assert(position != NULL);
   position = position->next;
   return *this;
}
Iterator& Iterator::operator--(int)
{
	if (position == NULL)
		position = last;
	else
		position = position->previous;
	assert(position != NULL);
	return *this;
}

Entry Iterator::operator*() const
{
   assert(position != NULL);
   return position->data;
}

Entry* Iterator::operator ->()
{
	   assert(position != NULL);
	   return &(position->data);
}
bool Iterator::operator==(const Iterator& b) const
{
   return position == b.position;
}

bool Iterator::operator!=(const Iterator& b) const
{
   return position != b.position;
}
