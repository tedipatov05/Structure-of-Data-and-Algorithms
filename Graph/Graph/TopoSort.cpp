#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Edge {
	int to;
	int weight;
};

void topologicalSort(int current,
	const unordered_map<int, vector<Edge>>& graph,
	vector<bool>& visited,
	stack<int>& topologicalSortStack) {

	visited[current] = true;
	if (graph.find(current) != graph.end()) {
		for (const auto& edge : graph.at(current)) {
			if (!visited[edge.to]) {
				topologicalSort(edge.to, graph, visited, topologicalSortStack);
			}
		}
	}

	topologicalSortStack.push(current);
}

vector<int> dagShortestPath(int start, int V, const unordered_map<int, vector<Edge>>& graph) {
	vector<int> distances(V, INT_MAX);
	distances[start] = 0;

	stack<int> topologicalSortStack;
	vector<bool> visited(V, false);

	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			topologicalSort(i, graph, visited, topologicalSortStack);
		}
	}

	while (!topologicalSortStack.empty()) {
		int u = topologicalSortStack.top();
		topologicalSortStack.pop();

		if (distances[u] != INT_MAX && graph.find(u) != graph.end()) {
			for (const auto& edge : graph.at(u)) {
				if (distances[u] + edge.weight < distances[edge.to]){
					distances[edge.to] = distances[u] + edge.weight;
				}
			}
		}
	}

	return distances;
}