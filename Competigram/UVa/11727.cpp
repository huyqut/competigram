#include <bits/stdc++.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	
	int size;
	cin >> size;
	for (int i = 1; i <= size; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cout << "Case " << i << ": ";
		if (a > b)
		{
			cout << ((b > c) ? b : (a > c) ? c : a);
		}
		else
		{
			cout << ((a > c) ? a : (b > c) ? c : b);
		}
		cout << '\n';
	}

	return 0;
}