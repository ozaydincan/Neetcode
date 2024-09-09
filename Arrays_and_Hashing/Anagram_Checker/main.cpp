#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
    public:
    bool isAnagram(string s, string t){
        if (s.length() != t.length()){
            return false;
        }
        unordered_map<char, int> seen_s;
        unordered_map<char ,int> seen_t;

        int s_len = s.length();

        for (int j = 0; j< s_len; j++){
            seen_s[s[j]]++;
            seen_t[t[j]]++;
        }
        if (seen_s != seen_t){
            return false;
        } 
        
        return true;        
    }
};


int main (int argc, char *argv[]) {
    Solution solution;
    string s = "racecar", t = "carrace";
    bool flag = solution.isAnagram(s, t);
    cout << boolalpha<<flag<<'\n';
    return 0;
}
