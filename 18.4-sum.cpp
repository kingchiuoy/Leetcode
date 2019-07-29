#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */
class Solution {
public:
    // int ind1, ind2, ind3, ind4;
    // int cur_sum(vector<int>&nums) {
    //     return nums[ind1] + nums[ind2] + nums[ind3] + nums[ind4];
    // }

    // vector<int> tnums;
    // vector<vector<int>> result;

    // void Sum2(int ind1, int ind4,int target) {
    //     int ind2 = ind1+1;
    //     int ind3 = ind4-1;
    //     while(ind2 < ind3) {
    //             if(tnums[ind2] + tnums[ind3] < target) {
    //                 ind2++;
    //             } else if(tnums[ind2] + tnums[ind3] > target) {
    //                 ind3--;
    //             } else {
    //                 result.push_back({tnums[ind1], tnums[ind2], tnums[ind3], tnums[ind4]});
    //                 ind2++;
    //                 ind3--;
    //             }
    //     }
    // }

    // vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     if(nums.size() < 4) return result;
    //     // vector<int> nums = anums;
    //     sort(nums.begin(), nums.end());
    //      tnums = nums;
    //     ind1 = 0; ind2 = 1; ind3 = nums.size()-2; ind4 = nums.size()-1;
    //     while(ind1 < ind4-2) {
    //         Sum2(ind1, ind4, target-nums[ind1]-nums[ind4]);
    //         if(ind1 + 1 < ind4-2)
    //         Sum2(ind1+1, ind4, target-nums[ind1+1]-nums[ind4]);
    //         if(ind1 + 1 < ind4-3)
    //         Sum2(ind1, ind4-1, target-nums[ind1]- nums[ind4-1]);
    //     }
    //     return result;
    // }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-3 ; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < nums.size()-2; ++j) {
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                int l = j+1, k = nums.size()-1;
                while(l < k) {
                    int cur_sum = nums[i]+nums[j]+nums[l]+nums[k];
                    if(cur_sum == target) {
                        result.push_back({nums[i], nums[j], nums[l], nums[k]});
                        l++;
                        while (l + 1 < k && nums[l+1] == nums[l])
                           l++;
                        k--;
                        while (k-1 >= 0 && nums[k-1] == nums[k])
                           k--;                        
                    } else if(cur_sum < target) {
                        l++;
                    } else {
                        k--;
                    }
                }
            }
        }
    }
};

// int ind1, ind2, ind3, ind4;

// int cur_sum(vector<int>&nums) {
//     return nums[ind1] + nums[ind2] + nums[ind3] + nums[ind4];
// }

void print_result(vector<vector<int>>& result) {
    for(auto i:result) {
        cout << "[";
        for(auto j:i) {
            cout << j << ",";
        }
        cout << "]" << endl;
    }
}

vector<vector<int>> tests(vector<int> nums, int target) {
        vector<vector<int>> result;
        if(nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-3 ; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < nums.size()-2; ++j) {
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                int l = j+1, k = nums.size()-1;
                while(l < k) {
                    int cur_sum = nums[i]+nums[j]+nums[l]+nums[k];
                    if(cur_sum == target) {
                        result.push_back({nums[i], nums[j], nums[l], nums[k]});
                        l++;
                        while (l + 1 < k && nums[l+1] == nums[l])
                           l++;
                        k--;
                        while (k-1 >= 0 && nums[k-1] == nums[k])
                           k--;                        
                    } else if(cur_sum < target) {
                        l++;
                    } else {
                        k--;
                    }
                }
            }
        }
    }

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result;
    result = tests(nums, target);
    print_result(result);
}




