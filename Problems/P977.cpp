#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i = 0;
        int j = A.size() - 1;
        int pos = j;

        vector<int> res(A.size());
        while (i <= j) {
            int i_square = pow(A[i], 2);
            int j_square = pow(A[j], 2);

            if (i_square > j_square) {
                res[pos--] = i_square;
                i++;
            } else {
                res[pos--] = j_square;
                j--;
            }
        }

        return res;
    }
};

int main() {
    vector<int> A{-4, -1, 0, 3, 10};
    for (auto v : Solution().sortedSquares(A)) {
        cout << v << '\n';
    }
    return 0;
}
