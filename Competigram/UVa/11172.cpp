#include <bits/stdc++.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int cases;
	cin >> cases;
	for (; cases > 0; --cases)
	{
		int a, b;
		cin >> a >> b;
		if (a < b)
		{
			cout << '<';
		}
		else if (a == b)
		{
			cout << '=';
		}
		else
		{
			cout << '>';
		}
		cout << '\n';
	}
	return 0;
}