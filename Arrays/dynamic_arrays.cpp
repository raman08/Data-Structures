#include <iostream>
#include <climits>

using namespace std;

// Class contaning all the methods for the dynamic array.
class Dynamic_Arrays {

	int MAX_SIZE; // Variable for the maximum size of the array
	int capicity; // Variable for the current size of the array
	int* arr; // Pointer for storing array.

public:

	// Constructor for the array.
	Dynamic_Arrays() {

		MAX_SIZE = 1; // Setting maximn size to one.
		capicity = 0; // Setting current size to 0
		arr = new int [MAX_SIZE]; // Creating array of maximun size

	};


	// Destructor for the array.
	~Dynamic_Arrays() {

		delete[] arr; // Seleting the entire array.

	};



	// Funtion for adding value in the array.
	void push_back(int value) {

		// If size become equal to maximun size the increse the maximin size
		if (capicity == MAX_SIZE) {

			int* new_arr = new int [2 * MAX_SIZE]; // Creating a temporary array of double mazimun size.

			// Copping the elements from old array to new array.
			for (int i = 0; i < capicity; i++)
				new_arr[i] = arr[i];

			delete arr; // deleting the old array

			arr = new_arr; // Renaming the new array as old array.
			MAX_SIZE *= 2; // Incresing the maximum size of the array;

		}

		arr[capicity++] = value; // Adding value to the array and increasing current size.

	}



	// Function to remove the element at secific index from array.
	void pop_back(int idx) {

		// Checking if index is within the range.
		if (idx < 0 || idx >= capicity) {

			cout << "ERROR: index" << idx << "out of range";
			return;
		}

		// Removing the element by overriding at the given index.
		for (int j = idx; j < capicity - 1; j++)
			arr[j] = arr[j + 1];

		capicity--; // Decresing the current size of the array

	}



	// Function to get the value of specific index in array.
	int get(int idx) {

		// Checking if index is within the range.
		if (idx < 0 || idx >= capicity)
			return INT_MIN;


		return arr[idx]; // Returning value at given index.

	}




	// Function to set the given value at given index.
	void set(int idx, int value) {

		// Checking if index is within the range.
		if (idx < 0 || idx >= capicity) {

			cout << "ERROR: index" << idx << "out of range";
			return;
		}

		arr[idx] = value; // Setting the value at given index.

	}


	// Function to return the  current size of the array.
	int size() {
		return capicity;
	}


	// Function to display the array.
	void diaplay() {

		for (int i = 0; i < capicity; i++)
			cout << arr[i] << " ";

		cout << endl;

	}


};


// Main driver code
int main() {

	Dynamic_Arrays a;

	int i = 1;

	a.push_back(i);
	i++;
	a.push_back(i);
	i++;
	a.push_back(i);
	i++;
	a.push_back(i);
	i++;
	a.push_back(i);
	i++;
	a.push_back(i);
	i++;
	a.push_back(i);
	i++;
	a.push_back(i);
	i++;

	cout << "Array become: ";
	a.diaplay();

	cout << "Array Size become: " << a.size() << endl << endl;


	a.pop_back(1);
	a.pop_back(2);
	a.pop_back(3);


	cout << "Array become: ";
	a.diaplay();

	cout << "Array Size become: " << a.size() << endl << endl;

	cout << "Get result: " << a.get(0) << endl;
	cout << "Get result: " << a.get(1) << endl;
	cout << "Get result: " << a.get(2) << endl;
	cout << endl;

	a.set(0, 10);
	a.set(1, 20);
	a.set(2, 30);

	cout << "Array become: ";
	a.diaplay();

	cout << "Array Size become: " << a.size() << endl << endl;


	cout << "Get result: " << a.get(0) << endl;
	cout << "Get result: " << a.get(1) << endl;
	cout << "Get result: " << a.get(2) << endl;
	cout << endl;


}