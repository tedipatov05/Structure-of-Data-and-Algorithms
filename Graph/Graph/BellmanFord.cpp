#include <iostream>
#include <vector>
using namespace std;

struct Edge{
	int from;
	int to;
	int weight;
};

vector<int> bellmanFord(int start, int nodesCount, const vector<Edge>& edges){
	vector<int> distances(nodesCount, INT_MAX);
	distances[start] = 0;

	for (int i = 0; i < nodesCount; i++) {
		for (const auto& edge: edges){
			if (distances[edge.from] != INT_MAX && distances[edge.from] + edge.weight < distances[edge.to]) {
				distances[edge.to] = distances[edge.from] + edge.weight;
			}
		}
	}

	for (const auto& edge : edges){
		if (distances[edge.from] != INT_MAX && distances[edge.from] + edge.weight < distances[edge.to]){
			throw std::logic_error("Negative cycle");
		}
	}

	return distances;
}