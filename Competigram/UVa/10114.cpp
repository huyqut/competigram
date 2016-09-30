#include <bits/stdc++.h>

using namespace std;

struct Record
{
	int month;
	double rate;
	Record() : month(0), rate(0.0f) {}
	Record(int month, double rate) : month(month), rate(rate) {}
};

int main()
{
	int month_size, record_size;
	double down_payment, loan;
	while (cin >> month_size && month_size > 0)
	{
		vector<Record> records;
		cin >> down_payment >> loan >> record_size;
		records.reserve(record_size);
		for (; record_size > 0; --record_size)
		{
			int month;
			double rate;
			cin >> month >> rate;
			records.push_back(Record(month, rate));
		}
		double car_value = down_payment + loan;
		double monthly_payment = loan / month_size;
		int current_month = 0;
		auto record = records.begin();
		auto end_record = records.end();
		double current_rate_inv = 1 - record->rate;
		car_value *= current_rate_inv;
		++record;
		if (car_value <= loan)
		{
			for (++current_month ; current_month <= month_size; ++current_month)
			{
				if (record != end_record)
				{
					if (current_month == record->month)
					{
						current_rate_inv = 1 - record->rate;
						++record;
					}
				}
				car_value *= current_rate_inv;
				loan -= monthly_payment;
				if (car_value > loan)
				{
					break;
				}
			}
		}
		if (current_month == 1)
		{
			cout << "1 month";
		}
		else
		{
			cout << current_month << " months";
		}
		cout << '\n';
	}
	return 0;
}