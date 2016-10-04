#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	for (int pages; cin >> pages && pages > 0;)
	{
		cout << "Printing order for " << pages << " pages:\n";
		int total = pages / 4;
		if (pages % 4 > 0)
		{
			++total;
		}
		int begin = 1, end = 4 * total;
		bool front = true;
		int sheet = 1;
		for (; begin < end && begin <= pages; ++begin, --end)
		{
			cout << "Sheet " << sheet << ", ";
			if (front)
			{
				cout << "front: ";
				if (end > pages)
				{
					cout << "Blank";
				}
				else
				{
					cout << end;
				}
				cout << ", " << begin << '\n';
			}
			else
			{
				cout << "back : ";
				cout << begin << ", ";
				if (end > pages)
				{
					cout << "Blank";
				}
				else
				{
					cout << end;
				}
				cout << '\n';
				++sheet;
			}
			front = !front;
		}
	}

	return 0;
}