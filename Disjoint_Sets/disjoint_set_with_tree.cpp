#include <iostream>

using namespace std;


// The root of the each tree is the ID of the set.

// Class contaning all the methods for the disjoint set.
class Disjoint_Set_With_Tree {

	int* parent; // Variable to store parent of the each node (represented by the index of the array).

	int* rank; // Variable to store height of each subtree.

	int MAX_SIZE; // Maximum size of the array.

public:

	// Default constructor for the disjoint set.
	Disjoint_Set_With_Tree() {

		MAX_SIZE = 10; // Default size of the array.

		parent = new int [MAX_SIZE]; // Array for storing the parents.

		rank = new int [MAX_SIZE]; // Array for storing height of each subtree.

	};


	// Parameterized Constructor for the disjoint set.
	Disjoint_Set_With_Tree(int size) {

		MAX_SIZE = size; // Default size of the array.

		parent = new int [MAX_SIZE]; // Array for storing the parents.

		rank = new int [MAX_SIZE]; // Array for storing height of each subtree.

	};



	// Deconsetuctor for deleting the disjointed set
	~Disjoint_Set_With_Tree() {

		delete[] parent; // deleting the parent array.

		delete[] rank; // deleting the rank array.

	};



	// Method to make the singleton set.
	void make_set(int u) {

		parent[u] = u; // Creating a singleton set.
		rank[u] = 0; // Setting initial height of each subtree to zero.

	}

	// Method to find the ID of the set in which given element is present.
	int find(int u) {

		// While root is not found
		while (u != parent[u])
			u = parent[u]; // Go to a higher level in the tree.

		return u; // When root is found return root

	}

	// Method to find the ID of the given node and also updated the root of the deeper node to attach directly to the root.
	int find_path_compression(int u) {

		// If the node is not the root
		if (u != parent[u])
			parent[u] = find_path_compression(parent[u]); // Set the parent of the node to the  root of parent of the node.

		return parent[u]; // return the parent of the node.

	}


	// Method to joint the 2 set with given elements with help of the rank.
	void union_by_rank(int u, int v) {

		int u_id = find_path_compression(u); // Finding ID of the first element.
		int v_id = find_path_compression(v); // Finding ID of the second element.


		// If ID is valid....
		if (u_id >= 0 && v_id >= 0) {

			// If ID is same then the set are already joint.
			if (u_id == v_id)
				return; // return from the function.

			// If ID is not common then they are different set..

			// Finding the tree with smaller height and merging it with the larger tree.
			if (rank[u_id] > rank[v_id])
				parent[v_id] = u_id;

			else {

				parent[u_id] = v_id;

				// IF height of tree is same
				if (rank[u_id] == rank[v_id])
					rank[v_id] += 1; // Increse it by 1.

			}

		}

	}


	// Methods to check if two element is in same set.
	bool same_set(int u, int v) {
		return (find(u) == find(v));
	}


	// Function to display the disjoint set.
	void display() {

		for (int i = 0; i < MAX_SIZE; i++)
			cout << "For index: " << i << "   Parent is: " << parent[i] << "   Rank is: " << rank[i] << endl;

		cout << endl;

	}


};



int main() {

	Disjoint_Set_With_Tree set(7);

	set.make_set(1);
	set.make_set(2);
	set.make_set(3);
	set.make_set(4);
	set.make_set(5);
	set.make_set(6);

	cout << "Set become: " << endl << endl;
	set.display();

	set.union_by_rank(2, 4);
	set.union_by_rank(5, 2);
	set.union_by_rank(3, 1);
	set.union_by_rank(2, 3);
	set.union_by_rank(2, 6);

	cout << "Set become: " << endl << endl;
	set.display();

}