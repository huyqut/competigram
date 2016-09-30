#include <bits/stdc++.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	string cards[52];
	size_t cases; cin >> cases;
	for (size_t i = 1; i <= cases; ++i)
	{
		for (size_t j = 0; j < 52; ++j)
		{
			cin >> cards[j];
		}
		
		int top = 26;
		int value = 0;
		for (size_t j = 0; j < 3; ++j)
		{
			int card_value = 10;
			if ('2' <= cards[top][0] && cards[top][0] <= '9')
			{
				card_value = cards[top][0] - '0';
			}
			value += card_value;
			top -= 11 - card_value;
		}
		
		cout << "Case " << i << ": ";
		if (value > top)
		{
			cout << cards[25 + value - top];
		}
		else
		{
			cout << cards[value];
		}
		cout << '\n';
	}

	return 0;
}