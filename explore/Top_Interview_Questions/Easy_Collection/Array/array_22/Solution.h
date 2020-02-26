//
// Created by liyang on 2020/2/23.
//

#ifndef ARRAY_22_SOLUTION_H
#define ARRAY_22_SOLUTION_H

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (i == prices.size() - 1) continue;
            else {
                if (prices[i] < prices[i + 1]) profit += prices[i + 1] - prices[i];
            }
        }
        return profit;
    }
};


#endif //ARRAY_22_SOLUTION_H
