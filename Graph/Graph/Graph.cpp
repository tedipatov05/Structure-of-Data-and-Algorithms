#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
	int V;
	bool directed;
	unordered_map<int, unordered_set<int>> adjList; 

public:
	Graph(int vertices, bool isDirected = false) : V(vertices), directed(isDirected) {}

	void addEdge(int u, int v) {
		adjList[u].insert(v);
		if (!directed) {
			adjList[v].insert({ u });
		}
	}

	void bfs(int startingVertex) {
		queue<int> queue;
		unordered_set<int> visited;
		queue.push(startingVertex);
		visited.insert(startingVertex);

		int distance;
		while (!queue.empty()) {
			int levelSize = queue.size();
			cout << "At distance: " << distance << std::endl;
			for (int i = 0; i < levelSize; i++) {
				int currentElement = queue.front();
				queue.pop();
				cout << currentElement << " ";
				for (auto& neighbour : adjList[currentElement]) {
					if (!visited.count(neighbour)) {
						queue.push(neighbour);
						visited.insert(currentElement);
					}

				}
				distance++;
			}

		}
	}

	void dfs(int current, unordered_set<int>& visited){
		cout << current << " ";
		visited.insert(current);

		for (auto& neightbour : adjList[current]) {
			if (!visited.count(neightbour)) {
				dfs(current, visited);
			}
		}
	}

	void dfsIterative(int startingVertex) {
		unordered_set<int> visited;
		stack<int> stack;
		visited.insert(startingVertex);
		stack.push(startingVertex);

		while (!stack.empty()) {
			int current = stack.top();
			stack.pop();

			if (visited.count(current)) {
				continue;
			}

			visited.insert(current);
			for (auto& neighbour : adjList[current]) {
				if (!visited.count(neighbour)) {
					stack.push(neighbour);
				}
			}
		}
	}

	int countAreas() {
		unordered_set<int> visited;
		int count;

		for (const auto& kvp : adjList){
			if (!visited.count(kvp.first)){
				dfs(kvp.first, visited);
				count++;
			}
		}
		
	}

	vector<int> topologicalSort(){
		if (hasCycle()){
			cout << "Graph has a cycle! Topological sort not possible." << endl;
			return {};
		}

		unordered_set<int> visited;
		stack<int> stack;

		for (int i = 0; i < V; i++){
			if (!visited.count(i)){
				topologicalSortDfsUtil(i, visited, stack);
			}
		}

		vector<int> result;
		while (!stack.empty()){
			result.push_back(stack.top());
			stack.pop();
		}

		return result;
	}

	void topologicalSortDfsUtil(int current, unordered_set<int>& visited, stack<int>& stack){
		visited.insert(current);

		for (auto& neighbour : adjList[current]){
			if (!visited.count(neighbour)){
				topologicalSortDfsUtil(neighbour, visited, stack);
			}
		}

		stack.push(current);
	}

	bool hasCycle(){
		unordered_set<int> visited;
		unordered_set<int> recStack;

		for (int i = 0; i < V; i++){
			if (!visited.count(i)){
				if (hasCycleRecursive(i, visited, recStack)){
					return true;
				}
			}
		}

		return false;
	}

	bool hasCycleRecursive(int current, unordered_set<int>& visited, unordered_set<int>& recStack){
		visited.insert(current);
		recStack.insert(current);

		for (auto& neighbour : adjList[current]){
			if (!visited.count(neighbour)){
				if (hasCycleRecursive(neighbour, visited, recStack)){
					return true;
				}
			}
			else if (recStack.count(neighbour))
			{
				return true;
			}
		}

		recStack.erase(current);
		return false;
	}


	void printGraph() {
		cout << "\nGraph representation:" << endl;
		for (auto& [vertex, neighbors] : adjList) {
			cout << vertex << " -> ";
			for (auto& neighbor : neighbors) {
				cout << "(" << neighbor << ") ";
			}
			cout << endl;
		}
	}
};

int main() {
	return 0;
}