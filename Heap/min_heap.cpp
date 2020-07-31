#include <iostream>
#include <climits>

using namespace std;

// Class contaning all methods required in min-heap.
class MIN_Heap {

private:

	int* heap; // Variable to store the min-heap.

	int MAX_SIZE; // Variable to store max size of the heap.
	int count; // Variable to store current size of the heap.

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
			if (heap[i] == data)
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


	// Method to shift up the node of the from given child to rearrange the tree to heap.
	void shift_up(int child) {

		// while child value is smaller then the parent value
		while (( heap[parent(child)] > heap[child]) ) {

			swap(heap[parent(child)], heap[child]); // swap the value of the child and parents.

			child = parent(child); // Make parent of the given child as the new child

		}

	}



	// Method to shift down the node of the from given child to rearrange the tree to heap.
	void shift_down(int child) {

		int max_idx = child; // Store the given child index.

		int left = left_child(child); // Store the index of the left child

		// If left child index is smaller the heap size and left child value is smaller the the given value
		if (left < count  && heap[left] < heap[max_idx])
			max_idx = left; // Then max index become left child index

		int right = right_child(child); // Store the index of the right child

		// If right child index is smaller the heap size and right child value is smaller the the given value
		if (right < count && heap[right] < heap[max_idx])
			max_idx = right; // Then max index become right child index

		// While heap is not formed
		if (child != max_idx) {

			swap(heap[child], heap[max_idx]); // Swap the required nodes.

			shift_down(max_idx); // Recalling teh function.

		}
	}


public:

	// Condtructor for the creation of heap.
	MIN_Heap() {

		MAX_SIZE = 10; // Default max size of the heap.
		heap = new int [MAX_SIZE]; // Creating a new array for heap.

		count = 0; // Initialzing the size of the heap.

	}

	// Paramitrized Constructor for heap creation
	MIN_Heap(int si) {

		MAX_SIZE = si; // Set max size os given ny uset.
		heap = new int [MAX_SIZE]; // Creating a new array for heap.

		count = 0; // Initialzing the size of the heap.

	}


	// Deconstructor to delete the heap
	~MIN_Heap() {

		delete[] heap; // deleting the heap.

	}

	// Method to insert the values in the heap
	void insert(int data) {

		// If heap become full then return.
		if (isFull()) {

			cout << "Error: Heap overflow!!!!" << endl;
			return;

		}

		heap[count] = data; // Adding the data into  as a leaf in the heap.
		shift_up(count); // Shifting up to rearrange heap.

		count++; // Incresing the size of the haea.

	}

	// Method to remove and return the maximun element in the heap.
	int extract_min() {

		// I heap is not empty
		if (!isEmpty()) {

			int result = heap[0]; // Storing the maximun value in a variable.

			heap[0] = heap[count - 1]; // Replacing the root of heap with a leaf in heap.

			shift_down(0); // Shifting down the root.

			count--; // Decresing the size of the heap.

			return result; // returning the maximun value in the heap.

		}

		// If heap is empty return the maximin int value.
		return INT_MIN;

	}



	// Function to remove the given data from the heap.
	void remove(int data) {

		// If heap is empty return.
		if (isEmpty())
			return;

		// Fing the index if the data to be deleted.
		int child = find(data);

		// If data is present in the heap
		if (child >= 0 && child < count) {

			heap[child] = INT_MIN; // Replacing the data with maximun value of the integer.

			shift_up(child); // Shifting up to regrrange the heap

			extract_min(); // Extracting the maximin value from heap. (We ourself given the node to be removed the maximun value.)

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
		if (child >= 0 && child < count) {

			int old_priority = heap[child]; // Tempiory variable to store the old priority.

			heap[child] = pri; // Replace the data with given priority.

			// Shifting the heap according the need

			// If priority is greater then the data
			if (pri > old_priority)
				shift_up(child); // then shift up the heap.

			else
				shift_down(child); // Else shift down the heap.

			change_priority(data, pri); // Recursively replacing the data.

		}

	}



	// Function to return the maximun element of the heap.
	int get_min() {

		// If heap is empty
		if (isEmpty())
			return INT_MIN; // return the maximun int.

		return heap[0]; // else return first element of the heap;

	}



	// Function to return the size of the heap.
	int size() {
		return count;
	}


	// Function to find if heap is empty or not.
	bool isEmpty() {
		return (count == 0);
	}


	// Function to find if heap is full or not.
	bool isFull() {
		return (count == MAX_SIZE);
	}



	// Function to display the heap.
	void display() {

		for (int i = 0; i < size(); i++)
			cout << heap[i] << " ";

		cout << endl;
	}


};

// Main driver code
int main() {


	MIN_Heap mh;

	cout << "Heap size become: " << mh.size() << endl;
	cout << "Min Element is: " << mh.get_min() << endl;
	cout << endl;

	int i = 10;

	// mh.insert(i);
	// i--;
	// mh.insert(i);
	// i--;
	// mh.insert(i);
	// i--;
	// mh.insert(i);
	// // mh.insert(i);
	// // mh.insert(i);
	// // mh.insert(i);
	// i--;
	// mh.insert(i);
	// i--;
	// mh.insert(i);
	// i--;
	// mh.insert(i);
	// // mh.insert(i);
	// // mh.insert(i);
	// // mh.insert(i);
	// i--;
	// mh.insert(i);
	// i--;
	// mh.insert(i);
	// i--;
	// mh.insert(i);
	// i--;

	mh.insert(29);
	mh.insert(18);
	mh.insert(7);
	mh.insert(42);
	mh.insert(18);
	mh.insert(13);
	mh.insert(12);
	mh.insert(14);
	mh.insert(11);




	cout << "Heap become: ";
	mh.display();

	cout << "Heap size become: " << mh.size() << endl;
	cout << "Min Element is: " << mh.get_min() << endl;

	cout << endl;



	mh.extract_min();
	// cout << mh.extract_max() << endl << endl;

	cout << "Heap become: ";
	mh.display();

	cout << "Heap size become: " << mh.size() << endl;
	cout << "Min Element is: " << mh.get_min() << endl;

	cout << endl;



	mh.remove(10);

	cout << "Heap become: ";
	mh.display();

	cout << "Heap size become: " << mh.size() << endl;
	cout << "Min Element is: " << mh.get_min() << endl;

	cout << endl;

	mh.change_priority(8, 90);

	cout << "Heap become: ";
	mh.display();

	cout << "Heap size become: " << mh.size() << endl;
	cout << "Min Element is: " << mh.get_min() << endl;

	cout << endl;

	return 0;

}