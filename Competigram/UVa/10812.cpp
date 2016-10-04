#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	size_t cases; cin >> cases;
	while (cases-- > 0)
	{
		int sum, diff;
		cin >> sum >> diff;
		if (sum < diff || (sum - diff) % 2 == 1)
		{
			cout << "impossible";
		}
		else
		{
			int small = (sum - diff) / 2;
			int big = small + diff;
			cout << big << ' ' << small;
		}
		cout << '\n';
	}

	return 0;
}