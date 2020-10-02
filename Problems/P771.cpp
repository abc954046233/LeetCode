//
// Created by liyang on 2020/10/2.
//

#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> gem;

        for (auto j : J) {
            gem.insert(j);
        }

        int cnt = 0;
        for (auto s : S) {
            if (gem.find(s) != gem.end())
                cnt++;
        }

        return cnt;

//        方法二：
//        bool gem[123] = {false};
//
//        for (auto j : J) {
//            gem[j] = true;
//        }
//
//        int cnt = 0;
//        for (auto s : S) {
//            if (gem[s])
//                cnt++;
//        }
//
//        return cnt;
    }
};
