#include <iostream>
#include <climits>


using namespace std;

// Structure to store the proberties of the queue.
struct pq_item {

	int value; // Value of the item
	int priority; // Priority of the item

};

// Class containing all the methods related to Priority Queue.
class Priority_Queue_With_Array {

	pq_item*  priority_queue; // Variable to store priority queue.

	int count; // Variable to store size.
	int Max_Priority_INDEX; // Varizble to store the index of max priority item.

	int MAX_SIZE;

	// Private Function to find the index of the fgiven item.
	int find(int data) {

		// Iterating through all the item
		for (int i = 0; i < size(); i++) {

			if (priority_queue[i].value == data) // If data match then return the index of the element.
				return i;

		}

		return INT_MIN; // Else return the minimun integer.

	}

	// Function to change the Max_Priority_INDEX to required value if required.
	void get_Max_Priority_INDEX() {

		// If queue is not empty
		if (!isEmpty()){

			int Max_Priority = INT_MIN; // Create a temp variable to compare

			// Going throught all the element in the priority queue
			for (int i = 0; i < size(); i++) {

				// If change is needed
				if (Max_Priority < priority_queue[i].priority) {

					Max_Priority_INDEX = i; // Change the Max_Priority_INDEX
					Max_Priority = priority_queue[i].priority; // Changing the temp variable

				}

			}

		}

		// If queue is empty
		else
			Max_Priority_INDEX = -1; // Max_Priority_INDEX become -1.

	}


public:

	// Costructor to initilized the priority queue.
	Priority_Queue_With_Array() {

		MAX_SIZE = 10; // Initialzing teh maximun size of the array.

		priority_queue = new pq_item[MAX_SIZE]; // Initialzing the array.

		count = 0; // Variable to store the size of the array.
		Max_Priority_INDEX = -1; // Variable to store the index of the max priority element.

	};


	// Paramitrized Costructor to initilized the priority queue.
	Priority_Queue_With_Array(int MAX_SIZE) {

		priority_queue = new pq_item[MAX_SIZE]; // Initialzing the array with size given by User.

		count = 0; // Variable to store the size of the array.
		Max_Priority_INDEX = -1; // Variable to store the index of the max priority element.

	};

	// Deconstructor to free the space.
	~Priority_Queue_With_Array() {

		delete[] priority_queue; // deleting the  priority queue.

	}



	// Method to insrert the element in priority queue.
	void insert(int data, int weight) {

		if (isFull()) {
			cout << "ERROR: Queue overflow!!!" << endl;

			return;
		}

		priority_queue[count].value = data; // Adding data in value field.
		priority_queue[count].priority = weight; // Adding weight in the priority

		count++; // Incresing the size.

		// setting the index of the maximun priority element into Max_Priority_INDEX variable.
		if (priority_queue[Max_Priority_INDEX].priority <= weight)
			Max_Priority_INDEX = count - 1;

	}



	// Method to remove the element with maximun priority.
	void extract_max() {

		if (isFull()) {

			cout << " ERROR: Queue overflow!!!" << endl;

			return;
		}


		// If priority queue is not empty
		if (!isEmpty()) {

			// Shifting element by one place from Max_Priority_INDEX to size - 1
			for (int i = Max_Priority_INDEX; i < count - 1; i++) {

				priority_queue[i].value = priority_queue[i + 1].value; // Changing the value of the item.
				priority_queue[i].priority = priority_queue[i + 1].priority; // Changing the priority of the item.

			}

			count--; //  Decresing the size of the priority queue.

			get_Max_Priority_INDEX(); // Changing the Max_Priority_INDEX to required value.

		}


	}



	// Methid to remove the item with given value from the priority queue.
	void remove(int data) {

		// If priority queue is not empty
		if (!isEmpty()) {

			int idx = find(data); // Find the index of the element to remove.

			// If element is found then exit the function.
			if (idx >= 0 && idx < size()) {

				// Shifting element by one place from index of the given element to size - 1
				for (int i = idx; i < size(); i++) {

					priority_queue[i].value = priority_queue[i + 1].value; // Changing the value of the item.
					priority_queue[i].priority = priority_queue[i + 1].priority; // Changing the priority of the item.


				}

				count--; // Decresing the size of the priority queue.

				get_Max_Priority_INDEX(); // Changing the Max_Priority_INDEX to required value.


				remove(data); // Calling it recusively to delete all the element with same data.

			}

		}


	}

	// Method to change the priority of the given element to given priority.
	void change_priority(int data, int pri) {

		// If priority queue is not empty
		if (!isEmpty()) {

			int idx = find(data); // Find the index of the element with same data.

			// If such element exist the change the priority else exit the function
			if (idx >= 0 && idx < size() && priority_queue[idx].value == data) {

				priority_queue[idx].priority = pri; // Change the priority of the element.


			}

			get_Max_Priority_INDEX(); // // Changing the Max_Priority_INDEX to required value.

		}

	}



	// Method to get the value of element with maximun priority.
	int get_max() {

		if (Max_Priority_INDEX >= 0)
		 	return priority_queue[Max_Priority_INDEX].value;

		 return INT_MIN;

	}



	// Method to check if priority queue is empty.
	bool isEmpty() {
		return (count <= 0);
	}



	// Method to get the size of the priority queue.
	int size() {
		return count;
	}


	bool isFull() {
		return (count == MAX_SIZE);
	}



	// Method to display the priority queue.
	void display() {

		for (int i = 0; i < count; i++)
			cout << "(" << priority_queue[i].value << ", " << priority_queue[i].priority << ")" << "; ";

		cout << endl;

	}

};

int main () {

	Priority_Queue_With_Array pq;

	// cout << "Is priority queue empty? " << pq.isEmpty() << endl;

	// cout << "Size of priority queue is: " << pq.size() << endl;;

	// cout << endl;

	int i = 1;

	pq.insert(i, i);
	i++;
	pq.insert(i, 800);
	i++;
	pq.insert(i, 700);
	i++;
	pq.insert(i, 900);
	i++;
	pq.insert(i, i);
	pq.insert(i, i + 100);
	pq.insert(i, i + 200);

	i++;
	// pq.insert(i, 1000);
	// i++;
	// pq.insert(i, i);
	// i++;
	// pq.insert(i, 100);
	// i++;





	cout << "The priority queue become: ";
	pq.display();

	cout << "The max priority item is: " << pq.get_max() << endl;
	cout << "Size of priority queue is: " << pq.size() << endl;
	cout << endl;

	// pq.extract_max();

	// cout << "The priority queue become: ";
	// pq.display();

	// cout << "The max priority item is: " << pq.get_max() << endl;
	// cout << "Is priority queue empty? " << pq.isEmpty() << endl;
	// cout << "Size of priority queue is: " << pq.size() << endl;
	// cout << endl;




	// pq.remove(5);
	// pq.remove(2);

	// cout << "The priority queue become: ";
	// pq.display();

	// cout << "The max priority item is: " << pq.get_max() << endl;
	// cout << "Is priority queue empty? " << pq.isEmpty() << endl;
	// cout << "Size of priority queue is: " << pq.size() << endl;
	// cout << endl;

	pq.change_priority(5, 9000);

	cout << "The priority queue become: ";
	pq.display();

	cout << "The max priority item is: " << pq.get_max() << endl;



	return 0;

}