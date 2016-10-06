#include <bits/stdc++.h>

using namespace std;

const vector<vector<string>> children = {
	{"O"},
	{"O", "A"},
	{"O", "B"},
	{"B", "A"},
	{"AB", "B", "A" },
	{"O", "AB", "B", "A" },
};

vector<string> blood_types = {
	"A", "AB", "B", "O"
};

vector<vector<int>> map_children = {
	{1, 4, 5, 1},
	{4, 4, 3},
	{2, 2},
	{0}
};

unordered_map<string, unordered_map<string, vector<string>>> parent_parent;
unordered_map<string, unordered_map<string, unordered_set<string>>> parent_child;

void init_parent_child();
void print_possible(unordered_set<string> & input, string const & rh);

int main()
{
	ios::sync_with_stdio(false);

	init_parent_child();
	
	unsigned cases = 1;
	string parents[2], child;
	while (cin >> parents[0] >> parents[1] >> child && parents[0][0] != 'E')
	{
		cout << "Case " << cases << ": ";
		if (child[0] == '?')
		{
			cout << parents[0] << ' ' << parents[1];
			string rh = (parents[0].back() == '+' || parents[1].back() == '+') ? "-+" : "-";
			parents[0].pop_back();
			parents[1].pop_back();
			auto const & result = parent_parent[parents[0]][parents[1]];
			int counter = rh.size() * result.size();
			if (counter == 1)
			{
				cout << ' ' << result[0] << rh[0] << '\n';
			}
			else
			{
				cout << " {";
				for (int i = 0; i < result.size(); ++i)
				{
					for (int j = 0; j < rh.size(); ++j)
					{
						cout << result[i] << rh[j];
						if (counter == 1)
						{
							break;
						}
						--counter;
						cout << ", ";
					}
				}
				cout << "}\n";
			}
		}
		else
		{
			bool miss_first = (parents[0][0] == '?');
			string parent = (miss_first) ? parents[1] : parents[0];
			char p = parent.back();
			char c = child.back();
			parent.pop_back();
			child.pop_back();
			bool possible = true;
			auto & possible_parents = parent_child[parent][child];
			if (possible_parents.empty())
			{
				possible = false;
			}
			string rh = (p == '-' && c == '+') ? "+" : "-+";
			if (miss_first)
			{
				if (!possible)
				{
					cout << "IMPOSSIBLE";
				}
				else
				{
					print_possible(possible_parents , rh);
				}
				cout << ' ' << parents[1];
			}
			else
			{
				cout << parents[0] << ' ';
				if (!possible)
				{
					cout << "IMPOSSIBLE";
				}
				else
				{
					print_possible(possible_parents, rh);
				}
			}
			cout << ' ' << child << c << '\n';
		}
		++cases;
	}
	return 0;
}

void init_parent_child()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = i; j < 4; ++j)
		{
			auto & t = children[map_children[i][j - i]];
			parent_parent[blood_types[i]][blood_types[j]] = children[map_children[i][j - i]];
			parent_parent[blood_types[j]][blood_types[i]] = children[map_children[i][j - i]];
			for (auto const & child : t)
			{
				parent_child[blood_types[i]][child].insert(blood_types[j]);
				parent_child[blood_types[j]][child].insert(blood_types[i]);
			}
		}
	}
}

void print_possible(unordered_set<string>& input, string const & rh)
{
	int counter = rh.size() * input.size();
	if (counter == 1)
	{
		cout << *input.begin() << rh[0];
	}
	else
	{
		cout << "{";
		for (auto const & element : input)
		{
			for (int i = 0; i < rh.size(); ++i)
			{
				cout << element << rh[i];
				if (counter == 1)
				{
					break;
				}
				--counter;
				cout << ", ";
			}
		}
		cout << "}";
	}
}