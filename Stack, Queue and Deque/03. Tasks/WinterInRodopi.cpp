
#include <iostream>
#include <queue>
using namespace std;

struct Cell
{
	int row, col, day;
};

class ApplesRotting
{

public:

	int applesRotting()
	{
		int m, n, t;
		cin >> m >> n >> t;

		vector<pair<int, int>> rottenApples;

		int r1, c1;
		cin >> r1 >> c1;
		rottenApples.push_back({ c1, r1 });

		int r2, c2;
		if (cin >> r2 >> c2)
		{
			rottenApples.push_back({ r2, c2 });
		}

		vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
		queue<Cell> queue;

		for (auto& apple : rottenApples)
		{
			grid[apple.first][apple.second] = -1;
			queue.push({ apple.first, apple.second, 0 });
		}

		vector<pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

		while (!queue.empty())
		{
			Cell current = queue.front();
			queue.pop();

			if (current.day >= t)
			{
				continue;
			}

			for (auto [dx, dy] : directions)
			{
				int newRow = current.row + dx;
				int newCol = current.col + dy;

				if (newRow >= 1 && newRow <= n &&
					newCol >= 1 && newCol <= m &&
					grid[newRow][newCol] == 0) {

					grid[newRow][newCol] = current.day + 1;
					queue.push({ newRow, newCol, current.day + 1 });
				}
			}
		}

		int healthyCount = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (grid[i][j] == 0 || grid[i][j] > t) {
					healthyCount++;
				}
			}
		}

		return healthyCount;
	}
};