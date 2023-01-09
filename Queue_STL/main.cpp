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

int main()
{
	/// test with an empty queue
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
	
	return 0;
}
