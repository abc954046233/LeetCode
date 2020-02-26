#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main() {
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    vector<int> result = Solution().intersect(nums1, nums2);
    for (int i : result) {
        cout << i << endl;
    }
}
