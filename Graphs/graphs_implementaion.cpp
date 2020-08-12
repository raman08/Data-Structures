#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Class contanning all the methods for the graph
class Graph {

	// NO. of vertices.
	int vertices;

	// Vector contanning the adjecent list.
	vector<vector<int> > edges;

	// Vector contanning the cost of the edges.
	vector<vector<int> > cost;

public:


	// Graph initialzation
	Graph(int vert) {

		// setting no of vertices.
		vertices = vert;

		// Resizing the vector.
		edges.resize(vertices);
		cost.resize(vertices);

	}


	// Method to add the edge in the graph.
	void addEdge(int u, int v, int w = 1) {

		// Checking for the right vertices.
		if (u > vertices || v > vertices)
			return;

		// Adding the edges of the graphs using adj list.
		edges[u - 1].push_back(v - 1);

		// For the bidirected graphs.
		edges[v - 1].push_back(u - 1);

		// Adding the cost of the graph.
		cost[u - 1].push_back(w);


	}

	// Method to retirn all the vertices attached to the given vertices.
	vector<int> adj_vertices(int v) {

		//If vertix is not define return NULLL vector
		if (v > vertices)
			return {};

		// Else return the required vector.
		return edges[v - 1];

	}

	// Method to find the cost of the given edge.
	int edge_cost(int u, int v) {
		// Checking for the right vertices.
		if (u > vertices || v > vertices)
			return INT_MIN;

		// Finding the position of the edge and returning the cost.
		for (int i = 0; i < edges[u - 1].size(); i++)
			if (edges[u - 1][i] == v - 1) {

				return cost[u - 1][i];

			}

		// If edge is not found return INT_MIN
		return INT_MIN;



	}




	// Method to display the graph.
	void display() {

		cout << "\nDisplaying graph with " << vertices << " vertices." << endl;

		for (int i = 0; i < vertices; i++){

			cout << "\nFor vertix: " << i + 1 << endl;

			cout << "Head";

			for (auto x : edges[i])
				cout << " -> " << x + 1;


			cout << endl;

		}
	}


};


// Main driver function.
int main() {

	int v;
	cin >> v;

	Graph graph(v);

	graph.addEdge(1, 4);
	graph.addEdge(2, 4);
	graph.addEdge(3, 4);
	graph.addEdge(5, 4, 10);
	graph.addEdge(6, 5);
	graph.addEdge(6, 7);

	graph.display();


	cout << "#########################" << endl;

	cout << endl;


	for (auto x : graph.adj_vertices(8))
		cout << x + 1 << " ";

	cout << endl;


	cout << graph.edge_cost(5, 4);


}