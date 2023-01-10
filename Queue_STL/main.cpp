#include <iostream>
#include <stack>
#include <queue>
#include <string>

#include <stack>

template <class Type>
void reverseQ(std::queue<Type> &q)
{
	std::stack<Type> s;
	while (!q.empty())
	{
		s.push(q.front());
		q.pop();
	}
	
	while (!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
}


template <class Type>
void printQueue(const std::queue<Type>& theQueue)
{
	// create a copy of the queue to maintain original queue elements
	std::queue<Type> tempQueue = theQueue;
	
	while (!tempQueue.empty())
	{
		std::cout << tempQueue.front() << " ";
		tempQueue.pop();
	}
	std::cout << std::endl;
}


bool isInLanguageL(std::string w)
{
	std::queue<char> q;
	unsigned int index = 0;
	
	while (w[index] == 'a')
	{
		q.emplace('-');
		index++;
	}
	
	while (w[index] == 'b' && !q.empty())
	{
		if (q.front() == '-')
		{
			q.pop();
			index++;
		}
	}
	
	if (q.empty())
	{
		return index == w.length();
	}
	
	else
	{
		return false;
	}
}

// Function replaces every second item in a queue with a new item.
template <class Type>
void replaceEverySecondItem(std::queue<Type>& q, const Type& newItem)
{
	// create a temp queue to maintain original elements
	std::queue<Type> tempQueue;
	
	// move elements to temp queue
	while (!q.empty())
	{
		tempQueue.emplace(q.front());
		q.pop();
	}
	
	// conditionally move elements back to original queue
	unsigned int currentIndex = 0;
	while (!tempQueue.empty())
	{
		if (currentIndex % 2 == 0)
		{
			q.emplace(tempQueue.front());
		}
		else
		{
			q.emplace(newItem);
		}
		tempQueue.pop();
		currentIndex++;
	}
}

static void test_reverseQ()
{
	std::queue<int> emptyQueue;
	reverseQ(emptyQueue);
	assert(emptyQueue.empty());
	
	/// test with a queue of size 5
	std::queue<int> q;
	
	// add elements to queue
	q.emplace(1);
	q.emplace(2);
	q.emplace(3);
	q.emplace(4);
	q.emplace(5);
	
	assert(q.front() == 1);
	assert(q.back() == 5);
	
	// print the elements in the queue before reversing
	std::cout << "The queue before reversing: ";
	printQueue(q);
	
	// reverse the queue
	reverseQ(q);
	
	assert(q.front() == 5);
	assert(q.back() == 1);
	
	// print the elements in the queue after reversing
	std::cout << "The queue after reversing: ";
	printQueue(q);
}

static void test_replaceEverySeconItem()
{
	std::queue<int> myQueue;
	
	// add elements to queue
	myQueue.emplace(1);
	myQueue.emplace(3);
	myQueue.emplace(4);
	myQueue.emplace(6);
	myQueue.emplace(7);
	myQueue.emplace(8);
	myQueue.emplace(2);
	
	std::cout << "My queue before replaceEverySecondItem: ";
	printQueue(myQueue);
	
	replaceEverySecondItem(myQueue, 0);
	std::cout << "My queue after replaceEverySecondItem: ";
	printQueue(myQueue);
}

int main()
{
	test_replaceEverySeconItem();
	
	return 0;
}
