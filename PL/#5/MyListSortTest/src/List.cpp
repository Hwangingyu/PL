
#include "String.h"
#include "List.h"

int Node::curCount = 0;
int Node::maxCount = 0;

Node::Node(String s)
{  
	data = s;
	previous = NULL;
	next = NULL;
	curCount++;
	//maxCount = max(maxCount, curCount);
	maxCount++;
}
Node::~Node()
{
	curCount--;
	//maxCount++;
}

List::List()
{  
	first = NULL;
	last = NULL;
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
List::List(const List& right){
	cout << "List Copy Constructor Called" << endl;
	first = NULL;
	last = NULL;
	for (Iterator iter=right.begin(); iter!=right.end(); iter++ ){
		push_back(*iter);
	}
}
List& List::operator=(const List& right){
	cout << "List operator= Called" << endl;
	if (this != &right) {
		// Delete all Node
		if (!empty()) {
			Node* p = first;
			while (p!=last) {
				Node* nextp = p->next;
				delete p;
				p = nextp;
			}
			delete p;
		}
		// Copy right List
		first = NULL;
		last = NULL;
		for (Iterator iter=right.begin(); iter!=right.end(); iter++ ){
			push_back(*iter);
		}
	}
	return *this;
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

void List::push_back(String s)
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
void List::push_front(String s)
{
	Node* newnode = new Node(s);
	if (last == NULL) /* list is empty */
	{
		first = newnode;
		last = newnode;
	}
	else
	{
		newnode->next = first;
		first->previous = newnode;
		first = newnode;
	}
}

void List::insert(Iterator iter, String s)
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

String Iterator::get() const
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

String Iterator::operator*() const
{
	assert(position != NULL);
	return position->data;
}
String& Iterator::operator*()
{
	assert(position != NULL);
	return position->data;
}

String* Iterator::operator->()
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
