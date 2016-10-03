#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	static const int dx[] = {
		-1, -1, -1, 0, 1, 1, 1, 0
	};
	static const int dy[] = {
		-1, 0, 1, 1, 1, 0, -1, -1
	};
	int index = 1;
	for (int row, col; cin >> row >> col && row > 0 && col > 0; ++index)
	{
		if (index > 1)
		{
			cout << '\n';
		}
		vector<string> mine_field;
		mine_field.reserve(row);
		for (int i = 0; i < row; ++i)
		{
			string row_field; cin >> row_field;
			for (char & c : row_field)
			{
				if (c == '.')
				{
					c = '0';
				}
			}
			mine_field.push_back(row_field);
		}
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (mine_field[i][j] != '*')
				{
					continue;
				}
				for (int k = 0; k < 8; ++k)
				{
					int x = i + dx[k];
					int y = j + dy[k];
					if (x < 0 || x >= row || y < 0 || y >= col || mine_field[x][y] == '*')
					{
						continue;
					}
					++mine_field[x][y];
				}
			}
		}
		cout << "Field #" << index << ":\n";
		for (auto const & row_field : mine_field)
		{
			cout << row_field << '\n';
		}
	}

	return 0;
}