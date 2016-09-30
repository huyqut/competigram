#include <bits/stdc++.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	string cards[13];
	while (cin >> cards[0])
	{
		for (size_t i = 1; i < 13; ++i)
		{
			cin >> cards[i];
		}
		unsigned point = 0;
		unordered_map<char, unordered_set<char>> suits;
		for (auto const & card : cards)
		{
			switch (card[0])
			{
				case 'A': point += 4; break;
				case 'K': point += 3; break;
				case 'Q': point += 2; break;
				case 'J': point += 1; break;
			}
			suits[card[1]].insert(card[0]);
		}

		unsigned no_trump_point = point;
		unsigned stopped_suits = 0;
		for (char suit_key : {'S', 'H', 'D', 'C'})
		{
			auto & suit = suits[suit_key];
			if (suit.size() <= 1)
			{	//	Rule 6+7
				point += 2;
			}
			else if (suit.size() == 2)
			{	//	Rule 5
				++point;
			}
			if (suit.find('K') != suit.end() && suit.size() == 1)
			{	//	Rule 2
				--point; --no_trump_point;
			}
			if (suit.find('Q') != suit.end() && suit.size() <= 2)
			{	//	Rule 3
				--point; --no_trump_point;
			}
			if (suit.find('J') != suit.end() && suit.size() <= 3)
			{	//	Rule 4
				--point; --no_trump_point;
			}
			if (suit.find('A') != suit.end() ||
				suit.find('K') != suit.end() && suit.size() >= 2 ||
				suit.find('Q') != suit.end() && suit.size() >= 3)
			{
				++stopped_suits;
			}
		}
		if (no_trump_point >= 16 && stopped_suits == 4)
		{
			cout << "BID NO-TRUMP";
		}
		else
			if (point >= 14)
		{
			char suit;
			size_t suit_size = 0;
			for (char suit_key : {'S', 'H', 'D', 'C'})
			{
				if (suits[suit_key].size() > suit_size)
				{
					suit_size = suits[suit_key].size();
					suit = suit_key;
				}
			}
			cout << "BID " << suit;
		}
		else
		{
			cout << "PASS";
		}
		cout << '\n';
	}

	return 0;
}