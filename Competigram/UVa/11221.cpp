#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	size_t cases; cin >> cases; cin.ignore();
	for (size_t index = 1; index <= cases; ++index)
	{
		string line; getline(cin, line);
		int a = 0, b = 0;
		while (b < line.length())
		{
			if (line[b] == ' ' || line[b] == ',' || line[b] == '.' ||
				line[b] == '?' || line[b] == '!' || line[b] == '(' || line[b] == ')')
			{
				++b;
				continue;
			}
			line[a] = line[b];
			++a;
			++b;
		}
		line.resize(a);

		int k = sqrt(a);
		bool magic = true;
		if (k * k != line.length())
		{
			magic = false;
		}
		else
		{
			int quad[4];
			for (int i = 0; i < k / 2 && magic; ++i)
			{
				for (int j = i; j < k - i && magic; ++j)
				{
					quad[0] = i * k + j;
					quad[1] = j * k + i;
					quad[2] = line.length() - k * i - j - 1;
					quad[3] = line.length() - k * j - i - 1;
					for (int u = 1; u < 4 && magic; ++u)
					{
						if (line[quad[u]] != line[quad[u - 1]])
						{
							magic = false;
						}
					}
				}
			}
		}
		cout << "Case #" << index << ":\n";
		if (magic)
		{
			cout << k;
		}
		else
		{
			cout << "No magic :(";
		}
		cout << '\n';
	}

	return 0;
}