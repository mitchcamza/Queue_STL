//
//  tests.h
//  Queue_STL
//
//  Created by Mitch Campbell on 2023/02/13.
//

#ifndef tests_h
#define tests_h

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

static void test_replaceEverySecondItem()
{
	// Test case 0: Provided in exam question
	{
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
	}
	
	// Test case 1: Test the function with an empty queue.
	{
		std::queue<int> emptyQueue;
		replaceEverySecondItem(emptyQueue, 0);
		assert(emptyQueue.empty());
	}

	// Test case 2: Test the function with a queue containing only one element.
	{
		std::queue<int> singleElementQueue;
		singleElementQueue.push(1);
		replaceEverySecondItem(singleElementQueue, 0);
		assert(singleElementQueue.size() == 1);
		assert(singleElementQueue.front() == 1);
	}

	// Test case 3: Test the function with a queue containing two elements.
	{
		std::queue<int> twoElementQueue;
		twoElementQueue.push(1);
		twoElementQueue.push(2);
		replaceEverySecondItem(twoElementQueue, 0);
		assert(twoElementQueue.size() == 2);
		assert(twoElementQueue.front() == 1);
		twoElementQueue.pop();
		assert(twoElementQueue.front() == 0);
	}

	// Test case 4: Test the function with a queue containing an odd number of elements.
	{
		std::queue<int> oddElementQueue;
		oddElementQueue.push(1);
		oddElementQueue.push(2);
		oddElementQueue.push(3);
		replaceEverySecondItem(oddElementQueue, 0);
		assert(oddElementQueue.size() == 3);
		assert(oddElementQueue.front() == 1);
		oddElementQueue.pop();
		assert(oddElementQueue.front() == 0);
		oddElementQueue.pop();
		assert(oddElementQueue.front() == 3);
	}

	// Test case 5: Test the function with a queue containing an even number of elements.
	{
		std::queue<int> evenElementQueue;
		evenElementQueue.push(1);
		evenElementQueue.push(2);
		evenElementQueue.push(3);
		evenElementQueue.push(4);
		replaceEverySecondItem(evenElementQueue, 0);
		assert(evenElementQueue.size() == 4);
		assert(evenElementQueue.front() == 1);
		evenElementQueue.pop();
		assert(evenElementQueue.front() == 0);
		evenElementQueue.pop();
		assert(evenElementQueue.front() == 3);
		evenElementQueue.pop();
		assert(evenElementQueue.front() == 0);
	}
	
	// Test case 6: Test the function with a queue containing all the same elements.
	{
		std::queue<int> sameElementsQueue;
		sameElementsQueue.push(1);
		sameElementsQueue.push(1);
		sameElementsQueue.push(1);
		replaceEverySecondItem(sameElementsQueue, 0);
		assert(sameElementsQueue.size() == 3);
		assert(sameElementsQueue.front() == 1);
		sameElementsQueue.pop();
		assert(sameElementsQueue.front() == 0);
		sameElementsQueue.pop();
		assert(sameElementsQueue.front() == 1);
		sameElementsQueue.pop();
//		assert(sameElementsQueue.front() == NULL);
	}
	
	// Test case 7: Test the function with a queue containing all different elements.
	{
		std::queue<int> differentElementsQueue;
		differentElementsQueue.push(1);
		differentElementsQueue.push(2);
		differentElementsQueue.push(3);
		replaceEverySecondItem(differentElementsQueue, 0);
		assert(differentElementsQueue.size() == 3);
		assert(differentElementsQueue.front() == 1);
		differentElementsQueue.pop();
		assert(differentElementsQueue.front() == 0);
		differentElementsQueue.pop();
		assert(differentElementsQueue.front() == 3);
	}

	// Test case 8: Test the function with a queue containing a mix of different elements.
	{
		std::queue<int> mixElementsQueue;
		mixElementsQueue.push(1);
		mixElementsQueue.push(2);
		mixElementsQueue.push(2);
		mixElementsQueue.push(3);
		replaceEverySecondItem(mixElementsQueue, 0);
		assert(mixElementsQueue.size() == 4);
		assert(mixElementsQueue.front() == 1);
		mixElementsQueue.pop();
		assert(mixElementsQueue.front() == 0);
		mixElementsQueue.pop();
		assert(mixElementsQueue.front() == 2);
		mixElementsQueue.pop();
		assert(mixElementsQueue.front() == 0);
	}

	// Test case 9: Test the function with a queue containing a mix of different elements and the new item value equal to the minimum value.
	{
		std::queue<int> mixElementsMinQueue;
		mixElementsMinQueue.push(1);
		mixElementsMinQueue.push(2);
		mixElementsMinQueue.push(2);
		mixElementsMinQueue.push(3);
		replaceEverySecondItem(mixElementsMinQueue, std::numeric_limits<int>::min());
		assert(mixElementsMinQueue.size() == 4);
		assert(mixElementsMinQueue.front() == 1);
		mixElementsMinQueue.pop();
		assert(mixElementsMinQueue.front() == std::numeric_limits<int>::min());
		mixElementsMinQueue.pop();
		assert(mixElementsMinQueue.front() == 2);
		mixElementsMinQueue.pop();
		assert(mixElementsMinQueue.front() == std::numeric_limits<int>::min());
	}

	// Test case 10: Test the function with a queue containing a mix of different elements and the new item value equal to the maximum value.
	{
		std::queue<int> mixElementsMaxQueue;
		mixElementsMaxQueue.push(1);
		mixElementsMaxQueue.push(2);
		mixElementsMaxQueue.push(2);
		mixElementsMaxQueue.push(3);
		replaceEverySecondItem(mixElementsMaxQueue, std::numeric_limits<int>::max());
		assert(mixElementsMaxQueue.size() == 4);
		assert(mixElementsMaxQueue.front() == 1);
		mixElementsMaxQueue.pop();
		assert(mixElementsMaxQueue.front() == std::numeric_limits<int>::max());
		mixElementsMaxQueue.pop();
		assert(mixElementsMaxQueue.front() == 2);
		mixElementsMaxQueue.pop();
		assert(mixElementsMaxQueue.front() == std::numeric_limits<int>::max());
	}
}


static void test_replaceItem()
{
	std::queue<int> myQueue;
	
	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(2);
	myQueue.push(10);
	myQueue.push(22);
	
	std::cout << "My queue before replaceItem: ";
	printQueue(myQueue);
	std::cout << std::endl;
	
	replaceItem(myQueue, 2, 8);
	
	std::cout << "My queue after replaceItem: ";
	printQueue(myQueue);
	std::cout << std::endl;
}


#endif /* tests_h */
