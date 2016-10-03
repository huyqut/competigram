#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	size_t cases; cin >> cases;
	while (cases-- > 0)
	{
		size_t player_size, snake_size, dice_size;
		cin >> player_size >> snake_size >> dice_size;
		unordered_map<unsigned, unsigned> snakes;
		while (snake_size-- > 0)
		{
			unsigned head, tail;
			cin >> head >> tail;
			snakes[head] = tail;
		}

		vector<unsigned> players(player_size + 1, 1);
		unsigned player = 1;
		bool stop = false;
		for (;dice_size-- > 0; player = player % player_size + 1)
		{
			unsigned dice_roll; cin >> dice_roll;
			if (stop)
			{
				continue;
			}
			unsigned new_position = players[player] + dice_roll;
			if (new_position > 100)
			{
				new_position = 100;
			}
			if (snakes.find(new_position) != snakes.end())
			{
				new_position = snakes[new_position];
			}
			players[player] = new_position;
			if (new_position == 100)
			{
				stop = true;
			}
		}
		
		for (unsigned i = 1; i <= player_size; ++i)
		{
			cout << "Position of player " << i << " is " << players[i] << ".\n";
		}
	}

	return 0;
}