#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	while (true)
	{
		vector<int> cycles;
		int cycle;
		if (cin >> cycle && cycle != 0)
		{
			do {
				cycles.push_back(cycle);
				cin >> cycle;
			} while (cycle != 0);
		}
		else
		{
			break;
		}
		vector<int> starts(cycles.size(), 0);
		vector<int> ends(cycles.size(), 0);
		auto compare = [&](pair<int, int> const & lhs, pair<int, int> const & rhs)
		{
			if (lhs.first > rhs.first)
			{
				return true;
			}
			if (lhs.first < rhs.first)
			{
				return false;
			}
			return cycles[lhs.second] > cycles[rhs.second];
		};
		priority_queue<
			pair<int, int>,
			vector<pair<int, int>>,
			function<bool(pair<int, int> const &, pair<int, int> const &)>>
			heap(compare);
		pair<int, int> top;
		for (int i = 0; i < cycles.size(); ++i)
		{
			ends[i] = cycles[i] - 5;
			heap.push(pair<int, int>(ends[i], i));
			starts[i] = 0;
		}
		int result = -1;
		while (true)
		{
			top = heap.top();
			heap.pop();
			starts[top.second] += 2 * cycles[top.second];
			if (starts[top.second] > 18000)
			{
				break;
			}
			ends[top.second] = starts[top.second] + cycles[top.second] - 5;
			if (ends[top.second] > 18000)
			{
				ends[top.second] = 18001;
			}
			heap.push(pair<int, int>(ends[top.second], top.second));
			int begin = starts[0];
			int end = ends[0];
			for (int i = 1; i < starts.size() && begin < end; ++i)
			{
				int new_begin = starts[i];
				int new_end = ends[i];
				if (begin < new_begin)
				{
					begin = new_begin;
				}
				if (end > new_end)
				{
					end = new_end;
				}
			}
			if (begin < end)
			{
				result = begin;
				break;
			}
		}
		if (result == -1)
		{
			cout << "Signals fail to synchronise in 5 hours\n";
		}
		else
		{
			int hours = result / 3600;
			result %= 3600;
			int minutes = result / 60;
			result %= 60;
			int seconds = result;
			cout << 0 << hours << ':';
			if (minutes >= 10)
			{
				cout << minutes;
			}
			else
			{
				cout << 0 << minutes;
			}
			cout << ':';
			if (seconds >= 10)
			{
				cout << seconds;
			}
			else
			{
				cout << 0 << seconds;
			}
			cout << '\n';
		}
	}

	return 0;
}