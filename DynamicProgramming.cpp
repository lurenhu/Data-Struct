#include "DynamicProgramming.h"

int ClimbingStairsDPComp(int n) {
    if (n == 1 || n == 2) {
        return n;
    }

    int a = 1, b = 2;
    for (int i = 3; i <= n; i++) {
        int temp = b;
        b = a + b;
        a = temp;
    }
    return b;
}

int MinCostClimbingStairsDPComp(std::vector<int> &cost) {
    int n = cost.size() - 1;
    if (n == 1 || n == 2) {
        return cost[n];
    }

    int a = cost[1], b = cost[2];
    for (int i = 3; i <= n; i++) {
        int temp = b;
        b = std::min(a, temp) + cost[i];
        a = temp;
    }
    return b;
}

int ClimbingStairsConstraintDP(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(3, 0));
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[2][1] = 0;
    dp[2][2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i][1] = dp[i - 1][2];
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
    }
    return dp[n][1] + dp[n][2];
}

int KnapsackDPComp(std::vector<int> &wgt, std::vector<int> &val, int cap) {
    int n = wgt.size();
    std::vector<int> dp(cap + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = cap; j >= 1; j--) {
            wgt[j] = std::max(dp[j], dp[j - wgt[i - 1] + val[i - 1]]);
        }
    }
    return dp[cap];
}

int UnboundedKnapsackDP(std::vector<int> &wgt, std::vector<int> &val, int cap) {
    int n = wgt.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(cap + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= cap; c++) {
            if (wgt[i - 1] > c) {
                dp[i][c] = dp[i - 1][c];
            } else {
                dp[i][c] = std::max(dp[i - 1][c], dp[i][c - wgt[i - 1]] + val[i][c]);
            }
        }
    }
    return dp[n][cap];
}

int CoinChangeDP(std::vector<int> &coins, int amt) {
    int n = coins.size();
    int MAX = amt + 1;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amt + 1, 0));
    for (int a = 1; a <= amt; a++) {
        dp[0][a] = MAX;
    }
    for (int i = 1; i <= n; i++) {
        for (int a = 1; a <= amt; a++) {
            if (coins[i - 1] > a) {
                dp[i][a] = dp[i - 1][a];
            } else {
                dp[i][a] = std::min(dp[i - 1][a], dp[i][a - coins[i - 1]] + 1);
            }
        }
    }
    return dp[n][amt] != MAX ? dp[n][amt] - 1;
}

int CoinChangeIIDP(std::vector<int> &coins, int amt) {
    int n = coins.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amt + 1, 0));
    for (int i = 1; i <= amt; i++) {
        dp[i][0] = 1;
    }

    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= amt; b++) {
            if (coins[a - 1] > b) {
                dp[a][b] = dp[a - 1][b];
            } else {
                dp[a][b] = dp[a - 1][b] + dp[a][b - coins[a - 1]];
            }
        }
    }
    return dp[n][amt];
}

int EditDistanceDP(std::string s, std::string t) {
    int n = s.length(), m = t.length();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = std::min(dp[i - 1][j - 1] + 1, dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
