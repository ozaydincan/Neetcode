#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;

        for(string& str: strs){
            encoded += str+"/x/00";
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        string delimiter = "/x/00";
        size_t pos = 0;

        while ((pos = s.find(delimiter)) != string::npos) {
            strs.push_back(s.substr(0, pos));
            s.erase(0, pos + 5);
        }

        return strs;
    }
};

int main(void){
    Solution solution;
    vector<string> strs = {"neet","code","love","you"};
    string encoded = solution.encode(strs);
    vector<string> decoded = solution.decode(encoded);
    cout << encoded <<'\n';
    for(string& str: decoded){
        cout<< str << '\n';
    }

    return 0;
}
