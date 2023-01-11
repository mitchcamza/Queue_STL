#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <stack>
#include "Queue.h"


static void test_reverseQ()
{
	std::queue<int> emptyQueue;
	reverseQ(emptyQueue);
	assert(emptyQueue.empty());
	
	/// test with a queue of size 5
	std::queue<int> q;
	
	// add elements to queue
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	
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
	// Test case 0: Provided in exam question
	std::queue<int> myQueue;
	
	// add elements to queue
	myQueue.push(1);
	myQueue.push(3);
	myQueue.push(4);
	myQueue.push(6);
	myQueue.push(7);
	myQueue.push(8);
	myQueue.push(2);
	
	std::cout << "My queue before replaceEverySecondItem: ";
	printQueue(myQueue);
	
	replaceEverySecondItem(myQueue, 0);
	std::cout << "My queue after replaceEverySecondItem: ";
	printQueue(myQueue);
	
	// Test case 1: Test the function with an empty queue.
	std::queue<int> q;
	replaceEverySecondItem(q, 0);
	assert(q.size() == 0);

	// Test case 2: Test the function with a queue containing only one element.
	q.push(1);
	replaceEverySecondItem(q, 0);
	assert(q.size() == 1);
	assert(q.front() == 1);

	// Test case 3: Test the function with a queue containing two elements.
	q.push(2);
	replaceEverySecondItem(q, 0);
	assert(q.size() == 2);
	assert(q.front() == 1);
	q.pop();
	assert(q.front() == 0);

	// Test case 4: Test the function with a queue containing an odd number of elements.
	q.push(3);
	q.push(4);
	q.push(5);
	replaceEverySecondItem(q, 0);
	assert(q.size() == 5);
	assert(q.front() == 1);
	q.pop();
	assert(q.front() == 0);
	q.pop();
	assert(q.front() == 4);
	q.pop();
	assert(q.front() == 0);
	q.pop();
	assert(q.front() == 5);


	// Test case 5: Test the function with a queue containing an even number of elements.
	q.push(6);
	q.push(7);
	q.push(8);
	q.push(9);
	replaceEverySecondItem(q, 0);
	assert(q.size() == 8);
	assert(q.front() == 1);
	q.pop();
	assert(q.front() == 0);
	q.pop();
	assert(q.front() == 4);
	q.pop();
	assert(q.front() == 0);
	q.pop();
	assert(q.front() == 5);
	q.pop();
	assert(q.front() == 0);
	q.pop();
	assert(q.front() == 8);
	q.pop();
	assert(q.front() == 0);

	// Test case 6: Test the function with a queue containing all the same elements.
	q.push(9);
	q.push(9);
	q.push(9);
	q.push(9);
	replaceEverySecondItem(q, 0);
	assert(q.size() == 8);
	assert(q.front() == 9);
	q.pop();
	assert(q.front() == 0);
	q.pop();
	assert(q.front() == 9);
	q.pop();
	assert(q.front() == 0);
	q.pop();
	assert(q.front() == 9);
	q.pop();
	assert(q.front() == 0);
	q.pop();
	assert(q.front() == 9);
	q.pop();
	assert(q.front() == 0);

	// Test case 7: Test the function with a queue containing all different elements.
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	replaceEverySecondItem(q, 0);
	assert(q.size() == 8);
	assert(q.front() == 1);
	q.pop();
	assert(q.front() == 0);
	q.pop();
	assert(q.front() == 3);
	q.pop();
	assert(q.front() == 0);
	q.pop();
	assert(q.front() == 4);
	q.pop();
	assert(q.front() == 0);
	q.pop();
	assert(q.front() == 1);
	q.pop();
	assert(q.front() == 0);
	
	// Test case 8: Test the function with a queue containing a mix of different elements.
	q.push(5);
	q.push(6);
	q.push(7);
	q.push(8);
	replaceEverySecondItem(q, 0);
	assert(q.size() == 8);
	assert(q.front() == 5);
	q.pop();
	assert(q.front() == 0);
	q.pop();
	assert(q.front() == 7);
	q.pop();
	assert(q.front() == 0);
	q.pop();
	assert(q.front() == 8);
	q.pop();
	assert(q.front() == 0);
	q.pop();
	assert(q.front() == 5);
	q.pop();
	assert(q.front() == 0);

	// Test case 9: Test the function with a queue containing a mix of different elements and the new item value equal to the minimum value.
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	replaceEverySecondItem(q, std::numeric_limits<int>::min());
	assert(q.size() == 8);
	assert(q.front() == 1);
	q.pop();
	assert(q.front() == std::numeric_limits<int>::min());
	q.pop();
	assert(q.front() == 3);
	q.pop();
	assert(q.front() == std::numeric_limits<int>::min());
	q.pop();
	assert(q.front() == 4);
	q.pop();
	assert(q.front() == std::numeric_limits<int>::min());
	q.pop();
	assert(q.front() == 1);
	q.pop();
	assert(q.front() == std::numeric_limits<int>::min());

	// Test case 10: Test the function with a queue containing a mix of different elements and the new item value equal to the maximum value.
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	replaceEverySecondItem(q, std::numeric_limits<int>::max());
	assert(q.size() == 8);
	assert(q.front() == 1);
	q.pop();
	assert(q.front() == std::numeric_limits<int>::max());
	q.pop();
	assert(q.front() == 3);
	q.pop();
	assert(q.front() == std::numeric_limits<int>::max());
	q.pop();
	assert(q.front() == 4);
	q.pop();
	assert(q.front() == std::numeric_limits<int>::max());
	q.pop();
	assert(q.front() == 1);
	q.pop();
	assert(q.front() == std::numeric_limits<int>::max());
}


int main()
{
	
	return 0;
}
