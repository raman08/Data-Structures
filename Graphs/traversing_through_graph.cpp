#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <stack>

using namespace std;

// Class contanning all the methods for the graph
class Graph_Traversing {

	// NO. of vertices.
	int vertices;

	// Vector contanning the adjecent list.
	vector<vector<int> > adj;

	// Vector contanning the cost of the edges.
	vector<vector<int> > cost;

	// Private function for the depth first search
	void DFS(int s, vector<bool> &visited) {

		visited[s] = true;

		cout << s + 1 << " ";

		for (auto i = adj[s].begin(); i != adj[s].end(); i++) {

			if (!visited[*i])
				DFS(*i, visited);

		}
	}


	//  Private Method to find the topological order in the graph.
	void topological_order(int s, vector<bool> &visited, stack<int> &ordering) {

		// Mark the node as visited
		visited[s] = true;

		// For all edges in the node
		for (auto i = adj[s].begin(); i != adj[s].end(); i++) {

			// If vertex is not visited
			if (!visited[*i])
				topological_order(*i, visited, ordering); // Recursive call the topologcal_order
		}

		ordering.push(s + 1); // If we found the sink push the vertex in the stack.

	}

public:


	// Graph initialzation
	Graph_Traversing(int vert) {

		// setting no of vertices.
		vertices = vert;

		// Resizing the vector.
		adj.resize(vertices);
		cost.resize(vertices);

	}


	// Method to add the edge in the graph.
	void addEdge(int u, int v, int w = 1) {

		// Checking for the right vertices.
		if (u > vertices || v > vertices)
			return;

		// Adding the edges of the graphs using adj list.
		adj[u - 1].push_back(v - 1);

		// For the bidirected graphs.
		// adj[v - 1].push_back(u - 1);

		// Adding the cost of the graph.
		cost[u - 1].push_back(w);


	}

	// Method to implement breadth first search in graph.
	void BFS(int s) {

		// Vector to mark if node is visited or not.
		vector<bool> visited(adj.size(), false);

		// Queue contaning the visited node.
		queue<int> Q;

		// Mark given node as visited and pushing it to queue.
		visited[s - 1] = true;
		Q.push(s - 1);

		// Traversing while loop is not empty.
		while (!Q.empty()) {

			// Computinng the first element
			s = Q.front();
			cout << s + 1 << " ";
			Q.pop();

			// Looping through the vertices and adding all the verties to vhich given vertix is attached.
			for (auto i = adj[s].begin(); i != adj[s].end(); i++) {

				// If vertix if not visited
				if (!visited[*i]) {

					// Then mark the vertix as visited and pushing it to the queue.
					visited[*i] = true;
					Q.push(*i);

				}
			}

		}

		cout << endl;

	}


	// Method to implement depth first search in graph
	void DFS(int s) {

		// Initialzing the visited vector
		vector<bool> visited(adj.size(), false);

		// Looping through all the node.
		for (int i = 0; i < adj.size(); i++) {

			// If node is not visited
			if (!visited[i])
				DFS(s - 1, visited); // DFS the node

		}

		cout << endl;

	}


	// Method to find the topolofical order in the graph.
	stack<int>  topological_order() {

		// Initialsizing the visited vector
		vector<bool> visited(adj.size(), false);

		// For storing the ordering.
		stack<int> ordering;

		// For all the vertex in the graph
		for (int i = 0; i < adj.size(); i++) {

			// If vertex is not visited
			if (!visited[i])
				topological_order(i, visited, ordering); // call the privete  topological_order

		}

		return ordering; // return the ordering.

	}




	// Method to display the graph.
	void display() {

		cout << "\nDisplaying graph with " << vertices << " vertices." << endl;

		for (int i = 0; i < vertices; i++){

			cout << "\nFor vertix: " << i + 1 << endl;

			cout << "Head";

			for (auto x : adj[i])
				cout << " -> " << x + 1;


			cout << endl;

		}
	}


};


// Main driver function.
int main() {

	// int v;
	// cin >> v;

	Graph_Traversing graph(4);

	graph.addEdge(1, 4);
	graph.addEdge(2, 4);
	graph.addEdge(3, 4);
	graph.addEdge(5, 4, 10);
	graph.addEdge(6, 5);
	graph.addEdge(6, 7);

	// graph.addEdge(1, 2);
	// graph.addEdge(1, 3);
	// graph.addEdge(2, 3);
	// graph.addEdge(3, 1);
	// graph.addEdge(3, 4);
	// // graph.addEdge(4, 4);
	// // graph.addEdge(3, 3);


	graph.display();


	// cout << "#########################" << endl;

	// cout << endl;

	// graph.BFS(3);

	cout << "#########################" << endl;

	// graph.DsbFS(3);


	stack<int> ordering = graph.topological_order();

	for (int i = 0; i < ordering.size(); i++) {

		cout << ordering.top() << " ";
		ordering.pop();

	}






}