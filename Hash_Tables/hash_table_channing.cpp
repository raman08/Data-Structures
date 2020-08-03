#include <iostream>
#include <list>
#include <climits>

using namespace std;

struct Pair {

	int key;
	int value;

};




class Hash_Table_Channing {

	list<Pair>* table;

	int cardinality;
	int chain_size;

	int hash_a;
	int hash_b;
	int hash_prime;

	int count;

	long long hash_function(int key) {

		return  ((hash_a * key + hash_b) % hash_prime) % cardinality;

	}


public:

	Hash_Table_Channing() {

		cardinality = 1000;
		table = new list<Pair>[cardinality];

		hash_a = 34;
		hash_b = 2;
		hash_prime = 100153;

		count = 0;

	};

	~Hash_Table_Channing() {

		delete[] table;

	};

	void insert(int key, int value) {

		int index = hash_function(key);

		table[index].push_back({key, value});

		count++;

	}

	void remove(int key) {

		int index = hash_function(key);

		list<Pair> :: iterator i;

		for (i = table[index].begin(); i != table[index].end(); i++) {

			if (i->key == key)
				break;

		}

		if (i != table[index].end())
			 table[index].erase(i);

		count--;

	}


	int get_value(int key) {

		int index = hash_function(key);

		for (auto x : table[index]) {

			if (x.key == key)
				return x.value;

		}

		return INT_MIN;

	}

	int size() {

		return count;

	}

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


int main() {

	Hash_Table_Channing ht;

	cout << "\n Number of keys added: " << ht.size() << endl;

	ht.insert(5, 8);
	ht.insert(344, 8);
	ht.insert(235325, 8);
	ht.insert(34345234, 8);
	ht.insert(3245235, 8);
	ht.insert(8102001, 20011008);

	ht.display();

	cout << "Value of " << 8102001 << " is " << ht.get_value(8102001) << endl;
	cout << "\n Number of keys added: " << ht.size() << endl;


	ht.remove(8102001);

	ht.display();

	cout << "Value of " << 8102001 << " is " << ht.get_value(8102001) << endl;
	cout << "\n Number of keys added: " << ht.size() << endl;

}