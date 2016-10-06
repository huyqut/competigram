#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	size_t cases; cin >> cases;
	while (cases-- > 0)
	{
		string left, right, balance;
		unordered_set<char> true_silvers;
		unordered_map<char, int> heavy, light;
		int unbalance = 0;
		for (int i = 0; i < 3; ++i)
		{
			cin >> left >> right >> balance;
			switch (balance[0])
			{
			case 'e':
				for (char coin : left)
				{
					true_silvers.insert(coin);
				}
				for (char coin : right)
				{
					true_silvers.insert(coin);
				}
				break;
			case 'u':
				++unbalance;
				for (char coin : left)
				{
					++heavy[coin];
				}
				for (char coin : right)
				{
					++light[coin];
				}
				break;
			case 'd':
				++unbalance;
				for (char coin : left)
				{
					++light[coin];
				}
				for (char coin : right)
				{
					++heavy[coin];
				}
				break;
			}
		}
		char counterfeit = ' ';
		bool is_heavy = false;
		for (auto const & coin_freq : heavy)
		{
			if (true_silvers.find(coin_freq.first) != true_silvers.end())
			{
				continue;
			}
			if (coin_freq.second == unbalance)
			{
				counterfeit = coin_freq.first;
				is_heavy = true;
				break;
			}
		}
		if (is_heavy)
		{
			cout << counterfeit << " is the counterfeit coin and it is heavy.";
		}
		else
		{
			for (auto const & coin_freq : light)
			{
				if (true_silvers.find(coin_freq.first) != true_silvers.end())
				{
					continue;
				}
				if (coin_freq.second == unbalance)
				{
					counterfeit = coin_freq.first;
					break;
				}
			}
			cout << counterfeit << " is the counterfeit coin and it is light.";
		}
		cout << '\n';
	}

	return 0;
}