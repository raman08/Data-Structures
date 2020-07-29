#include <iostream>
#include <climits>

using namespace std;


class Stack_With_Array {

	int top; // Current size of the stack
	int MAX_SIZE; // Max Size of the stack
	int* stack;

public:

	// Initial Constructor for the stabk.
	Stack_With_Array() {

		top = -1; // Current size of the stack.
		MAX_SIZE = 10; // Default size of the stack
		stack = new int [MAX_SIZE]; // Initialzing the array

	}



	// Parameterized Constructor for the stack.
	Stack_With_Array(int s) {

		top = -1;
		MAX_SIZE = s; // Max size given by the user.
		stack = new int [MAX_SIZE]; // Initialzing the array.

	}




/* 	################### Functions start Here ##################	*/



	// Function to add value to the stack.
	void push(int value) {

		// Checking if stack is full?
		if (isFull())
			cout << "ERROR: Stack Overflow !!!!" << endl;

		else
			stack[++top] = value; // Else add value to the apporiate postion.

	}



	// Function to add remove and return the last value of the stack.
	int pop() {

		// Checking if stack is Empty??
		if (isEmpty()) {
			cout << "ERROR: Stack Underflow!!!!" << endl; // Returning the error
			return INT_MIN;
		}


		return stack[top--]; // Else reducting the top pointer and returning teh value

	}




	// Function to return the last value of the stack.
	int peek(){

		// If stack is not empty return value at top
		if (!isEmpty())
			return stack[top];

		else
			return INT_MIN; // else return the -ve value.
	}




	// Function to check if stack is empty.
	bool isEmpty() {
		return (size() <= 0);
	}


	// Funciom to check if stack is Full.
	bool isFull() {
		return (size() >= MAX_SIZE);
	}



	// Function to return size of the stack.
	int size() {
		return top + 1;
	}



	// Function to print the stack.
	void display() {

		for (int i = 0; i < size(); i++)
			cout << stack[i] << " ";

		cout << endl;
	}

};







// Main driver function.
int main() {

	Stack_With_Array s(10);

	int i = 1;

	cout << "Is stack EMPTY?? ";
	cout << s.isEmpty() << endl;

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

	cout << "Is stack Full?? ";
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

	cout << "Is stack Full?? ";
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

	cout << "Is stack Full?? ";
	cout << s.isEmpty() << endl;

	return 0;
}