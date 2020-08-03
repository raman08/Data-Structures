#include <iostream>
#include <climits>

using namespace std;

// Class contaning all the methods releated to hash tables
class Hash_Table_Direct_Addressing {

private:

	int* arr; // Arr to store hash tables;

	int MAX_SIZE; // Max size of the hash table.
	int count; // Current size of the hash table.


public:

	// Constructor for initalizing values
	Hash_Table_Direct_Addressing() {

		MAX_SIZE = 10; // default size of the hash tables.

		arr = new int[MAX_SIZE]; //Creating a new array.

		// Filling all the element of the array into default value,
		for (int i = 0; i < MAX_SIZE; i++)
			arr[i] = INT_MIN;


		count = 0; // initialzing the count.

	};

	// Deconstructor for deletng the hash tables.
	~Hash_Table_Direct_Addressing() {

		delete[] arr; // Dleleting the hash table.

	};


	// Method to insert the key and value into hash table.
	void insert(int key, int value) {

		arr[key] = value; // Filling the hash table  key index the value.

		count++; // Incresing the size.

	}



	// Method to remove the element of specific key.
	void remove(int key) {

		// If the key is avilable the decrese the size.
		if (arr[key] != INT_MIN)
			count--;

		arr[key] = INT_MIN; // Filling the hash table at key index with the  default value.

	}



	// Method to return the value of the specific key.
	int get_value(int key) {

		return arr[key];

	}



	// Method to return the size of the hash table.
	int size() {

		return count;

	}



	// Method to check if the hash table is empty or not?
	int isEmpty() {

		return count == 0;

	}


	// Method to display the hash table .
	void display() {

		for (int i = 0; i < MAX_SIZE; i++) {

			if (arr[i] != INT_MIN)
				cout << "Key: " << i << "\tValue: " << arr[i] << endl;

		}

		cout << endl;

	}

};


// Main Drive code.
int main() {

	Hash_Table_Direct_Addressing table;

	cout << "Size: " << table.size() << endl;
	cout << "Is Empyt :" << table.isEmpty() << endl;

	for (int i = 0; i < 9; i ++) {

		if (i % 2 == 0)
			continue;

		table.insert(i, i * 10);
	}

	cout << "Values inserted" << endl << endl;
	table.display();

	cout << "Size: " << table.size() << endl;
	cout << "Is Empyt :" << table.isEmpty() << endl;

	table.remove(1);
	table.remove(0);
	table.remove(8);

	cout << "Values deleted" << endl << endl;
	table.display();

	cout << "Get value Operations" << endl << endl;

	cout << table.get_value(3) << endl;
	cout << table.get_value(4) << endl;

	cout << "Size: " << table.size() << endl;
	cout << "Is Empyt :" << table.isEmpty() << endl;
	return 0;

}