#include <bits/stdc++.h>

using namespace std;

void lower_case(string & word);

int main()
{
	ios::sync_with_stdio(false);

	unordered_map<string, unordered_multiset<string>> ana_freq;
	string word;
	while (cin >> word && word != "#")
	{
		string lowered = word;
		lower_case(lowered);
		sort(lowered.begin(), lowered.end());
		ana_freq[lowered].insert(word);
	}

	vector<string> ananagrams;
	for (auto const & ana_freq_pair : ana_freq)
	{
		if (ana_freq_pair.second.size() == 1)
		{
			ananagrams.push_back(*ana_freq_pair.second.begin());
		}
	}
	sort(ananagrams.begin(), ananagrams.end());
	
	for (auto const & ananagram : ananagrams)
	{
		cout << ananagram << '\n';
	}

	return 0;
}

void lower_case(string & word)
{
	for (char & c : word)
	{
		c = tolower(c);
	}
}