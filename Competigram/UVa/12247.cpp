#include <bits/stdc++.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int princess[3], prince[2];
	while (cin >> princess[0] && princess[0] > 0)
	{
		unordered_set<int> cards;
		cin >> princess[1] >> princess[2] >> prince[0] >> prince[1];
		cards.insert(princess[0]); cards.insert(princess[1]); cards.insert(princess[2]);
		cards.insert(prince[0]); cards.insert(prince[1]);
		bool princess_card[3] = { false , false , false };
		for (size_t i = 0; i < 2; ++i)
		{
			for (size_t j = i + 1; j < 3; ++j)
			{
				if (princess[i] > princess[j])
				{
					swap(princess[i], princess[j]);
				}
			}
		}
		int win = 2;
		for (int i = 0; i < 2; ++i)
		{
			for (int s = 0; s < 3; ++s)
			{
				if (princess_card[s])
				{
					continue;
				}
				if (princess[s] > prince[i])
				{
					princess_card[s] = true;
					--win;
					++s;
					
					break;
				}
			}
		}
		switch (win)
		{
			case 0: cout << -1; break;
			case 1:
			{
				int i = 2;
				for (; i >= 0 && princess_card[i]; --i);
				int j = princess[i] + 1;
				for (; j <= 52 && cards.find(j) != cards.end(); ++j);
				if (j == 53)
				{
					cout << -1;
				}
				else
				{
					cout << j;
				}
				break;
			}
			case 2:
			{
				int j = 1;
				for (; j <= 52 && cards.find(j) != cards.end(); ++j);
				cout << j;
			}
		}
		cout << '\n';
	}

	return 0;
}