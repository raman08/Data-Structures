#include <iostream>
#include <climits>

using namespace std;


// Structure to store the properties of the queue.
struct pq_item {

	int value; // Value of the item
	int priority; // Priority of the item

};


// Class contaning all methods required in priority-queue.
class Priority_Queue_Wih_MAX_Heap {

private:

	pq_item* priority_queue; // Variable to store the min-priority queue.

	int MAX_SIZE; // Variable to store max size of the priority queue.
	int count; // Variable to store current size of the priority queue.

	// Function to swap two varables.
	void swap(int& a, int& b) {

		int temp = a;
		a = b;
		b = temp;

	}


	// Function to find the index of the given data.
	int find(int data) {

		// Iterating through all the element
		for (int i = 0; i < count; i++) {

			// If element match return the index.
			if (priority_queue[i].value == data)
				return i;
		}

		return INT_MIN; // Else return minimun int.

	}



	// Method to find the parent index of given child
	int parent(int child) {
		return ((child - 1) / 2);
	}


	// Method to find the left child index of given child
	int left_child(int child) {
		return ((2 * child) + 1);
	}


	// Method to find the right child index of given child
	int right_child(int child) {
		return ((2 * child) + 2);
	}

	// Method to shift up the node of the from given child to rearrange the tree to priority queue.
	void shift_up(int child) {

		// while child value is greater then the parent value
		while ( priority_queue[parent(child)].priority < priority_queue[child].priority ) {

			swap(priority_queue[parent(child)].value, priority_queue[child].value); // swap the value of the child and parents.

			swap(priority_queue[parent(child)].priority, priority_queue[child].priority); // swap the value of the child and parents.

			child = parent(child); // Make parent of the given child as the new child

		}

	}

	// Method to shift down the node of the from given child to rearrange the tree to priority queue.
	void shift_down(int child) {

		int max_idx = child; // Store the given child index.

		int left = left_child(child); // Store the index of the left child

		// If left child index is smaller the priority queue size and left child value is greater the the given value
		if (left < count  && priority_queue[left].priority > priority_queue[max_idx].priority)
			max_idx = left; // Then max index become left child index

		int right = right_child(child); // Store the index of the right child

		// If right child index is smaller the priority queue size and right child value is greater the the given value
		if (right < count && priority_queue[right].priority > priority_queue[max_idx].priority)
			max_idx = right; // Then max index become right child index

		// While priority queue is not formed
		if (child != max_idx) {

			swap(priority_queue[child].value, priority_queue[max_idx].value); // Swap the required nodes.

			swap(priority_queue[child].priority, priority_queue[max_idx].priority); // Swap the required nodes.

			shift_down(max_idx); // Recalling teh function.

		}
	}


public:

	// Condtructor for the creation of priority queue.
	Priority_Queue_Wih_MAX_Heap () {

		MAX_SIZE = 10; // Default max size of the priority queue.
		priority_queue = new pq_item [MAX_SIZE]; // Creating a new array for priority queue.

		count = 0; // Initialzing the size of the priority queue.

	}

	// Paramitrized Constructor for priority queue creation
	Priority_Queue_Wih_MAX_Heap (int si) {

		MAX_SIZE = si; // Set max size os given ny uset.
		priority_queue = new pq_item [MAX_SIZE]; // Creating a new array for priority queue.

		count = 0; // Initialzing the size of the priority queue.

	}

	// Deconstructor to delete the priority queue
	~Priority_Queue_Wih_MAX_Heap () {

		delete[] priority_queue; // deleting the priority queue.

	}

	// Method to insert the values in the priority queue
	void insert(int data, int weight) {

		// If priority queue become full then return.
		if (isFull()) {

			cout << "Error: Priority Queue overflow!!!!" << endl;
			return;

		}

		priority_queue[count].value = data; // Adding the data into  as a leaf in the priority queue.

		priority_queue[count].priority = weight; // Adding the data into  as a leaf in the priority queue.

		shift_up(count); // Shifting up to rearrange priority queue.

		count++; // Incresing the size of the haea.

	}

	// Method to remove and return the maximun element in the priority queue.
	int extract_max() {

		// I priority queue is not empty
		if (!isEmpty()) {

			int result = priority_queue[0].value; // Storing the maximun value in a variable.

			priority_queue[0].value = priority_queue[count - 1].value; // Replacing the root of priority queue with a leaf in priority queue.
			priority_queue[0].priority = priority_queue[count - 1].priority; // Replacing the root of priority queue with a leaf in priority queue.

			shift_down(0); // Shifting down the root.

			count--; // Decresing the size of the priority queue.

			return result; // returning the maximun value in the priority queue.

		}

		// If priority queue is empty return the maximin int value.
		return INT_MAX;

	}



	// Function to remove the given data from the priority queue.
	void remove(int data) {

		// If priority queue is empty return.
		if (isEmpty())
			return;

		// Fing the index if the data to be deleted.
		int child = find(data);

		// If data is present in the priority queue
		if (child >= 0 && child < count) {

			priority_queue[child].priority = INT_MAX; // Replacing the data with maximun value of the integer.

			shift_up(child); // Shifting up to regrrange the priority queue

			extract_max(); // Extracting the maximin value from priority queue. (We ourself given the node to be removed the maximun value.)

			remove(data); // Recursively deleting the data.

		}

	}



	// Change the priority of given data with given priority.
	void change_priority(int data, int pri) {

		// If list is empty return.
		if (isEmpty())
			return;

		// Find the index of the given data.
		int child = find(data);

		// If data is avilable
		if (child >= 0 && child < count && priority_queue[child].value == data) {

			int old_priority = priority_queue[child].priority; // Tempiory variable to store the old priority.

			priority_queue[child].priority = pri; // Replace the data with given priority.

			// Shifting the priority queue according the need

			// If priority is greater then the data
			if (pri > old_priority) {

				cout << "shift_up!!!";
				shift_up(child); // then shift up the priority queue.
			}

			else {

				cout << "shift_down!!!!";
				shift_down(child); // Else shift down the priority queue.
			}

			// change_priority(data, pri); // Recursively replacing the data.

		}

	}



	// Function to return the maximun element of the priority queue.
	int get_max() {

		// If priority queue is empty
		if (isEmpty())
			return INT_MAX; // return the maximun int.

		return priority_queue[0].value; // else return first element of the priority queue;

	}



	// Function to return the size of the priority queue.
	int size() {
		return count;
	}


	// Function to find if priority queue is empty or not.
	bool isEmpty() {
		return (count == 0);
	}


	// Function to find if priority queue is full or not.
	bool isFull() {
		return (count == MAX_SIZE);
	}



	// Function to display the priority queue.
	void display() {

		for (int i = 0; i < size(); i++)
			cout << "(" << priority_queue[i].value << ", " << priority_queue[i].priority << "); ";

		cout << endl;
	}


};

// Main driver code
int main() {


	Priority_Queue_Wih_MAX_Heap mh;

	cout << "Priority Queue size become: " << mh.size() << endl;
	cout << "Max Element is: " << mh.get_max() << endl;
	cout << endl;

	int i = 1;

	mh.insert(i, i);
	i++;
	mh.insert(i, i);
	i++;
	mh.insert(i, i);
	i++;
	mh.insert(i, i);
	mh.insert(i, i);
	mh.insert(i, i);
	mh.insert(i, i);

	i++;
	mh.insert(i, i);
	i++;
	mh.insert(i, i);
	i++;
	mh.insert(i, i);
	// mh.insert(i);
	// mh.insert(i);
	// mh.insert(i);
	i++;
	// mh.insert(i, i);
	// i++;
	// mh.insert(i, i);
	// i++;
	// mh.insert(i, i);
	// i++;

	// mh.insert(29);
	// mh.insert(18);
	// mh.insert(7);
	// mh.insert(42);
	// mh.insert(18);
	// mh.insert(13);
	// mh.insert(12);
	// mh.insert(14);
	// mh.insert(11);




	cout << "Priority Queue become: ";
	mh.display();

	cout << "Priority Queue size become: " << mh.size() << endl;
	cout << "Max Element is: " << mh.get_max() << endl;

	cout << endl;

	cout << mh.extract_max() << endl << endl;
	// cout << mh.extract_max() << endl << endl;

	cout << "Priority Queue become: ";
	mh.display();

	cout << "Priority Queue size become: " << mh.size() << endl;
	cout << "Max Element is: " << mh.get_max() << endl;

	cout << endl;

	mh.remove(4);

	cout << "Priority Queue become: ";
	mh.display();

	cout << "Priority Queue size become: " << mh.size() << endl;
	cout << "Max Element is: " << mh.get_max() << endl;

	cout << endl;

	mh.change_priority(5, 900);

	cout << "Priority Queue become: ";
	mh.display();

	cout << "Priority Queue size become: " << mh.size() << endl;
	cout << "Max Element is: " << mh.get_max() << endl;

	cout << endl;

	return 0;

}