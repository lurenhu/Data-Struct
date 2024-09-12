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
