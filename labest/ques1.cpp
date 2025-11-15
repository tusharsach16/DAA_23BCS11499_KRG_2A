#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];

        auto countLessEqual = [&](int mid) {
            int count = 0;
            int col = n - 1;
            for (int row = 0; row < n; row++) {
                while (col >= 0 && matrix[row][col] > mid)
                    col--;
                count += (col + 1);
            }
            return count;
        };

        while (low < high) {
            int mid = low + (high - low) / 2;
            int cnt = countLessEqual(mid);

            if (cnt < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    Solution s;
    cout << s.kthSmallest(matrix, 8) << endl;  
    return 0;
}
