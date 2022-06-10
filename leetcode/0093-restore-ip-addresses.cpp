// 93. Restore IP Addresses
// Backtracking

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class Solution {
public:
    bool isValidIPsection(const string& s) {
        if (s.empty()) return false;
        if (s.size() == 1 && s[0] == '0') {
            return true;
        }
        if (s[0] == '0') {
            return false;
        }

        int n = std::stoi(s);
        return (n < 256);
    }

    string toIPString(const vector<string>& v) {
        string ip = v[0] + "." + v[1] + "." + v[2] + "." + v[3];
        return ip;
    }

    void backtrack(const string& s, vector<string>& path, int startIndex, vector<string>& validIPs) {
        if (path.size() == 4) {
            if (startIndex == s.size()) {
                validIPs.push_back(toIPString(path));
            }
            return;
        }

        for (int i = startIndex; i < (startIndex + 3); ++i) {
            string section = s.substr(startIndex, i - startIndex + 1);
            if (isValidIPsection(section)) {
                path.push_back(section);
                backtrack(s, path, i + 1, validIPs);
                path.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {

        vector<string> validIPs;

        // backtracking
        for (int i = 0; i < 3; ++i) {
            // start position = 0
            // i means the end position, [0, 0]
            string section = s.substr(0, i + 1);

            if (isValidIPsection(section)) {
                vector<string> path;
                path.push_back(section);
                backtrack(s, path, i + 1, validIPs);
                path.pop_back();
            }
        }

        return validIPs;
    }
};

int main() {
    Solution sln;
    vector<string> results = sln.restoreIpAddresses("25525511135");
    for (const string& s : results) {
        std::cout << s << std::endl;
    }
    return 0;
}
