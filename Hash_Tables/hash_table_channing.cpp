#include <iostream>
#include <list>
#include <climits>

using namespace std;

// Structure to store the key-value pair.
struct Pair {

	int key;
	int value;

};

// Class which contains all the method regarding hash tablels.
class Hash_Table_Channing {

	list<Pair>* table; // Variable to store table.

	int cardinality; // Maximun colomns of the table.

	int hash_a; // Hash function a
	int hash_b; // Hash function b.
	int hash_prime; // Hash function prime.

	int count; // Current no. of key-value pair.


	// Function to create the hashes.
	long long hash_function(int key) {

		return  ((hash_a * key + hash_b) % hash_prime) % cardinality;

	}


public:


	// Constructor for the hash functions.
	Hash_Table_Channing() {

		cardinality = 10; // Default cardinality.

		table = new list<Pair>[cardinality]; // Creating a array of the list of pair.

		hash_a = 34; // Hash function variable
		hash_b = 2; // Hash function variable
		hash_prime = 100153; // Hash function variable

		count = 0; // Current no. of key-value pair.

	};

	// Deconstructor for deleting hash table.
	~Hash_Table_Channing() {

		delete[] table;

	};

	// Method to add the key-value pair in hash table.
	void insert(int key, int value) {

		int index = hash_function(key); // Calculatig the hash of the key.

		table[index].push_back({key, value}); // Adding the key-value pair in the specific hash index of the table.

		count++; // Incresing the current size.

	}



	// Method to remove the pair from hash table.
	void remove(int key) {

		int index = hash_function(key); // Calculatig the hash of the key.

		list<Pair> :: iterator i; // Setting up the iterator

		// Finding the position of the pair in the list at specific array index.
		for (i = table[index].begin(); i != table[index].end(); i++) {

			if (i->key == key)
				break;

		}

		// If paur is found remove it.
		if (i != table[index].end()) {

			table[index].erase(i); // Deleting the pair.

			count--; // redicing the size.

		}

	}



	// method to find the value of the given key.
	int get_value(int key) {

		int index = hash_function(key); // Calculatig the hash of the key.

		// iterating through the list.
		for (auto x : table[index]) {

			// If key is found return the value.
			if (x.key == key)
				return x.value;

		}

		return INT_MIN; // else return -Infinity;

	}


	// Return the size of the hash table.
	int size() {

		return count;

	}


	// Function to display the hash table.
	void display() {

		for (int i = 0; i < cardinality; i++) {

			if (table[i].begin() == table[i].end())
				continue;

			cout << i;

			for (auto x : table[i])
				cout << " -->   " << x.key << ": " << x.value <<"    ";

			cout << endl;

		}

		cout << endl;

	}

};


// Main Drive code.
int main() {

	Hash_Table_Channing ht;

	cout << "\n Number of keys added: " << ht.size() << endl;

	ht.insert(5, 8);
	ht.insert(344, 8);
	ht.insert(235325, 8);
	ht.insert(34345234, 8);
	ht.insert(3245235, 8);
	ht.insert(8102001, 20011008);
	ht.insert(33543553, 7657);
	ht.insert(5343, 834543);
	ht.insert(34468, 8453);
	ht.insert(23435, 8768);
	ht.insert(3437884, 448);
	ht.insert(3267535, 85646);
	ht.insert(8654601, 2008);
	ht.insert(996553, 765657);

	ht.display();

	cout << "Value of " << 8102001 << " is " << ht.get_value(8102001) << endl;
	cout << "\n Number of keys added: " << ht.size() << endl;


	ht.remove(8102001);

	ht.display();

	cout << "Value of " << 8102001 << " is " << ht.get_value(8102001) << endl;
	cout << "\n Number of keys added: " << ht.size() << endl;

}