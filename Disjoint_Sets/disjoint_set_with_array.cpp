#include <iostream>

using namespace std;

// In disjoint set we use the smallest element of the set as its unique ID.

// Class contaning all the methods for the disjoint set.
class Disjoint_Set_With_Array {

	int* smallest; // Array representing the disjoint set. We use the indexes of the array as the element and it store the minimun element of the set.

	int MAX_SIZE; // Stores the maximun size of the array.


	// Function to find the minimun of the given integers.
	int min(int a, int b) {

		if (a < b)
			return a;

		return b;

	}

public:


	// Default constructor for the disjoint set.
	Disjoint_Set_With_Array() {

		MAX_SIZE = 10; // Default size of the array.

		smallest = new int [MAX_SIZE]; // Initialzing the array.

		// for (int i = 0; i < MAX_SIZE; i++)
		// 	smallest[i] = -1;

	}


	// Parameterized Constructor for the disjoint set.
	Disjoint_Set_With_Array(int size) {

		MAX_SIZE = size; // User defined value.

		smallest = new int [MAX_SIZE];  // Initialzing the array.

		// for (int i = 0; i < MAX_SIZE; i++)
		// 	smallest[i] = -1;

	}



	// Deconsetuctor for deleting the disjointed set
	~Disjoint_Set_With_Array() {

		delete[] smallest; // Deleting the array.

	};



	// Method to make the singleton set.
	void make_set(int u) {

		smallest[u] = u; // Creating a singleton set.

	}



	// Method to find the ID of the set in which given element is present.
	int find(int u) {

		return smallest[u]; // Returning the ID.

	}



	// Method to joint the 2 set with given elements.
	void union_set(int u, int v) {

		int u_id = find(u); // Finding ID of the first element .
		int v_id = find(v); // Finding ID of the second element.

		// If ID is valid....
		if (u_id >= 0 && v_id >= 0) {

			// If ID is same then the set are already joint.
			if (u_id == v_id)
				return; // return from the function.


			// If ID is not common then they are different set..

			// Finding minimun ID.
			int min_id = min(u_id, v_id);


			// Giving all the element in the two given set the same id...

			// For all the element in set
			for (int i = 0; i < MAX_SIZE; i++) {

				// If the right set is found
				if (smallest[i] == u_id || smallest[i] == v_id) {

					smallest[i] = min_id; // Change the id..

				}
			}
		}
	}

	// Methods to check if two element is in same set.
	bool same_set(int u, int v) {
		return (find(u) == find(v));
	}


	// Function to display the disjoint set.
	void display() {

		for (int i = 1; i < MAX_SIZE; i++)
			cout << i << ": " << smallest[i] << endl;

		cout << endl;

	}

};


int main() {

	Disjoint_Set_With_Array set;

	set.make_set(1);
	set.make_set(2);
	set.make_set(3);
	set.make_set(4);
	set.make_set(5);
	set.make_set(6);
	set.make_set(7);
	set.make_set(8);
	set.make_set(9);


	cout << endl;
	cout << "Set become: " << endl;
	set.display();

	set.union_set(9, 3);
	set.union_set(2, 4);
	set.union_set(4, 7);
	set.union_set(9, 2);

	set.union_set(5, 5);

	set.union_set(6, 1);
	set.union_set(8, 6);

	cout << endl;
	cout << "Set become: " << endl;
	set.display();


	cout <<  set.same_set(9, 3) << "   " << set.same_set(5, 6);


	// set.union_set(9, 1);

	// cout << endl;
	// cout << "Set become: " << endl;
	// set.display();


}