#include <bits/stdc++.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	for (size_t length; cin >> length && length > 0;)
	{
		string direction = "+x";
		while (length-- > 1)
		{
			string bend; cin >> bend;
			if (bend == "No")
			{
				continue;
			}
			if (direction == "+x")
			{
				direction = bend;
			}
			else if (direction == "-x")
			{
				direction[0] = (bend[0] == '-') ? '+' : '-';
				direction[1] = bend[1];
			}
			else if (direction[1] == bend[1])
			{
				direction[1] = 'x';
				direction[0] = (direction[0] != bend[0]) ? '+' : '-';
			}
		}
		cout << direction << '\n';
	}
	
	return 0;
}