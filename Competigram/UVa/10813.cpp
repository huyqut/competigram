#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	size_t cases; cin >> cases;
	while (cases-- > 0)
	{
		unordered_set<int> rows[5];
		unordered_set<int> cols[5];
		unordered_set<int> diag[2];
		unordered_map<int, int> number_row;
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (i == 2 && j == 2)
				{
					++j;
				}
				int number; cin >> number;
				number_row[number] = i;
				rows[i].insert(number);
				cols[j].insert(number);
				if (i == j)
				{
					diag[0].insert(number);
				}
				else if (i == 4 - j) 
				{
					diag[1].insert(number);
				}
			}
		}
		bool free_space = true;
		int bingo = -1;
		for (int i = 1; i <= 75; ++i)
		{
			int number; cin >> number;
			if (bingo > 0)
			{
				continue;
			}
			int col = (number - 1) / 15;
			if (number_row.find(number) == number_row.end())
			{
				if (col == 2) {
					if (free_space)
					{
						if (cols[2].empty() || rows[2].empty()
							|| diag[0].empty() || diag[1].empty())
						{
							bingo = i;
						}
						else
						{
							free_space = false;
						}
					}
				}
			}
			else
			{
				cols[col].erase(number);
				if (cols[col].empty())
				{
					bingo = i;
				}
				else
				{
					int row = number_row[number];
					rows[row].erase(number);
					if (rows[row].empty())
					{
						bingo = i;
					}
					else if (row == col)
					{
						diag[0].erase(number);
						if (diag[0].empty())
						{
							bingo = i;
						}
					}
					else if (row == 4 - col)
					{
						diag[1].erase(number);
						if (diag[1].empty())
						{
							bingo = i;
						}
					}
				}
			}
		}
		cout << "BINGO after " << bingo << " numbers announced\n";
	}

	return 0;
}