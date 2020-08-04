#include <iostream>
#include <queue>

using namespace std;


// Structure to store the tree nodes
struct Node {

	int value; // Value at that node
	Node* left; // Pointer to the left node
	Node* right; // Pointer to the right node

};



// Class to store all the methods of the binary tree.
class Binary_Tree {

private:

	Node* root; // Root Node for the tree



	// Private function to delete the tree
	void destory_tree(Node* leaf) {

		// If tree is not NULL
		if (leaf != NULL) {

			destory_tree(leaf->left); // Delete the left tree
			destory_tree(leaf->right); // Delete the right tree

			delete leaf; // Delete the node.

		}
	}

	//  Private Function to insert the node to the tree.
	void insert(int key, Node* leaf) {

		// If value if less then the parent node then store it to the left node
		if (key < leaf->value) {

			// If node is already exist then insert a new node
			if (leaf->left != NULL)
				insert(key, leaf->left); // Inserting a new node

			// If there a not a node then create a new node
			else {

				leaf->left = new Node; // Creating a new node to the left of the parent node

				leaf->left->value = key; // Adding a value to the node

				leaf->left->left = NULL; // Assigning left of the new node to NULL
				leaf->left->right = NULL; // Assigning right of new node to NULL
			}

		}

		// If value if less then the parent node then store it to the left node
		else if (key >= leaf->value) {

			// If node is already exist then insert a new node
			if (leaf->right != NULL)
				insert(key, leaf->right); // Inserting a new node

			// If there a not a node then create a new node
			else {

				leaf->right = new Node; // Creating a new node to the left of the parent node

				leaf->right->value = key; // Adding a value to the node

				leaf->right->left = NULL; // Assigning left of the new node to NULL
				leaf->right->right = NULL; // Assigning right of new node to NULL
			}

		}
	}



	// Private function to compute the height of the tree
	int height(Node* leaf) {

		// If root is null then height is 0.
		if (leaf == NULL)
			return 0;

		return 1 + max(height(leaf->left), height(leaf->right)); // Else height is 1 (root) + maximum of the height of left node and right node

	}



 	// Private function for the in-order traversal.
 		//First operate in the left node then the root and then right node

		//  <Left Node> <Root Node> <Right Node>
	void in_order_traversal(Node* leaf) {

		// If leaf become NULL then return
		if (leaf == NULL)
			return;

		in_order_traversal(leaf->left); // Calling in-order traversal on the left node of the tree

		cout << leaf->value << " "; // Do any computational you want....

		in_order_traversal(leaf->right); // Calling in-order traversal on the right node of the tree

	}

/* ######################## Depth first traversal ##########################*/

	// Private function for the pre-order traversal.
 		//First operate in the root then the left node and then right node

		// <Root Node> <Left Node> <Right Node>
	void pre_order_traversal(Node* leaf) {

		// If leaf become NULL then return
		if (leaf == NULL)
			return;

		cout << leaf->value << " "; // Do any computational you want....

		pre_order_traversal(leaf->left); // Calling in-order traversal on the left node of the tree
		pre_order_traversal(leaf->right); // Calling in-order traversal on the right node of the tree
	}



	// Private function for the post-order traversal.
 		//First operate in the left node then the right node and then root

		//  <Left Node> <Right Node> <Root Node>
	void post_order_traversal(Node* leaf) {

		// If leaf become NULL then return
		if (leaf == NULL)
			return;

		post_order_traversal(leaf->left); // Calling in-order traversal on the left node of the tree
		post_order_traversal(leaf->right); // Calling in-order traversal on the right node of the tree

		cout << leaf->value << " "; // Do any computational you want....

	}



/* ######################## Breadth first traversal ##########################*/


	// Private function for the level-order traversal.
	void level_order_traversal(Node* leaf) {

		// If leaf is NULL then return
		if (leaf == NULL)
			return;

		queue<Node*> Q; // Queue to store the node address of the childern of the passing node

		Q.push(leaf); // Inserting the first (root) node to the queue.


		// Loop while queue is empty do the following process
		while (!Q.empty()) {

			Node* current = Q.front(); // Variable to store the first value of the queue.

			cout << current->value << " "; // Do any computational you want....

			// If left chilren is not NULL then add it to the queue.
			if (current->left != NULL)
				Q.push(current->left);

			// If right chilren is not NULL then add it to the queue.
			if (current->right != NULL)
				Q.push(current->right);

			Q.pop(); // Removing the first value of the queue.

		}
	}


public:

	// Constructor for initialzing the tree.
	Binary_Tree() {

		root = NULL;

	}

	// Deconstructor for the deletion of the tree
	~Binary_Tree() {

		destory_tree(); // Function to delete tree

	}


	// Function to delete the tree
	void destory_tree() {

		destory_tree(root); // Calling the private destory_tree function.

	}



	// Function to insert the value to the tree
	void insert(int key) {

		// If root already exist then call the private insert function.
		if (root != NULL)
			insert(key, root);

		// if root not exist then create a new node
		else {

			root = new Node; // Creating a new node for the root node

			root->value = key; // Adding a value to the node

			root->left = NULL; // Assigning left of the new node to NULL
			root->right = NULL; // Assigning right of new node to NULL

		}

	}



	// Function to compute the height of the tree
	int height() {

		return height(root); // Calling the private height function.

	}



	// Function for the in-order traversal.
	void in_order_traversal() {

		in_order_traversal(root); // Calling the private in_order_traversal function.
	}



	// Function for the pre-order traversal.
	void pre_order_traversal() {

		pre_order_traversal(root); // Calling the private pre_order_traversal function.
	}



	// Function for the post-order traversal.
	void post_order_traversal() {

		post_order_traversal(root); // Calling the private post_order_traversal function.

	}



	// Function for the post-order traversal.
	void level_order_traversal() {

		level_order_traversal(root); // Calling the private level_order_traversal function.

	}

};



// Main function for the program
int main() {

	Binary_Tree bt;

	// Binary_Tree *bt = new Binary_Tree();

	bt.insert(10);
	bt.insert(9);
	bt.insert(11);
	bt.insert(8);
	bt.insert(12);
	bt.insert(10);
	bt.insert(14);
	bt.insert(13);
	bt.insert(6);
	bt.insert(9);
	bt.insert(2);
	bt.insert(4);



	cout << "height of the tree: " << bt.height() << endl << endl;

	cout << "In Order Travelsal: ";
	bt.in_order_traversal();
	cout << endl << endl;

	cout << "Pre Order Travelsal: ";
	bt.pre_order_traversal();
	cout << endl << endl;

	cout << "Post Order Travelsal: ";
	bt.post_order_traversal();
	cout << endl << endl;

	cout << "Level Order Travelsal: ";
	bt.level_order_traversal();
	cout << endl << endl;

	return 0;

}