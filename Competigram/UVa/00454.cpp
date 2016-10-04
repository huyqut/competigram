#include <bits/stdc++.h>

using namespace std;

void normalize(string & sentence);

int main()
{
	ios::sync_with_stdio(false);

	size_t cases; cin >> cases; cin.ignore();
	string sentence;
	getline(cin, sentence);
	while (cases-- > 0)
	{
		unordered_map<string, vector<string>> ana_origins;
		while (getline(cin, sentence) && !sentence.empty())
		{
			string standard = sentence;
			normalize(standard);
			ana_origins[standard].push_back(sentence);
		}

		map<string, vector<string>> result;
		for (auto & ana_origin : ana_origins)
		{
			if (ana_origin.second.size() == 1)
			{
				continue;
			}
			sort(ana_origin.second.begin(), ana_origin.second.end());
			auto const & origins = ana_origin.second;
			for (int i = 0; i + 1 < ana_origin.second.size(); ++i)
			{
				for (int j = i + 1; j < ana_origin.second.size(); ++j)
				{
					result[origins[i]].push_back(origins[j]);
				}
			}
		}
		
		for (auto & origin_ana : result)
		{
			for (auto const & second : origin_ana.second)
			{
				cout << origin_ana.first << " = " << second << '\n';
			}
		}
		if (cases > 0)
		{
			cout << '\n';
		}
	}


	return 0;
}

void normalize(string & sentence)
{
	int i = 0, j = 0;
	while (j < sentence.length())
	{
		if (sentence[j] == ' ')
		{
			++j;
			continue;
		}
		sentence[i] = sentence[j];
		++i;
		++j;
	}
	sentence.resize(i);
	sort(sentence.begin(), sentence.end());
}