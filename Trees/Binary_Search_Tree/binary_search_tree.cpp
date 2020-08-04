#include <iostream>
#include <vector>
#include <climits>

using namespace std;


// Node structure to contains the structure of the tree.
struct Node {

	int value; // Variable to store value

	Node* left; // Node pointer to the left child
	Node* right; // Node pointer to the right child.

};



// Class contanning all the method regarding the binary search tree.
class Binary_Search_Tree {

private:

	Node* root; // Root node of the tree.


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




	//Private method to check if the node with given value is present or noe.
	bool is_Present(int key, Node* leaf) {

		// If node has the value as the key, return true (base condition).
		if (leaf->value == key)
			return true;

		// If node has greater value then the key, go to the left.
		else if (leaf->value > key) {

			// If left is not null,
			if (leaf->left != NULL)
				return is_Present(key, leaf->left); // Recursive call to the left node of the tree.

			return false; // If left is null, return false.

		}


		// If node has smaller value then the key, go to the left.
		else if (leaf->value <= key) {

			// If left is not null,
			if (leaf->right != NULL)
				return is_Present(key, leaf->right);  // Recursive call to the right node of the tree.

			return false; // If right is null, return false.

		}

		else
			return false; // else return

	}



	// Private method to find the node contanning the same key as given by user.
	Node* find_node(int key, Node* leaf) {

		// If node has the value as the key, return node (base condition).
		if (leaf->value == key)
			return leaf;

		// If node has greater value then the key, go to the left.
		else if (leaf->value > key) {

			// If left is not null,
			if (leaf->left != NULL)
				return find_node(key, leaf->left); // Recursive call to the left node of the tree.

			return leaf; // If left is null, return node to which it must be attach.

		}

		// If node has smaller value then the key, go to the left.
		else if (leaf->value <= key) {

			// If left is not null,
			if (leaf->right != NULL)
				return find_node(key, leaf->right); // Recursive call to the left node of the tree.

			return leaf; // If left is null, return node to which it must be attach.

		}

		else
			return leaf; // else return node.

	}



	// Private method to find the node with the next largest value as compare to the given node.
	Node* next(Node* leaf) {

		// If leaf is null return NULL.
		if (leaf == NULL)
			return NULL;

		// Since we need to find the next largert value it will be the right subtree smallest value.

		// So if right node is not null
		if (leaf->right != NULL)
			return left_decendant(leaf->right); // SIng the smallest value in the right subtree.

		// If rightnode is null then we need to find the ansestor of the node.
		else
			return right_ancestor(leaf); // Find the right ansestors of the node.

	}


	// Private method to find the samllest value in given subtree.
	//         OR
	// Private method to find the find the node which is left-most of the given node.
	Node* left_decendant(Node* leaf) {

		// If given node is null return NULL.
		if (leaf == NULL)
			return NULL;

		// If node left child is null
		if (leaf->left == NULL)
			return leaf; // return node.

		// Else find the mininum node of the left subtree.
		else
			return left_decendant(leaf->left);

	}


	// Find the next node of the given node which has least greater key then the given node.
	Node* right_ancestor(Node* leaf) {

		// If given node is null return NULL.
		if (leaf == NULL)
			return NULL;

		// If node right child is not null
		if (leaf->right != NULL)
			return left_decendant(leaf->right); // Return the smallest node in the right subtree.


		Node* succ = NULL; // Node to store the sucessor node.

		Node* temp = root; // Temp variable to store the root.


		// While root is not null
		// OR untill we don't reach the root.
		while (temp != NULL) {

			// If leaf has smaller vaue then the temp search in left subtree.
			if (leaf->value < temp->value) {

				// Changing the variable
				succ = temp;
				temp = temp->left;

			}

			// / If leaf has smaller vaue then the temp search in right  subtree.
			else if (leaf->value > temp->value)
				temp = temp->right; // Changing required variable

			// When found break;
			else
				break;

		}

		// Return the sucessor
		return succ;

	}


	// Method to return the vector contanning the nodes whose value lies between given range.
	vector<Node*> range_search(int lower, int upper, Node* leaf) {

		vector<Node*> arr; // Vector to store the array.

		Node* lower_node = find_node(lower, leaf); // Find the node contanning the lower value

		Node* upper_node = find_node(upper, leaf); // Find the node contanning the upper value

		// While lower node value is less then the upper value.
		while (lower_node->value < upper_node->value) {

			// If lower node value is less ten thej upper, append the node to the vector.
			if (lower_node->value <= upper)
				arr.push_back(lower_node);

			lower_node = next(lower_node); // Finding the node with  least greater value then lower node.

		}

		return arr; // Returning the array.

	}




	// Method to remove the node with given key from tree.
	Node* remove(int key, Node* leaf) {

		// If leaf is NULL (base condition).
		if (leaf == NULL)
			return leaf; // Return the leaf


		// If key is smaller then the node value
		else if (key < leaf->value)
			leaf->left = remove(key, leaf->left); // Search in the left subtree.

		// If key is greater then the node value
		else if (key > leaf->value)
			leaf->right = remove(key, leaf->right); // Search in the right subtree.


		// When node to deleted is found ........
		else {


			// If tree only have right subtree
			if (leaf->left == NULL) {

				Node* temp = leaf->right; // Temporary store the right subtree.

				delete leaf; // delete the node

				return temp; // Return the temporary node.

			}

			// If tree only have right subtree
			else if (leaf->right == NULL) {

				Node* temp = leaf->left;  // Temporary store the right subtree.

				delete leaf; // delete the node

				return temp; // Return the temporary node.


			}

			Node* temp = left_decendant(leaf->right);

			leaf->value = temp->value;

			leaf->right = remove(temp->value, leaf->right);

		}

		return leaf;

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



public:

	// Constructor to initialzied the tree.
	Binary_Search_Tree() {

		root = NULL; // Initialzing the root as NULL.

	};

	// Deconstructor for the binary search tree.
	// ~Binary_Search_Tree();


	// Method to insert the value to the tree
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



	// Method to chech if the key is present in BST or not.
	bool is_Present(int key) {

		return is_Present(key, root); // Calling the parivate is_Present method.

	}


	// Function to remove the key from the binary search tree.
	void remove(int key) {

		root = remove(key, root); // Calling the private remvoe method.

	}

	// Method for the in-order traversal.
	void in_order_traversal() {

		in_order_traversal(root); // Calling the private in_order_traversal method.

	}

	// Method to find the adjoining least value of the given value.
	int left_decendant(int key) {

		// If key is present
		if (is_Present(key)) {

			Node* temp = left_decendant(find_node(key, root)); // Call the private left_decendant method

			return temp->value; // returning the value of the node.

		}

		// If key is not present
		else
			return INT_MIN; // return the -infinity.

	}


	// Method to find the least greatest value of the given value
	int right_ancestor(int key) {

		// If key is present
		if (is_Present(key)){

			Node* temp = right_ancestor(find_node(key, root)); // Call the private left_decendant method

			return temp->value; // returning the value of the node.
		}

		// If key is not present
		else
			return INT_MIN; // return the -infinity.

	}


	// Method to find all values present in the tree within specific range.
	vector<int> range_search(int lower, int upper) {

		vector<Node*> arr = range_search(lower, upper, root); // Calling the private range_search function.

		vector<int> range; // Vector to store value of the nodes.

		// Storing the value of the node in the range vector.
		for (int i = 0; i < arr.size(); i++)
			range.push_back(arr[i]->value);

		return range; // returning the range vector.

	}

};


// Main griver code
int main() {

	Binary_Search_Tree bst;

	bst.insert(50);
	bst.insert(30);
	bst.insert(20);
	bst.insert(40);
	bst.insert(70);
	bst.insert(60);
	bst.insert(80);
	// bst.insert(50);
	// bst.insert(50);

	cout << "In Order Travelsal: ";
	bst.in_order_traversal();
	cout << endl << endl;

	cout << "Is 20 present? " << bst.is_Present(20) << endl;
	cout << "Left Desendent of 70 is " << bst.left_decendant(70) << endl;
	cout << "Right Desendent of 40 is " << bst.right_ancestor(40) << endl;

	bst.remove(20);

	cout << "In Order Travelsal: ";
	bst.in_order_traversal();
	cout << endl << endl;

	cout << "Is 20 present? " << bst.is_Present(20) << endl;
	// cout << "Left Desendent of 100 is " << bst.left_decendant(100) << endl;

	cout << "All the element b/w 40 and 70 is: " ;

	vector<int> ptr = bst.range_search(41, 90);

	for (auto x : ptr)
		cout << x << " ";

	cout << endl;

	return 0;

}