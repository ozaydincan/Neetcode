#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> chunks;
        for (string& str: strs){
            array<int, 26> count = {0};
            for (char& c: str){
                int i = int(c) - int('a');
                count[i]++;
            }

            chunks[count].push_back(str);
      }

        vector<vector<string>> anagramChunks;
        for(auto& pair: chunks){
            anagramChunks.push_back(pair.second);
        }

        return anagramChunks;
        
    }
};
    
int main(void){
    vector<string> strs = {"act","pots","tops","cat","stop","hat"};
    Solution solution;

    vector<vector<string>> answer = solution.groupAnagrams(strs);

    for(const auto& group: answer){
        for(const string& anagram: group){
            cout << anagram<<" ";
        }
        cout << '\n';
    }



    return 0;
}
