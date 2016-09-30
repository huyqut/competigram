#include <bits/stdc++.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	unsigned well_height, climb_distance, slide_distance, fatigue;
	while (cin >> well_height && well_height > 0)
	{
		cin >> climb_distance >> slide_distance >> fatigue;
		double down_climb = (double) climb_distance * (double) fatigue / 100;
		double height = 0;
		unsigned factor = 0;
		while (true)
		{
			if (climb_distance > factor * down_climb)
			{
				height += climb_distance - factor * down_climb;
			}
			if (height > well_height)
			{
				cout << "success on day " << (factor + 1);
				break;
			}
			height -= slide_distance;
			if (height < 0)
			{
				cout << "failure on day " << (factor + 1);
				break;
			}
			++factor;
		}
		cout << '\n';
	}

	return 0;
}