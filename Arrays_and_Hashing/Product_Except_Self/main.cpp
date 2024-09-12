
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefix(len, 1);
        vector<int> suffix(len, 1);
        vector<int> products(len, 1);
        
        for (int i = 1; i < len; ++i) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for (int i = len - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < len; ++i) {
            products[i] = prefix[i] * suffix[i];
        }

        return products;
    }
};

int main () {
    Solution solution;
    vector<int> nums = {1, 2, 4, 6};

    auto start = high_resolution_clock::now();

    vector<int> product = solution.productExceptSelf(nums);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    for (int& element : product) {
        cout << element << '\n';
    }

    cout << "Execution time: " << duration.count() << " microseconds\n";

    return 0;
}

