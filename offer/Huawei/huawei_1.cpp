#include <iostream>

using namespace std; 

int main()
{
	int num;
	double	price;
	cin >> num >> price;
	
	double total_1 = 0, total_2 = 0;
	
	if (num >= 3)
	{
		total_1 = price * num * 0.7;
	}
	else
	{
		total_1 = price * num;
	}
	
	if (total_1 < 50)
	{
		total_1 += 10;
	}
	
	//2
	total_2 = price * num;
	
	total_2 -= ((int (total_2)) / 10) * 2;
	if (total_2 < 99)
	{
		total_2 += 6;
	}
	
	if (total_1 < total_2)
		cout << 1;
	else if (total_2 == total_1)
		cout << 0;
	else 
		cout << 2;
	
}