#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	for (int round; cin >> round && round > 0;)
	{
		cout << "Round " << round << '\n';
		string puzzle; cin >> puzzle;
		string answer; cin >> answer;
		unordered_set<char> char_set;
		for (char c : puzzle)
		{
			char_set.insert(c);
		}
		unsigned counter = 0;
		unordered_set<char> new_set;
		unordered_set<char> hang_set;
		for (char c : answer)
		{
			if (char_set.find(c) != char_set.end())
			{
				new_set.insert(c);
			}
			else {
				hang_set.insert(c);
			}
			if (new_set.size() == char_set.size() || hang_set.size() == 7)
			{
				break;
			}
		}
		if (hang_set.size() == 7)
		{
			cout << "You lose.";
		}
		else if (new_set.size() == char_set.size())
		{
			cout << "You win.";
		}
		else
		{
			cout << "You chickened out.";
		}
		cout << '\n';
	}

	return 0;
}