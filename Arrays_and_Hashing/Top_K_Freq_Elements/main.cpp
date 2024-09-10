#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> frequencies;
        for (int& num : nums) {
            frequencies[num]++;
        }

        std::vector<std::pair<int, int>> highestFreqs;
        for (auto& freqs : frequencies) {
            highestFreqs.push_back(freqs);
        }

        std::sort(highestFreqs.begin(), highestFreqs.end(),
            [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                return a.second > b.second;
            });

        std::vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(highestFreqs[i].first);
        }

        return result;
    }
};



int main(){
    std::vector<int> nums = {1,2,2,3,3,3};
    int k = 2;

    Solution solution;

    std::vector<int> highest_freqs = solution.topKFrequent(nums, k);
    for(int& freq: highest_freqs){
        std::cout << freq << ' ';
    }
}
