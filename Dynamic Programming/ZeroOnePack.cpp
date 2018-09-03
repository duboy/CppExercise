#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std; 

void printVV(const vector<vector<int>> &F)
{
	for (int i = 0; i < F[0].size(); ++i)
	{
		cout.width(2);
		cout << i << " ";
	}
	cout << endl;
	for (auto i : F)
	{
		//cout.width(3);
		for (auto j : i)
		{
			cout.width(2);
			cout << j << " ";
		}
			
		cout << endl;
	}
	cout << endl;
}

void printV(const vector<int> &F)
{
	for (int i = 0; i < F.size(); ++i)
	{
		cout.width(2);
		cout << i << " ";
	}

	cout << endl;

	for (auto i : F)
	{
		cout.width(2);
		cout << i << ' ';
	}
	cout << endl;
}

int ZeroOnePack2D(int V, vector<int> cost, vector<int> weight)
{
	//int *F = new int[cost.size() * V];
	int N = cost.size() - 1;
	vector<vector<int>> F(N + 1, vector<int>(V + 1, 0));

	for (int i = 1; i <= N; ++i)
	{
		for (int v = cost[i]; v <= V; ++v)
		{
			F[i][v] = max(F[i - 1][v], F[i - 1][v - cost[i]] + weight[i]);
		}
	}
	printVV(F);
	return F[N][V];
}

int ZeroOnePack1D(int V, vector<int> cost, vector<int> weight)
{
	int N = cost.size() - 1;
	vector<int> F(V + 1);

	for (int i = 1; i <= N; ++i)
	{
		for (int v = V; v >= cost[i]; --v) 
		{
			F[v] = max(F[v], F[v - cost[i]] + weight[i]);
		}
	}
	printV(F);

	return F[V];
}

int main()
{
	int V = 34;
	vector<int> cost = { 0,2,7,3,4,8,5,8,6,4,16 };
	vector<int> weight = { 0,15,25,8,9,15,9,13,9,6,14 };

	cout << ZeroOnePack2D(V, cost, weight) << endl;
	cout << ZeroOnePack1D(V, cost, weight) << endl;

}