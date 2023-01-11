//
//  Queue.h
//  Queue_STL
//
//  Created by Mitch Campbell on 2023/01/11.
//

#ifndef Queue_h
#define Queue_h

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
		q.push('-');
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
		tempQueue.push(q.front());
		q.pop();
	}
	
	// conditionally move elements back to original queue
	unsigned int currentIndex = 0;
	while (!tempQueue.empty())
	{
		if (currentIndex % 2 == 0)
		{
			q.push(tempQueue.front());
		}
		else
		{
			q.push(newItem);
		}
		tempQueue.pop();
		currentIndex++;
	}
}

// Function replaces every occurrence of an item in a queue
template <class Type>
void replaceItem(std::queue<Type>& queue, const Type& oldItem, const Type& newItem)
{
	std::queue<Type> tempQueue;
	
	// Conditionally move queue elements into a temporary queue
	while (!queue.empty())
	{
		if (queue.front() == oldItem)
		{
			tempQueue.push(newItem);
		}
		
		else
		{
			tempQueue.push(queue.front());
		}
		queue.pop();
	}
	
	// Move all queue elements back to original queue
	while (!tempQueue.empty())
	{
		queue.push(tempQueue.front());
		tempQueue.pop();
	}
}

#endif /* Queue_h */
