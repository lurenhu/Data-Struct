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
