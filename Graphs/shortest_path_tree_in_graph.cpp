#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;


// Class contanning all the methods for the graph
class Graph_Path {

	// NO. of vertices.
	int vertices;

	// Vector contanning the adjecent list.
	vector<vector<int> > adj;

	// Vector contanning the cost of the edges.
	vector<vector<int> > cost;




	vector<int> shortest_path_tree(int s) {

		vector<int> dist(adj.size(), INT_MAX);
		vector<int> prev(adj.size(), INT_MIN);

		dist[s] = 0;

		queue<int> Q;

		Q.push(s);

		while (!Q.empty()) {

			int u = Q.front();
			Q.pop();

			for (auto i = adj[u].begin(); i != adj[u].end(); i++) {

				if (dist[*i] == INT_MAX) {

					Q.push(*i);

					dist[*i] = dist[u] + 1;
					prev[*i] = u;

				}
			}
		}

		return prev;

	}



public:


	// Graph initialzation
	Graph_Path(int vert) {

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



	vector<int> path(int s, int e) {

		s -= 1;
		e -= 1;

		auto prev = shortest_path_tree(s);

		vector<int> result;

		while (e != s) {

			result.push_back(e);

			e = prev[e];

		}

		reverse(result.begin(), result.end());

		return result;

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

	Graph_Path graph(6);

	graph.addEdge(1, 4);
	graph.addEdge(2, 4);
	graph.addEdge(3, 4);
	graph.addEdge(5, 4, 10);
	graph.addEdge(6, 5);
	graph.addEdge(6, 7);

	// graph.addEdge(1, 2);
	// graph.addEdge(1, 3);
	// graph.addEdge(2, 3);
	// graph.addEdge(4, 1);
	// graph.addEdge(4, 5);

	// graph.addEdge(1, 2);
	// graph.addEdge(2, 3);

	graph.display();

	cout << "#########################" << endl;

	auto result = graph.path(1, 6);

	for (auto x: result)
		cout << x << " ";

}