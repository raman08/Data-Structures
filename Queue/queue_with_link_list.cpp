#include <iostream>
#include <climits>

using namespace std;

// Structue to store the Node Values of Link List.
struct Node {

	int data; // To store the data
	Node* next; // To store the pointer of the new node.
};


// Main class contaning all the methods contanning the Queue.
class Queue_With_Link_List {

	Node* head; // Node pointer for head.
	Node* tail; // Node pointer for tail.
	int count; // Variable for the size of queue.

public:

	// Construtor to store queue.
	Queue_With_Link_List() {

		head = NULL; // Initialzing the head pointer.
		tail = NULL; //Initialzing the tail pointer.
		count = 0; // Initaialzing the size of the queue.

	};

	// Deconstructor to free memory after the use
	~Queue_With_Link_List() {

		Node* current = head;

		// deleting all node one by one.
		while (head != NULL) {

			Node* next = current->next;
			delete current;
			current = next;

		}

		head = NULL;

	};



/* 	################### Functions start Here ##################	*/



	// Function to add value to the queue.
	void enqueue(int value) {

		Node* temp = new Node; // Creating a new node.

		temp->data = value; // Adding data to the temp node

		temp->next = NULL; // Setting the next of the temp to NULL.

		count++; // Incresing the size of the quwuw

		// If queue is empty.
		if (head == NULL) {

			head = tail = temp; // Pointing head and tail to the temp.
			return;

		}

		tail->next = temp; // Setting temp as last element of the queue
		tail = temp; // Pointing tail to the temp.


	}




	// Function to return and remove the last element of the queue
	int dequeue() {

		// If queue if empty ?
		if (isEmpty()) {

			cout << "ERROR: Queue Underflow"  << endl;
			return INT_MIN;
		}

		int temp_data = head->data; // Storing the data of the first element

		Node* temp = head; // Creating a new node.

		head = temp->next; // Pointing head to the 2nd element in queue.

		// If the list is empty then set tail to NULL
		if (head == NULL)
			tail = NULL;

		delete temp; // Deleting the 1st node.

		--count; // Redicing the size of the queue.

		return temp_data; // returning the 1st element.

	}




	// Function to return first value from  the queue.
	int peek() {

		// If queue is empty return the smallest int
		if (isEmpty())
			return INT_MIN;

		return head->data; // return the first element.
	}



	// Function to check if queue is empty?
	bool isEmpty() {

		return (head == NULL);

	}



	// Function to return size of the queue.
	int size() {

		return count;

	}



	// Function to display the queue.
	void display() {

		Node* temp = head;

		while (temp != nullptr) {

			cout << temp->data << " -> ";
			temp = temp->next;

		}
		cout << "NULL" << endl;
	}


};

int main() {

	Queue_With_Link_List s;

	int i = 1;

	cout << "Is Queue EMPTY?? ";
	cout << s.isEmpty() << endl;

	s.enqueue(i);
	i++;

	cout << "Is Queue EMPTY?? ";
	cout << s.isEmpty() << endl;

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


	return 0;
}