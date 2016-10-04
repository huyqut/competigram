#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	string message;
	while (getline(cin, message) && message != "DONE")
	{
		int i = 0, j = message.length() - 1;
		bool bearable = true;
		while (i < j)
		{
			for (; i < j && 
				(message[i] == '.' || message[i] == ',' || message[i] == ' '
					|| message[i] == '!' || message[i] == '?'); ++i);
			for (; i < j &&
				(message[j] == '.' || message[j] == ',' || message[j] == ' '
					|| message[j] == '!' || message[j] == '?'); --j);
			if (i >= j)
			{
				break;
			}
			char left = tolower(message[i]);
			char right = tolower(message[j]);
			if (left != right)
			{
				bearable = false;
				break;
			}
			++i;
			--j;
		}
		if (bearable)
		{
			cout << "You won't be eaten!";
		}
		else
		{
			cout << "Uh oh..";
		}
		cout << '\n';
	}

	return 0;
}