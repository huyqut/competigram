#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	static const int dx[] = {
		-1, 0, 1, 0
	};
	static const int dy[] = {
		0, -1, 0, 1
	};

	size_t cases; cin >> cases;
	while (cases-- > 0)
	{
		int row, col, day;
		cin >> row >> col >> day;
		vector<string> grid[2];
		grid[0].reserve(row);
		grid[1] = vector<string>(row, string(col, ' '));
		for (int i = 0; i < row; ++i)
		{
			string row_grid; cin >> row_grid;
			grid[0].push_back(row_grid);
		}
		
		unsigned from = 0;
		while (day-- > 0)
		{
			unsigned to = (from == 0) ? 1 : 0;
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					char self = grid[from][i][j];
					for (int k = 0; k < 4; ++k)
					{
						int x = i + dx[k];
						int y = j + dy[k];
						if (x < 0 || x >= row || y < 0 || y >= col)
						{
							continue;
						}
						char other = grid[from][x][y];
						if (self == 'R' && other == 'P' ||
							self == 'S' && other == 'R' ||
							self == 'P' && other == 'S')
						{
							self = other;
							break;
						}
					}
					grid[to][i][j] = self;
				}
			}
			from = to;
		}
		for (int i = 0; i < row; ++i)
		{
			cout << grid[from][i] << '\n';
		}
		if (cases > 0)
		{
			cout << '\n';
		}
	}

	return 0;
}