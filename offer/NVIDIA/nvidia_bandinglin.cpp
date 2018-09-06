#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int FunCore(int n, int m)
{
	if (n == 1)
		return 0;
	if (n < m)
		return (FunCore(n - 1, m) + m) % n;
	int s = FunCore(n - n / m, m) - n % m;
	return s < 0 ? s + n : s + s / (m - 1);
}

int Fun(int N, int M)
{
	return FunCore(N, M) + 1;
}



int main()
{
	cout << Fun(5, 3);
}