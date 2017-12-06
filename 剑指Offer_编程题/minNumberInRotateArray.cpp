#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (!rotateArray.size())
            return 0;
        else
        {
            auto beg = rotateArray.begin();
            int min = *beg;
            for (; beg != rotateArray.end(); ++beg)
            {
                min = min < *beg ? min : *beg;
            }
            return min;
        }
    }
};

int main()
{
    Solution s1;
    vector<int> ivec = {7,2,3,4,5};
    cout << s1.minNumberInRotateArray(ivec);
}