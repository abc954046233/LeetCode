#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << Solution().maxProfit(prices) << endl;
}
