#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;

        for (int i = 0; i < (int)nums.size(); i++) {
            int complement = target - nums[i];

            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }

            num_map[nums[i]] = i;
        }

        return {};
    }
};


int main(){
    Solution solution;
    vector<int> nums = {3,4,5,6};
    int target = 7;

    vector<int> idx = solution.twoSum(nums, target);

    for (int &i: idx){
        cout << i << '\n';
    }

    return 0;
}
