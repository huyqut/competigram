#include <bits/stdc++.h>

using namespace std;

int is_palindrome(string const & text);
int is_mirrored(string const & text);

int main()
{
	ios::sync_with_stdio(false);

	string text;
	while (cin >> text)
	{
		int palindrome = is_palindrome(text);
		int mirrored = is_mirrored(text);
		cout << text << " -- is ";
		switch (palindrome + mirrored)
		{
		case 0:
			cout << "not a palindrome.";
			break;
		case 1:
			cout << "a regular palindrome.";
			break;
		case 2:
			cout << "a mirrored string.";
			break;
		case 3:
			cout << "a mirrored palindrome.";
			break;
		}
		cout << "\n\n";
	}

	return 0;
}

int is_palindrome(string const & text)
{
	for (size_t i = 0; i < text.length() / 2; ++i)
	{
		if (text[i] != text[text.length() - i - 1])
		{
			return 0;
		}
	}
	return 1;
}

int is_mirrored(string const & text)
{
	static const unordered_map<char, char> mirror = {
		{'A', 'A'}, {'E', '3'}, {'H', 'H'}, {'I', 'I'}, {'J', 'L'}, {'L', 'J'},
		{'M', 'M'}, {'O', 'O'}, {'S', '2'}, {'T', 'T'}, {'U', 'U'}, {'V', 'V'},
		{'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, {'Z', '5'}, {'1', '1'}, {'2', 'S'},
		{'3', 'E'}, {'5', 'Z'}, {'8', '8'}
	};
	size_t limit = text.length() / 2 + text.length() % 2;
	for (size_t i = 0; i < limit; ++i)
	{
		if (mirror.find(text[i]) == mirror.end()
			|| mirror.at(text[i]) != text[text.length() - i - 1])
		{
			return 0;
		}
	}
	return 2;
}