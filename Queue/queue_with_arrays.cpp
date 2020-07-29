#include <iostream>
#include <climits>

using namespace std;


// Main class contaning all the methods contanning the Queue.
class Queue_With_Arrays
{

	int read, write; // Points to the first and last index.
	int count; // Variable to determine the size of the queue.
	int MAX_SIZE; // To store the max size of queue.
	int* queue ; // Array to store queue.

public:

	// Construtor to store queue.
	Queue_With_Arrays() {

		read = -1;
		write = -1;
		count = 0;
		MAX_SIZE = 10; // Default size of the queue is 10.

		queue = new int[MAX_SIZE]; // Creating the array to store the queue.

	}

	// Parameterized consstructor to store queue
	Queue_With_Arrays(int s) {

		read = -1;
		write = -1;
		count = 0;
		MAX_SIZE = s; // Max size of queue is given by users.

		queue = new int[MAX_SIZE]; // Creating the array to store the queue.

	}


	// Deconstructor to free memory after the use
	~Queue_With_Arrays() {
		delete[] queue;
	}




/* 	################### Functions start Here ##################	*/




	// Function to add value to the queue.
	void enqueue(int value) {

		// Check if queue if full?
		if (isFull()) {

			cout << "ERROR: Queue Overflow " << endl;
			return;
		}

		// Check if queue is empty?
		else if (isEmpty()) {

			read = 0;
			write = 0;

		}

		// else
		else
			write = (write + 1) % MAX_SIZE; // Change the write position

		queue[write] = value; // Adding the value to the queue.

		count ++; // Incresing the size of queue.

	}



	// Function to  return and remove first value from the queue.
	int dequeue() {

		// If queue if Empty?
		if (isEmpty()) {

			cout << "ERROR: Queue Underflow"  << endl;
			return INT_MIN;

		}

		// Variable to store the first value
		int temp_data = queue[read];

		read = (read + 1) % MAX_SIZE; // Changing the read position.


		count--; // Reducing the size

		return temp_data; // returning the value.
	}




	// Function to return first value from  the queue.
	int peek() {

		// Is queue is empty?
		if (isEmpty()){

			return INT_MIN;
		}


		return queue[read]; // Returning the value

	}




	// Function to check if queue is empty?
	bool isEmpty() {

		return (size() == 0);
	}




	// Funcion to check if queue is full?
	bool isFull() {
		return (size() == MAX_SIZE);
	}




	// Function to return size of the queue.
	int size() {

		return count;

	}



	// Function to display the queue.
	void display() {

		if (!isEmpty()) {

			int temp_read = read;

			do {
				cout << " " << queue[temp_read];

				if (temp_read == write)
					break;

				temp_read = ++ temp_read % MAX_SIZE;
			}
			while (temp_read != read);

			cout << endl;
		}

	}

};


// Main driver function.
int main() {

	Queue_With_Arrays s(5);

	int i = 1;

	cout << "Is stack EMPTY?? ";
	cout << s.isEmpty() << endl;

	s.enqueue(i);
	i++;

	// cout << "Is stack EMPTY?? ";
	// cout << s.isEmpty() << endl;

	s.enqueue(i);
	i++;
	s.enqueue(i);
	i++;
	s.enqueue(i);
	i++;
	s.enqueue(i);
	i++;
	s.enqueue(i);
	i++;
	s.enqueue(i);
	i++;
	s.enqueue(i);
	i++;
	s.enqueue(i);
	i++;
	s.enqueue(i);
	i++;
	// s.enqueue(i);
	// i++;



	cout << "Queue Become : ";
	s.display();

	cout << "Queue Peek : ";
	cout << s.peek() << endl;

	cout << "Queue  Size Become : ";
	cout << s.size() << endl;

	cout << "Is Queue EMPTY?? ";
	cout << s.isEmpty() << endl;

	cout << "Is Queue Full?? ";
	cout << s.isFull() << endl;

	cout << endl;


	cout << "Element removed: " << s.dequeue() << endl;
	cout << "Element removed: " << s.dequeue() << endl;
	cout << "Element removed: " << s.dequeue() << endl;

	cout << endl;


	cout << "Queue Become : ";
	s.display();

	cout << "Queue Peek : ";
	cout << s.peek() << endl;

	cout << "Queue  Size Become : ";
	cout << s.size() << endl;

	cout << "Is Queue EMPTY?? ";
	cout << s.isEmpty() << endl;

	cout << "Is Queue Full?? ";
	cout << s.isFull() << endl;


	cout << endl;


	cout << "Element removed: " << s.dequeue() << endl;
	cout << "Element removed: " << s.dequeue() << endl;
	cout << "Element removed: " << s.dequeue() << endl;

	cout << endl;


	cout << "Queue Become : ";
	s.display();

	cout << "Queue Peek : ";
	cout << s.peek() << endl;

	cout << "Queue  Size Become : ";
	cout << s.size() << endl;

	cout << "Is Queue EMPTY?? ";
	cout << s.isEmpty() << endl;

	cout << "Is Queue Full?? ";
	cout << s.isFull() << endl;



	return 0;

}