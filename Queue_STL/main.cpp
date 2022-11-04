#include <iostream>
#include <stack>
#include <queue>

template <class Type>
void reverseQ(std::queue<Type> &q)
{
	std::stack<Type> localStack;
	
	while (!q.empty())
	{
		localStack.push(q.front());
		q.pop();
	}
	
	while (!localStack.empty())
	{
		q.emplace(localStack.top());
		localStack.pop();
	}
}


template <class Type>
void printQueue(std::queue<Type> &theQueue)
{
	while (!theQueue.empty())
	{
		std::cout << theQueue.front() << " ";
		theQueue.pop();
	}
	std::cout << std::endl;
}

int main()
{
	std::queue<int> q;
	q.emplace(1);
	q.emplace(2);
	q.emplace(3);
	q.emplace(4);
	reverseQ(q);
	printQueue(q);
	
	return 0;
}
