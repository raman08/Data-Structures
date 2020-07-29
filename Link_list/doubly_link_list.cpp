#include <iostream>

using namespace std;

// Structue to store the node informations of link list.
// This is for doubely link list.
struct Node{

	int data;
	Node* next;
	Node* previous;

};

// Class for the doubly link list.
class Doubly_Link_List {

private:

	// This first pointer is for the head and last for tail.
	Node* head;
	Node* tail;

public:

	// Constructure for the link list.
	// Since its enpty both head and tail points to the null.
	Doubly_Link_List() {
		head = NULL;
		tail = NULL;
	}

	// Return the head node of link list
	Node* return_head() {
		return head;
	}

	// Return the tail node of link list
	Node* return_tail() {
		return tail;
	}

	/*
		############ Functions for inserting the element in the linked list ###########

	*/

	// Function to add the node at the end of the linked list
	// Time Complaxity = O(1)
	void push_front(int value) {

		Node* temp = new Node; // Creating a new node

		temp->data = value; // Adding data to the new node;

		temp->next = head; //Points the temp node to the NULL of list is empty otherwise point the temp node to the old first node.

		temp->previous = NULL; // Points the previous of the temp node to the null.

		if (head != NULL)
			head->previous = temp; // If list is not empty make previous of next node to the temp node.

		head = temp; // Points head to the temp

		if (temp->next == NULL)
			tail = temp;
	}





	// Function to add the node after a give position of the linked list
	// Time Complaxity = O(n)
	void push_after(int position, int value) {

		// Checking for the vaild position
		if (position < 0) {

			cout << "\nPlease enter a valid position.\n";

			return;
		}

		Node* temp = new Node; // Creating a new memory location for the new node.

		temp->data = value; // Putting teh data into new node

		temp->next = NULL; //Pointing the next to the null.

		if (position == 0) {
			temp->next = head;
			temp->previous = NULL;
			head = temp;

			return;
		}

		Node* temp_1 = head; // Creating a new node to store the position of (n-1)th node.

		// For loop to iterate to the n-2 th node;
		for (int i = 0; i < position - 1; i++) {
			temp_1 = temp_1->next;
		}

		temp->next = temp_1->next;  // Making next of teh temp to next of the temp_1;

		temp_1->next = temp; //Make the next of temp_1 as temp

		temp->previous = temp_1; //Make temp_1 as previous of temp.

		if (temp->next != NULL)
			temp->next->previous = temp; // Changing the previous of the temp node's next nede.


	}





	// Function to add the node at the end of the linked list without the tail
	// Time Complaxity = O(n)
	void push_back(int value) {

		Node* temp = new Node; // Creating a new memory location for the new node.

		Node* temp_1 = head; // For the iteration over the list as we directly can't use head.

		temp->data = value; // Adding the value to the data field.

		temp->next = NULL; // Pointing next to the null as its the last node.

		// If list is empty then adjusting the head node.
		if (head == NULL) {

			temp->previous = NULL; // making the temp previous to the null
			head = temp; // pointing head to the temp

			return;
		}

		// going to the last node.
		while (temp_1->next != NULL)
			temp_1 = temp_1->next;

		temp_1->next = temp; // Adding the temp to the list list

		temp->previous = temp_1; // Adjusting the previous of the temp.

		tail = temp;


	}





	void printLinkedList_recursion(Node* head) {

		if (head == NULL) // Exit condition
			return;

		cout << head->data << " "; // printing the data
		printLinkedList_recursion(head->next); // recursice call
	}

	void printLinkedList_reversed() {

		Node* temp = tail;

		while (temp != head) {
			cout << temp->data << " ";

			temp = temp->previous;

		}
	}




	// Delete the element from the first start of the link list.
	// Time Complaxity = O(1)
	void pop_front() {

		Node* temp = head;  // temp node to store head;

		head = temp->next; // pointing head to the next node (2nd node)

		delete temp; // deleting the 1st node.

	}

	// Delete the last node from given linked list from the back
	// Time Complaxity = O(n)
	void pop_back() {

		Node* temp = tail; // New node to store the last node of the linked list.

		tail = temp->previous; // Pointing tail to the second last node.

		delete temp; // Delete the last node of the linked list.

	}




};





// Main Driver Program.

int main() {

	Doubly_Link_List list;

	cout << "Enter the number of elements:\n";

	int n;
	cin >> n;

	cout << endl;

	// int first;
	// cin >> first;

	// list.push_back(first);

	for (int i = 0; i < n; ++i)
	{
		int input = 0;
		int position;

		cout << "\nEnter the " << i + 1 << " element: ";

		// cin >> position >> input;
		cin >> input;

		// list.push_after(position, input);
		list.push_back(input);

		cout << endl << "The list become: ";
		list.printLinkedList_recursion(list.return_head());
	}


	cout << endl << "The final list become: ";

	list.printLinkedList_recursion(list.return_head());

	cout << endl;

	// int d = 3;

	// while(d--) {
		list.pop_back();
	// }

	// cout << endl << "The final list become: ";

	list.printLinkedList_recursion(list.return_head());


	list.pop_front	();

	cout << endl << "The final list become: ";

	list.printLinkedList_reversed();

	// cout << endl;



	return 0;

}