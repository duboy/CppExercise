#include <iostream>
#include <vector>
#include <stack>
#include<queue>
using namespace std;

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence)
	{
		if (sequence.size() == 0)
			return false;
		return Verify(sequence);

	}

	bool Verify(vector<int> &sequence)
	{
		vector<int> left, right;
		if (sequence.size() <= 1)
			return true;

		int n = sequence.size() - 1;
		int beg = 0, split = n;
		int end = sequence[n];

		while (sequence[n] < sequence[split - 1])
		{
			right.push_back(sequence[--split]);
			if (split == 0)
				break;
		}

		while (sequence[beg] != sequence[split])
		{
			left.push_back(sequence[beg++]);
		}


		//left.insert(left.begin(), sequence.begin(), isplit + 1);
		//right.insert(right.begin(), isplit + 1, sequence.end() - 1);

		if (max(left, end) && min(right, end))
			return Verify(left) && Verify(right);
		else
			return false;

		return true;
	}

	bool min(vector<int> &sequence ,int end)
	{
		if (sequence.size() == 0)
			return true;
		int min = sequence[0];
		for (auto i : sequence)
			min = i < min ? i : min;
		return end < min;
	}
	bool max(vector<int> &sequence, int end)
	{
		if (sequence.size() == 0)
			return true;
		int max = sequence[0];
		for (auto i : sequence)
			max = i > max ? i : max;
		return end > max;
	}
};

int main()
{
	 vector<int> sequence = { 5, 7, 6, 9, 11, 10, 8 };
	// vector<int> sequence = { 4, 6, 7, 5 };
	// vector<int> sequence = { 5, 4, 3, 2, 1 };
	// vector<int> sequence = { 7, 4, 6, 5 };

	Solution sol;
	cout << sol.VerifySquenceOfBST(sequence);
	
}