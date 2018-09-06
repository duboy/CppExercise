#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 


int demCore(int capacityContainer, vector<int> &carats)
{
	if (carats.size() <= 1)
		return carats.size();

	auto flag = carats.begin();

	for (auto i = carats.begin() + 1; i != carats.end(); ++i)
	{
		if (carats[0] + *i <= capacityContainer)
		{
			flag = i;
		}
		else
			break;
	}
	if (flag != carats.begin())
		carats.erase(flag);
	carats.erase(carats.begin());

	return 1 + demCore(capacityContainer, carats);
}

int dem(int numPieces, int capacityContainer, int carats[])
{
	vector<int> car(carats, carats + numPieces);

	sort(car.begin(), car.end());

	return demCore(capacityContainer, car);
}

int main()
{

	//int numPieces = 5, capacityContainer = 12;
	//vector<int> carats = {4, 8, 6, 7, 8};

	//cin >> numPieces

	int numPieces = 9, capacityContainer = 12;
	vector<int> carats = { 6, 5, 2, 1, 7, 4, 9, 10, 4 };
	
	sort(carats.begin(), carats.end());
	//cout << dem(capacityContainer, carats);

	int carat[] = { 6, 5, 2, 1, 7, 4, 9, 10, 4 };

	//int carats[] = { 4, 8, 6, 7, 8 };

	cout << dem(9, 12, carat);

	cout << demCore(capacityContainer, carats);

}