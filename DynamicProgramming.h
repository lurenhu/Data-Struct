#include <iostream>
#include <vector>

int ClimbingStairsDPComp(int n);
int MinCostClimbingStairsDPComp(std::vector<int> &cost);
int ClimbingStairsConstraintDP(int n);
int KnapsackDPComp(std::vector<int> &wgt, std::vector<int> &val, int cap);
int UnboundedKnapsackDP(std::vector<int> &wgt, std::vector<int> &val, int cap);
int CoinChangeDP(std::vector<int> &coins, int amt);
int CoinChangeIIDP(std::vector<int> &coins, int amt);
int EditDistanceDP(std::string s, std::string t);