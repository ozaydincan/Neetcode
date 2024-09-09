#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;

class Solution{
public:
    bool hasDuplicate(vector<int> &nums){
        unordered_set<int> duplicates(nums.begin(), nums.end());
        return duplicates.size() != nums.size();
    }
};


int main(){
    Solution solution;
    vector<int> nums_1 = {1,2,3,3,4};
    vector<int> nums_2 = {1,2,3,4};

    bool containsDuplicate_1 = solution.hasDuplicate(nums_1);
    bool containsDuplicate_2 = solution.hasDuplicate(nums_2);
    cout<<boolalpha << "Solution to first test: " << containsDuplicate_1<< '\n'<<"Solution to second test: "<<containsDuplicate_2<<endl;
    return 0;
}
