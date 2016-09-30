#include <bits/stdc++.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	size_t cases; cin >> cases;
	for (size_t i = 1; i <= cases; ++i)
	{
		size_t creature_size; cin >> creature_size;
		unsigned max_speed = 0;
		while (creature_size-- > 0)
		{
			unsigned speed; cin >> speed;
			if (speed > max_speed)
			{
				max_speed = speed;
			}
		}
		cout << "Case " << i << ": " << max_speed << '\n';
	}

	return 0;
}