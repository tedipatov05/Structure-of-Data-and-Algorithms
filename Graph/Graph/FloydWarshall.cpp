#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<vector<int>> floydWarshall(int nodes, vector<vector<int>>& graph) {
	vector<vector<int>> dist = graph;

	for (int k = 0; k < nodes; k++) {
		for (int i = 0; i < nodes; i++) {
			for (int j = 0; j < nodes; j++) {
				if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
					if (dist[i][j] > dist[i][k] + dist[k][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
	}

	return dist;
}

