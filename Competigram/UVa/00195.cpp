#include <bits/stdc++.h>

using namespace std;

bool strict_compare(char const & a, char const & b)
{
	if ('A' <= a && a <= 'Z' && 'a' <= b && b <= 'z')
	{
		if (tolower(a) == b)
		{
			return true;
		}
		else
		{
			return tolower(a) < b;
		}
	}
	if ('a' <= a && a <= 'z' && 'A' <= b && b <= 'Z')
	{
		if (tolower(b) == a)
		{
			return false;
		}
		else
		{
			return a < tolower(b);
		}
	}
	return a < b;
}

bool weak_compare(char const & a, char const & b)
{
	if ('A' <= a && a <= 'Z' && 'a' <= b && b <= 'z')
	{
		if (tolower(a) == b)
		{
			return true;
		}
		else
		{
			return tolower(a) <= b;
		}
	}
	if ('a' <= a && a <= 'z' && 'A' <= b && b <= 'Z')
	{
		if (tolower(b) == a)
		{
			return false;
		}
		else
		{
			return a <= tolower(b);
		}
	}
	return a <= b;
}

int main()
{
	ios::sync_with_stdio(false);

	size_t cases; cin >> cases; cin.ignore();
	while (cases-- > 0)
	{
		string word; cin >> word;
		sort(word.begin(), word.end(), strict_compare);
		while (true)
		{
			cout << word << '\n';
			int i = word.length() - 1;
			for (; i > 0 && weak_compare(word[i], word[i - 1]); --i);
			if (i == 0)
			{
				break;
			}
			int j = word.length() - 1;
			for (; j >= i && weak_compare(word[j], word[i - 1]); --j);
			swap(word[i - 1], word[j]);
			int length = word.length() - i;
			for (int k = 0; k < length / 2; ++k)
			{
				swap(word[i + k], word[word.length() - k - 1]);
			}
		}
	}

	return 0;
}