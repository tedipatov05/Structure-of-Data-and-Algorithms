#include <queue>
#include <vector>
using namespace std;

class RottinOranges
{
public:

	int orangesRotting(std::vector<vector<int>>& grid)
	{
		size_t m = grid.size();
		size_t n = grid[0].size();
		vector<vector<int>> visited = grid;

		int countFreshOranges = 0;
		queue<pair<int, int>> queue;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visited[i][j] == 2)
				{
					queue.push({ i, j });
				}

				if (visited[i][j] == 1)
				{
					countFreshOranges++;
				}
			}
		}

		if (countFreshOranges == 0)
		{
			return 0;
		}

		if (queue.empty())
		{
			return -1;
		}

		int minutes = -1;
		vector<pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };

		while (!queue.empty())
		{
			int size = queue.size();
			while (size--)
			{
				auto [x, y] = queue.front();
				queue.pop();
				for (auto [dx, dy] : directions)
				{
					int i = x + dx;
					int j = y + dy;

					if (i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1)
					{
						visited[i][j] = 2;
						countFreshOranges--;
						queue.push({ i, j });
					}
				}
			}
			minutes++;
		}

		if (countFreshOranges == 0)
		{
			return minutes;
		}

		return -1;

	}
};
