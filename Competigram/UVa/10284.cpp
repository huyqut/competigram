#include <bits/stdc++.h>

using namespace std;

void occupy(int row, int col, unsigned & counter, vector<vector<char>> & board);

int main()
{
	std::ios::sync_with_stdio(false);

	string line;
	while (getline(cin, line))
	{
		vector<vector<char>> occupied(8, vector<char>(8, ' '));
		int row = 0, col = 0;
		for (char piece : line)
		{
			if (piece == '/')
			{
				++row; col = 0;
			}
			else if ('1' <= piece && piece <= '8')
			{
				col += piece - '0';
			}
			else
			{
				occupied[row][col] = piece;
				++col;
			}
		}
		unsigned unoccupied = 64;
		for (int row = 0; row < 8; ++row)
		{
			for (int col = 0; col < 8; ++col)
			{
				char piece = occupied[row][col];
				if (piece == ' ' || piece == 'x') {
					continue;
				}
				--unoccupied;
				switch (piece)
				{
				case 'p':
					occupy(row + 1, col - 1, unoccupied, occupied);
					occupy(row + 1, col + 1, unoccupied, occupied);
					break;
				case 'P':
					occupy(row - 1, col - 1, unoccupied, occupied);
					occupy(row - 1, col + 1, unoccupied, occupied);
					break;
				case 'n': case 'N':
				{
					static const int dr[] = {
						-2, -2, -1, -1, 1, 1, 2, 2
					};
					static const int dc[] = {
						-1, 1, -2, 2, -2, 2, -1, 1
					};
					for (int i = 0; i < 8; ++i)
					{
						occupy(row + dr[i], col + dc[i], unoccupied, occupied);
					}
					break;
				}
				case 'q': case 'Q':
				case 'b': case 'B':
				{
					for (int dr = -1; dr <= 2; dr += 2)
					{
						for (int dc = -1; dc <= 2; dc += 2)
						{
							int r = row, c = col;
							for (int i = 0; i < 8; ++i)
							{
								r += dr;
								c += dc;
								if (r < 0 || r >= 8 || c < 0 || c >= 8
									|| occupied[r][c] != ' ' && occupied[r][c] != 'x')
								{
									break;
								}
								occupy(r, c, unoccupied, occupied);
							}
						}
					}
					if (piece == 'b' || piece == 'B')
					{
						break;
					}
				}
				case 'r': case 'R':
				{
					static const int dr[] = {
						-1, 0, 1, 0
					};
					static const int dc[] = {
						0, -1, 0, 1
					};
					for (int i = 0; i < 4; ++i)
					{
						int r = row, c = col;
						for (int j = 0; j < 8; ++j)
						{
							r += dr[i];
							c += dc[i];
							if (r < 0 || r >= 8 || c < 0 || c >= 8
								|| occupied[r][c] != ' ' && occupied[r][c] != 'x')
							{
								break;
							}
							occupy(r, c, unoccupied, occupied);
						}
					}
					break;
				}
				case 'k': case 'K':
				{
					static const int dr[] = {
						-1, -1, -1, 0, 1, 1, 1, 0
					};
					static const int dc[] = {
						-1, 0, 1, 1, 1, 0, -1, -1
					};
					for (int i = 0; i < 8; ++i)
					{
						occupy(row + dr[i], col + dc[i], unoccupied, occupied);
					}
					break;
				}
				}
			}
		}
		cout << unoccupied << '\n';
	}

	return 0;
}

void occupy(int row, int col, unsigned & counter, vector<vector<char>>& occupied)
{
	if (row < 0 || row >= 8 || col < 0 || col >= 8 || occupied[row][col] != ' ')
	{
		return;
	}
	--counter;
	occupied[row][col] = 'x';
}