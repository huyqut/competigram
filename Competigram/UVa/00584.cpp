#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	while (true)
	{
		string game;
		getline(cin, game);
		if (game[0] == 'G')
		{
			break;
		}

		vector<pair<int, int>> frame_score;
		unsigned counter = 0;
		for (size_t i = 0; i < game.length(); ++i)
		{
			if (game[i] == ' ')
			{
				continue;
			}
			if (game[i] == 'X')
			{
				frame_score.push_back(pair<int, int>(10, 0));
				counter = 0;
			}
			else if (game[i] == '/')
			{
				frame_score.back().second = 10 - frame_score.back().first;
				counter = 0;
			}
			else {
				++counter;
				int score = game[i] - '0';
				if (counter == 2)
				{
					frame_score.back().second = score;
					counter = 0;
				}
				else {
					frame_score.push_back(pair<int, int>(score, 0));
				}
			}
		}
		unsigned game_score = 0;
		for (size_t i = 0; i < 10; ++i)
		{
			unsigned score = frame_score[i].first + frame_score[i].second;
			game_score += score;
			if (frame_score[i].first == 10)
			{
				game_score += frame_score[i + 1].first;
				if (frame_score[i + 1].first == 10)
				{
					game_score += frame_score[i + 2].first;
				}
				else {
					game_score += frame_score[i + 1].second;
				}
			}
			else if (score == 10)
			{
				game_score += frame_score[i + 1].first;
			}
		}
		cout << game_score << '\n';
	}

	return 0;
}