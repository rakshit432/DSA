#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Helper function: compute area of the bounding rectangle
        // that covers all 1's in a subgrid defined by (r1..r2, c1..c2).
        auto get_area = [&](int r1, int r2, int c1, int c2) -> int {
            int min_r = m, max_r = -1;
            int min_c = n, max_c = -1;

            for (int i = r1; i <= r2; i++) {
                for (int j = c1; j <= c2; j++) {
                    if (grid[i][j] == 1) {
                        min_r = min(min_r, i);
                        max_r = max(max_r, i);
                        min_c = min(min_c, j);
                        max_c = max(max_c, j);
                    }
                }
            }

            // If there are no 1's in this region → invalid
            if (max_r == -1) return INT_MAX;
            return (max_r - min_r + 1) * (max_c - min_c + 1);
        };

        int ans = INT_MAX;

        // ------------------------------------------------
        // 1. Two horizontal cuts (3 horizontal bands)
        // ------------------------------------------------
        for (int i = 0; i < m - 2; i++) {
            for (int j = i + 1; j < m - 1; j++) {
                int a1 = get_area(0, i, 0, n - 1);
                int a2 = get_area(i + 1, j, 0, n - 1);
                int a3 = get_area(j + 1, m - 1, 0, n - 1);
                if (a1 != INT_MAX && a2 != INT_MAX && a3 != INT_MAX)
                    ans = min(ans, a1 + a2 + a3);
            }
        }

        // ------------------------------------------------
        // 2. Two vertical cuts (3 vertical slices)
        // ------------------------------------------------
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int a1 = get_area(0, m - 1, 0, i);
                int a2 = get_area(0, m - 1, i + 1, j);
                int a3 = get_area(0, m - 1, j + 1, n - 1);
                if (a1 != INT_MAX && a2 != INT_MAX && a3 != INT_MAX)
                    ans = min(ans, a1 + a2 + a3);
            }
        }

        // ------------------------------------------------
        // 3. Horizontal + vertical cut (top region split vertically)
        // ------------------------------------------------
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                int a1 = get_area(0, i, 0, j);
                int a2 = get_area(0, i, j + 1, n - 1);
                int a3 = get_area(i + 1, m - 1, 0, n - 1);
                if (a1 != INT_MAX && a2 != INT_MAX && a3 != INT_MAX)
                    ans = min(ans, a1 + a2 + a3);
            }
        }

        // ------------------------------------------------
        // 4. Horizontal + vertical cut (bottom region split vertically)
        // ------------------------------------------------
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                int a1 = get_area(0, i, 0, n - 1);
                int a2 = get_area(i + 1, m - 1, 0, j);
                int a3 = get_area(i + 1, m - 1, j + 1, n - 1);
                if (a1 != INT_MAX && a2 != INT_MAX && a3 != INT_MAX)
                    ans = min(ans, a1 + a2 + a3);
            }
        }

        // ------------------------------------------------
        // 5. Vertical + horizontal cut (left region split horizontally)
        // ------------------------------------------------
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                int a1 = get_area(0, j, 0, i);
                int a2 = get_area(j + 1, m - 1, 0, i);
                int a3 = get_area(0, m - 1, i + 1, n - 1);
                if (a1 != INT_MAX && a2 != INT_MAX && a3 != INT_MAX)
                    ans = min(ans, a1 + a2 + a3);
            }
        }

        // ------------------------------------------------
        // 6. Vertical + horizontal cut (right region split horizontally)
        // ------------------------------------------------
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                int a1 = get_area(0, m - 1, 0, i);
                int a2 = get_area(0, j, i + 1, n - 1);
                int a3 = get_area(j + 1, m - 1, i + 1, n - 1);
                if (a1 != INT_MAX && a2 != INT_MAX && a3 != INT_MAX)
                    ans = min(ans, a1 + a2 + a3);
            }
        }

        return ans;
    }
};
