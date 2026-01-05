#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct Edge {
	int to;
	int weight;
};

struct Node {
	int value;
	int distance;

	bool operator<(const Node& other) const {
		return distance > other.distance;
	}
};

vector<int> dijkstra(int start, int nodesCount, unordered_map<int, vector<Edge>>& graph){
	vector<int> distances(nodesCount, INT_MAX);
	distances[start] = 0;

	priority_queue<Node> nextToProcess;
	nextToProcess.push({ start, 0 });

	while (!nextToProcess.empty()){
		auto currentNode = nextToProcess.top();
		nextToProcess.pop();

		if (currentNode.distance > distances[currentNode.value]){
			continue;
		}

		for (const auto& edge : graph[currentNode.value]){
			int newWeight = currentNode.distance + edge.weight;
			if (newWeight < distances[edge.to]){
				distances[edge.to] = newWeight;
				nextToProcess.push({ edge.to, newWeight });
			}
		}
	}

	return distances;

}
