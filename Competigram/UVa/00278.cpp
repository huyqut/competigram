#include <bits/stdc++.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	size_t cases; cin >> cases;
	while (cases-- > 0)
	{
		char piece; cin >> piece;
		unsigned row, col; cin >> row >> col;
		switch (piece)
		{
			case 'r':
				cout << ((row < col) ? row : col);
				break;
			case 'k':
				cout << (row * col / 2 + row * col % 2);
				break;
			case 'Q':
			{
				unsigned min = (row < col) ? row : col;
				if (min == 1 || min >= 4)
				{
					cout << min;
				}
				else
				{
					cout << 0;
				}
			}
				break;
			case 'K':
				cout << (((row + 1) / 2) * ((col + 1) / 2));
				break;
		}
		cout << '\n';
	}

	return 0;
}