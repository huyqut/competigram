#include <bits/stdc++.h>

using namespace std;

const unordered_map<char, vector<string>> alphabet = {
	{ 'A' ,{ ".***..","*...*.","*****.","*...*.","*...*.", } },
	{ 'B' ,{ "****..","*...*.","****..","*...*.","****..", } },
	{ 'C' ,{ ".****.","*...*.","*.....","*.....",".****.", } },
	{ 'D' ,{ "****..","*...*.","*...*.","*...*.","****..", } },
	{ 'E' ,{ "*****.","*.....","***...","*.....","*****.", } },
	{ 'F' ,{ "*****.","*.....","***...","*.....","*.....", } },
	{ 'G' ,{ ".****.","*.....","*..**.","*...*.",".***..", } },
	{ 'H' ,{ "*...*.","*...*.","*****.","*...*.","*...*.", } },
	{ 'I' ,{ "*****.","..*...","..*...","..*...","*****.", } },
	{ 'J' ,{ "..***.","...*..","...*..","*..*..",".**...", } },
	{ 'K' ,{ "*...*.","*..*..","***...","*..*..","*...*.", } },
	{ 'L' ,{ "*.....","*.....","*.....","*.....","*****.", } },
	{ 'M' ,{ "*...*.","**.**.","*.*.*.","*...*.","*...*.", } },
	{ 'N' ,{ "*...*.","**..*.","*.*.*.","*..**.","*...*.", } },
	{ 'O' ,{ ".***..","*...*.","*...*.","*...*.",".***..", } },
	{ 'P' ,{ "****..","*...*.","****..","*.....","*.....", } },
	{ 'Q' ,{ ".***..","*...*.","*...*.","*..**.",".****.", } },
	{ 'R' ,{ "****..","*...*.","****..","*..*..","*...*.", } },
	{ 'S' ,{ ".****.","*.....",".***..","....*.","****..", } },
	{ 'T' ,{ "*****.","*.*.*.","..*...","..*...",".***..", } },
	{ 'U' ,{ "*...*.","*...*.","*...*.","*...*.",".***..", } },
	{ 'V' ,{ "*...*.","*...*.",".*.*..",".*.*..","..*...", } },
	{ 'W' ,{ "*...*.","*...*.","*.*.*.","**.**.","*...*.", } },
	{ 'X' ,{ "*...*.",".*.*..","..*...",".*.*..","*...*.", } },
	{ 'Y' ,{ "*...*.",".*.*..","..*...","..*...","..*...", } },
	{ 'Z' ,{ "*****.","...*..","..*...",".*....","*****.", } },
	{ ' ' ,{ "......","......","......","......","......", } }
};

void write(
	vector<string> & page, char font, char align, 
	int row, int col, string const & message);
bool write_c1(vector<string> & page, char c, int row, int col);
bool write_c5(vector<string> & page, char c, int row, int col);

int main()
{
	ios::sync_with_stdio(false);

	string const separator(60, '-');
	string info;
	while (cin >> info && !info.empty())
	{
		vector<string> lines(60, string(60, '.'));
		if (info[1] != 'E')
		{
			do
			{
				char align = info[1];
				cin >> info;
				char font = info[1];
				int row; cin >> row;
				int col = 0;
				if (align == 'P')
				{
					cin >> col;
				}
				cin.ignore();
				getline(cin, info);
				write(lines, font, align, row - 1, col - 1, info.substr(1, info.length() - 2));
			} while (cin >> info && info[1] != 'E');
		}
		if (info[1] == 'E')
		{
			for (auto const & line : lines)
			{
				cout << line << '\n';
			}
			cout << '\n' << separator << "\n\n";
		}
	}

	return 0;
}

void write(vector<string> & page, char font, char align, 
	int row, int col, string const & message)
{
	function<bool(vector<string> &, char, int, int)> write_char
		= (font == '1') ? write_c1 : write_c5;
	int incol = (font == '1') ? 1 : 6;
	switch (align)
	{
	case 'L':
		col = 0;
	case 'P':
		for (int i = 0; i < message.length(); ++i)
		{
			if (!write_char(page, message[i], row, col))
			{
				break;
			}
			col += incol;
		}
		break;
	case 'R':
		col = 60 - incol;
		for (int i = message.length() - 1; i >= 0; --i)
		{
			if (!write_char(page, message[i], row, col))
			{
				break;
			}
			col -= incol;
		}
		break;
	case 'C':
		int half = message.length() / 2;
		int offset = (incol == 1) ? 30 : 5;
		int begin_char = half - offset, end_char = half + offset;
		if (begin_char < 0)
		{
			begin_char = 0;
		}
		int col = 30 - (half - begin_char) * incol;
		if (message.length() % 2 == 1 && incol == 6)
		{
			col -= 3;
			++end_char;
		}
		if (end_char > message.length())
		{
			end_char = message.length();
		}
		for (int i = begin_char; i < end_char; ++i)
		{
			if (!write_char(page, message[i], row, col))
			{
				break;
			}
			col += incol;
		}
		break;
	}
}

bool write_c1(vector<string> & page, char c, int row, int col)
{
	if (row < 0 || col < 0 || row >= 60 || col >= 60)
	{
		return false;
	}
	if (c != ' ')
	{
		page[row][col] = c;
	}
	return true;
}

bool write_c5(vector<string> & page, char c, int row, int col)
{
	if (row < 0 || row >= 60 || col + 6 <= 0 || col >= 60)
	{
		return false;
	}
	auto const & table = alphabet.at(c);
	for (int i = 0; i < 5 && row + i < 60; ++i)
	{
		for (int j = 0; j < 6 && col + j < 60; ++j)
		{
			if (col + j < 0 || table[i][j] == '.')
			{
				continue;
			}
			page[row + i][col + j] = table[i][j];
		}
	}
	return true;
}