//프로그램을 먼저 맞게끔 돌아가게 해라
//시간이 괜찬다고 생각하면 한번 구성, 그렇지 않으면 구성하지 말자.
//node max=104가 계속 나와야함 sort되어도. 쭉 cur은 0이 나오는건 sortTest()를 통해 확인가능.
#include "Entry.h"
#include "List.h"

Node::Node(Entry s)
{
	data = s;
	previous = NULL;
	next = NULL;
}

List::List()
{
	first = NULL;
	last = NULL;
}

List::~List()
{
	Node* p = first;
	while (p != NULL)
	{
		Node* nextp = p->next;
		delete p;
		p = nextp;
	}
}

List::List(const List& right)
{
	cout << "List Copy Constructor Called" << endl;
	first = NULL;
	last = NULL;
	for (Iterator iter = right.begin(); iter != right.end(); iter++)
	{
		push_back(*iter);
	}
}

List& List::operator=(const List& right)
{
	cout << "List operator= Called" << endl;

	if (this != &right) {
		// Delete all Node
		if (!empty()) {
			Node* p = first;
			while (p != last) {
				Node* nextp = p->next;
				delete p;
				p = nextp;
			}
			delete p;
		}
		// Copy right List
		first = NULL;
		last = NULL;
		for (Iterator iter = right.begin(); iter != right.end(); iter++) {
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
	for (Iterator li = begin(); li != end(); li++)
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

void List::push_front(Entry s)
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
Entry& Iterator::operator*()
{
	assert(position != NULL);
	return position->data;
}

Entry* Iterator::operator->()
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
