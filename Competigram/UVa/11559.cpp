#include <bits/stdc++.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	size_t participant_size, budget, hotel_size, week_size;
	while (cin >> participant_size)
	{
		cin >> budget >> hotel_size >> week_size;

		unsigned payment = budget + 1;
		bool stay = true;
		for (size_t hotel = 0; hotel < hotel_size; ++hotel)
		{
			unsigned cost; cin >> cost;
			unsigned max_space = 0;
			for (size_t i = 0; i < week_size; ++i)
			{
				unsigned space; cin >> space;
				if (space > max_space)
				{
					max_space = space;
				}
			}
			if (max_space >= participant_size)
			{
				unsigned new_payment = cost * participant_size;
				if (new_payment < payment)
				{
					payment = new_payment;
					stay = false;
				}
			}
		}
		if (stay)
		{
			cout << "stay home";
		}
		else
		{
			cout << payment;
		}
		cout << '\n';
	}

	return 0;
}