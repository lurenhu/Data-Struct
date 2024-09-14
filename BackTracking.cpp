#include "BackTracking.h"

void BackTrack(std::vector<int> &state, std::vector<int> &choices, std::vector<bool> &selected,
               std::vector<std::vector<int>> &res) {
    if (state.size() == choices.size()) {
        res.push_back(state);
        return;
    }

    std::unordered_set<int> duplicated;

    for (int i = 0; i < choices.size(); i++) {
        int choice = choices[i];
        if (!selected[i] && duplicated.find(choice) == duplicated.end()) {
            duplicated.emplace(choice);
            selected[i] = true;
            state.push_back(choice);
            BackTrack(state, choices, selected, res);
            selected[i] = false;
            state.pop_back();
        }
    }
}

/// @brief 全排列问题
/// @param nums
/// @return
std::vector<std::vector<int>> PermutationI(std::vector<int> &nums) {
    std::vector<int> state;
    std::vector<bool> selected(nums.size(), false);
    std::vector<std::vector<int>> res;
    BackTrack(state, nums, selected, res);
    return res;
}

void BackTrack(std::vector<int> &state, int target, int total, std::vector<int> &choices,
               std::vector<std::vector<int>> &res) {
    if (total == target) {
        res.push_back(state);
        return;
    }

    for (int i = 0; i < choices.size(); i++) {
        if (total + choices[i] > target) {
            continue;
        }
        state.push_back(choices[i]);
        BackTrack(state, target, total + choices[i], choices);
        state.pop_back();
    }
}

void BackTrack(std::vector<int> &state, int target, std::vector<int> &choices, int start,
               std::vector<std::vector<int>> &res) {
    if (target == 0) {
        res.push_back(state);
        return;
    }

    for (int i = start; i < choices.size(); i++) {
        if (target - choices[i] < 0) {
            break;
        }
        if (i > start && choices[i] == choices[i - 1]) {
            continue;
        }
        state.push_back(choices[i]);
        BackTrack(state, target - choices[i], choices, i + 1, res);
        state.pop_back();
    }
}

std::vector<std::vector<int>> SubSetSumINative(std::vector<int> &nums, int target) {
    std::vector<int> state;
    int total = 0;
    std::vector<std::vector<int>> res;
    BackTrack(state, target, total, nums, res);
    return res;
}

void BackTrack(int row, int n, std::vector<std::vector<string>> &state,
               std::vector<std::vector<std::vector<std::string>>> &res, std::vector<bool> &cols,
               std::vector<bool> &diags1, std::vector<bool> &diags2) {
    if (row == n) {
        res.push_back(state);
        return;
    }

    for (int col = 0; col < n; col++) {
        int diag1 = row - col + n - 1;
        int diag2 = row + col;
        if (!cols[col] && !diags1[diag1] && !diags2[diag2]) {
            state[row][col] = "Q";
            cols[col] = diags1[diag1] = diags2[diag2] = true;
            BackTrack(row + 1, n, state, res, cols, diags1, diags2);
            state[row][col] = "#";
            cols[col] = diags1[diag1] = diags2[diag2] = false;
        }
    }
}

std::vector<std::vector<std::vector<std::string>>> nQueen(int n) {
    std::vector<std::vector<std::string>> state(n, vector<string>(n, "#"));
    std::vector<bool> cols(n, false);           // 记录列是否有皇后
    std::vector<bool> diags1(2 * n - 1, false); // 记录主对角线上是否有皇后
    std::vector<bool> diags2(2 * n - 1, false); // 记录次对角线上是否有皇后
    std::vector<std::vector<std::vector<std::string>>> res;

    backtrack(0, n, state, res, cols, diags1, diags2);

    return res;
}
