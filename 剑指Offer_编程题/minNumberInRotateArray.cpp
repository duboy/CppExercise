#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
               if (!rotateArray.size())
            return 0;
        else
        {
            int left = 0;
            int right = rotateArray.size() - 1;
            // auto mid = ((right - left) / 2) + left;
            while (1)
            {
                auto mid = ((right - left) / 2) + left;
                if (right - left == 1)
                    return rotateArray[right];
                if (rotateArray[mid] < rotateArray[left])
                {
                    right = mid;
                }
                else
                    left = mid;
            }
        }
    }

};

int main()
{
    Solution s1;
    vector<int> ivec = { 6501,6828,6963,7036,7422,7674,8146,8468,8704,8717,9170,9359,9719,9895,9896,9913,9962,154,293,334,492,1323,1479,1539,1727,1870,1943,2383,2392,2996,3282,3812,3903,4465,4605,4665,4772,4828,5142,5437,5448,5668,5706,5725,6300,6335};
    // vector<int> ivec = {7,8,9,10,11, 1,2,3,4};
    // vector<int> ivec = {7, 1,2,3};
    // cout << *((ivec.end() - ivec.begin())/2 + ivec.begin());
    int a = 5;
    int b = a /2;
    // cout << ivec.size() << endl;
    cout << s1.minNumberInRotateArray(ivec);
}