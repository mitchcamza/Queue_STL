#include <iostream>
#include <stack>
#include <queue>
#include <string>

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
//	std::queue<int> q;
//	q.emplace(1);
//	q.emplace(2);
//	q.emplace(3);
//	q.emplace(4);
//	reverseQ(q);
//	printQueue(q);
	
	
	std::string w = "aabb";
	
	if (isInLanguageL(w))
	{
		std::cout << w << " is in the language L" << std::endl;
	}
	
	else
	{
		std::cout << w << " is not in the language L" << std::endl;
	}
	
	return 0;
}
