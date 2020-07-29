#include <iostream>
#include <climits>

using namespace std;


// Structue to store the Node Values of Link List.
struct Node {

	int data; // To store the data
	Node* next; // To store the pointer of the new node.
};


// Class to store all finction of the stack.
class Stack_With_Link_List {

	Node* head; // Pointer to store head node.

	int top; // Store the size of the stack.

public:

	// Constructre to initilized value.
	Stack_With_Link_List() {

		head = nullptr;
		top = 0;

	};

/* 	################### Functions start Here ##################	*/


	// Function to add value to the stack
	void push(int value) {

		Node* temp = new Node; // Creating a new node.

		temp->data = value; // Adding data to the temp node

		temp->next = head; // Pointing temp->next to the head pointer

		head = temp; // Pointing head to the temp node

		top++; // Incresing the size of the stack.
	}



	// Function to return and remove the last element of the stack
	int pop() {

		Node* temp = head; // Creating a new node.

		head = temp->next; // Pointing head to the 2nd  node

		int temp_value = temp->data; // storing the data of the 1st node

		delete temp; // Deleting the first node

		--top; // Reducing the size of the stack

		return temp_value; // returning the value of teh first node.

	}



	// Finction to return the lastest value of the stack.
	int peek() {

		if (head != nullptr)
			return head->data;

		return INT_MIN;
	}


	// Function to check if stack is empty.
	bool isEmpty() {
		return (head == nullptr);
	}



	// Function to return size of the stack.
	int size() {
		return top;
	}



	// Function to print the stack.
	void display() {

		Node* temp = head;

		while (temp != nullptr) {

			cout << temp->data << " -> ";
			temp = temp->next;

		}
		cout << "NULL" << endl;
	}


};


// Main driver function.
int main() {

	Stack_With_Link_List s;

	int i = 1;

	cout << "Is stack EMPTY?? ";
	cout << s.isEmpty() << endl;

	cout << "Stack Peek : ";
	cout << s.peek() << endl;

	s.push(i);
	i++;

	cout << "Is stack EMPTY?? ";
	cout << s.isEmpty() << endl;

	s.push(i);
	i++;
	s.push(i);
	i++;
	s.push(i);
	i++;
	s.push(i);
	i++;
	s.push(i);
	i++;
	s.push(i);
	i++;
	s.push(i);
	i++;
	s.push(i);
	i++;
	s.push(i);
	i++;
	s.push(i);
	i++;



	cout << "Stack Become : ";
	s.display();

	cout << "Stack Peek : ";
	cout << s.peek() << endl;

	cout << "Stack  Size Become : ";
	cout << s.size() << endl;

	cout << "Is stack EMPTY?? ";
	cout << s.isEmpty() << endl;



	s.pop();
	s.pop();
	s.pop();



	cout << "Stack Become : ";
	s.display();

	cout << "Stack Peek : ";
	cout << s.peek() << endl;

	cout << "Stack  Size Become : ";
	cout << s.size() << endl;

	cout << "Is stack EMPTY?? ";
	cout << s.isEmpty() << endl;


	s.pop();
	s.pop();
	s.pop();

	cout << "Stack Become : ";
	s.display();

	cout << "Stack Peek : ";
	cout << s.peek() << endl;

	cout << "Stack  Size Become : ";
	cout << s.size() << endl;

	cout << "Is stack EMPTY?? ";
	cout << s.isEmpty() << endl;

	return 0;
}