#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        // 输入[]
        if (nums.empty())
            return result;
        // 输入正常
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            vector<int> v;
            v.clear();
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    v.push_back(nums[i]);
                }
            }
            result.push_back(v);
        }

        return result;
    }
};

//若输入为
//[1, 2, 3]
//每位为0代表不在集合，为1代表在集合，则有如下pow(2, 3)种可能
//000
//001
//010
//011
//100
//101
//110
//111
//
//通过二进制移位运算实现对以上排列的生成
//1:
//0000 0000 0000 0000 0000 0000 0000 0001
//1 << 3:
//0000 0000 0000 0000 0000 0000 0000 1000
//[0b000..0b1000]即3位二进制的全排列
//p.s. 直接[0..7]也是可以的，但是上述方法可以清楚地显示出意图

//判断i位是1还是0：
//mask:
//0010
//1 << 0:
//001
//mask & (1 << 0)的结果只取决于(1 << 0)中的1和mask中与之对应的位的值
//所以mask & (1 << i)为0代表mask的i位是0，否则为1