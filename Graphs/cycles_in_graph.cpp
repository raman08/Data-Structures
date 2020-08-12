#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

// Class contanning all the methods for the graph
class Graph_Traversing {

	// NO. of vertices.
	int vertices;

	// Vector contanning the adjecent list.
	vector<vector<int> > adj;

	// Vector contanning the cost of the edges.
	vector<vector<int> > cost;


	// Private method to find cycles in directed graph.
	bool is_cyclic_directed_graph(int s, vector<bool> &visited, vector<bool> &res_stack) {


		// If vertex is not visited
		if (!visited[s]) {

			// Mark vertex as visited and fill it in recursive stack.
			visited[s] = true;
			res_stack[s] = true;

			// For each connected edge of the vertex
			for (auto i = adj[s].begin(); i != adj[s].end(); i++) {

				// If vetex is not visited and threre is cycle in next vertix.
				if (!visited[*i] && is_cyclic_directed_graph(*i, visited, res_stack))
					return true; // Return true.

				// else if vertex is in reverse stack return true
				else if (res_stack[*i])
					return true;
			}
		}

		// If vertex is visited and there is no cycle
		res_stack[s] = false; // Remove it from recursion stack
		return false; // return false

	}


	// Private method to find cycles in undirected graph.
	bool is_cyclic_undirected_graph (int s, vector<bool> &visited, int parent) {

		visited[s] = true; // Mark vertex as visited

		// for each edge in vertex.
		for (auto i = adj[s].begin(); i != adj[s].end(); i++) {

			// If node is not visited
			if (!visited[*i])
				return is_cyclic_undirected_graph(*i, visited, s); // Return if there is cycle in next vertex.

			// else if node is not its parent
			else if (*i != parent)
				return true; // return true

		}

		return false; // else return false

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
		adj[v - 1].push_back(u - 1);

		// Adding the cost of the graph.
		cost[u - 1].push_back(w);


	}


	// Method to find the cycles in directed graph.
	bool is_cyclic_directed_graph() {

		// Initialzing the visited and te recursive stack.
		vector<bool> visited(adj.size(), false);
		vector<bool> res_stack(adj.size(), false);

		// For each vertex in graph
		for(int i = 0; i < adj.size(); i++)
			 return is_cyclic_directed_graph(i, visited, res_stack); // Find if there is cycle in the graph or not.


		return false; // If there is no cycle return false.

	}


	// Method to find the cycles in directed graph.
	bool is_cyclic_undirected_graph() {

		// Initialzing the visited.
		vector<bool> visited(adj.size(), false);

		// For each vertex in graph
		for (int i = 0; i < adj.size(); i++){

			 // If vertex is not visited
			if (!visited[i]) {

				// return if there is cycle in the graph
				if ( is_cyclic_undirected_graph(i, visited, -1) ){
					return true;
				}
			}
		}


		return false; // if not return false.

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

	Graph_Traversing graph(3);

	// graph.addEdge(1, 4);
	// graph.addEdge(2, 4);
	// graph.addEdge(3, 4);
	// graph.addEdge(5, 4, 10);
	// graph.addEdge(6, 5);
	// graph.addEdge(6, 7);

	// graph.addEdge(1, 2);
	// graph.addEdge(1, 3);
	// graph.addEdge(2, 3);
	// graph.addEdge(4, 1);
	// graph.addEdge(4, 5);

	graph.addEdge(1, 2);
	graph.addEdge(2, 3);



	graph.display();


	// cout << "#########################" << endl;

	// cout << endl;

	// graph.BFS(3);

	cout << "#########################" << endl;

	// cout << graph.is_cyclic_directed_graph() << endl;

	cout << graph.is_cyclic_undirected_graph() << endl;




}