#include <bits/stdc++.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	size_t requirement_size, proposal_size;
	size_t index = 1;
	while (cin >> requirement_size && requirement_size > 0)
	{
		cin >> proposal_size;
		cin.ignore();
		for (size_t i = 0; i < requirement_size; ++i)
		{
			string line; getline(cin, line);
		}

		unsigned met_requirements = 0;
		double price;
		string best_proposal;
		while (proposal_size-- > 0)
		{
			string proposal_name; getline(cin, proposal_name);
			double proposed_price; cin >> proposed_price;
			unsigned proposed_requirements; cin >> proposed_requirements;
			cin.ignore();
			if (proposed_requirements > met_requirements)
			{
				met_requirements = proposed_requirements;
				price = proposed_price;
				best_proposal = proposal_name;
			}
			else if (proposed_requirements == met_requirements)
			{
				if (proposed_price < price)
				{
					price = proposed_price;
					best_proposal = proposal_name;
				}
			}
			for (size_t i = 0; i < proposed_requirements; ++i)
			{
				string line; getline(cin, line);
			}
		}
		if (index > 1)
		{
			cout << '\n';
		}
		cout << "RFP #" << index << '\n' << best_proposal << '\n';
		++index;
	}

	return 0;
}