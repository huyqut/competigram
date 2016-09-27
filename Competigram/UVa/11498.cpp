#include <bits/stdc++.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	static string const division[2][2] = {
		{ "NO", "NE" },
		{ "SO", "SE" }
	};

	int size;
	for (cin >> size; size > 0; cin >> size)
	{
		int origin[2];
		cin >> origin[0] >> origin[1];
		for (; size > 0; --size)
		{
			int x, y;
			cin >> x >> y;
			if (x == origin[0] || y == origin[1])
			{
				cout << "divisa";
			}
			else
			{
				int vertical = (y > origin[1]) ? 0 : 1;
				int horizontal = (x > origin[0]) ? 1 : 0;
				cout << division[vertical][horizontal];
			}
			cout << '\n';
		}
	}

	return 0;
}