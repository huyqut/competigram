#include <bits/stdc++.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	for (unsigned row, col; cin >> row >> col;)
	{
		if (row == 0 && col == 0)
		{
			break;
		}
		if (row == 1)
		{
			cout << col;
		}
		else if (col == 1)
		{
			cout << row;
		}
		else
		{
			unsigned area = row * col;
			if (area < 4)
			{
				cout << area;
			}
			else if (area < 9)
			{
				cout << 4;
			}
			else if (row == 2 || col == 2)
			{
				unsigned bonus = area % 8;
				if (bonus > 4)
				{
					bonus = 4;
				}
				cout << ((area / 8) * 4 + bonus);
			}
			else
			{
				cout << (area / 2 + area % 2);
			}
		}
		
		cout << " knights may be placed on a " 
			<< row << " row " << col << " column board.\n";
	}
	return 0;
}