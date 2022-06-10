// 131. Palindrome Partitioning
// Backtracking, String

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class Solution {
public:
    bool isPalindrome(const string& s) {
        if (s.empty()) return false;
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - i - 1])
                return false;
        }
        return true;
    }

    void backtrack(const string& s,
        vector<string>& path,
        int startIndex,
        vector<vector<string>>& results) {

        if (startIndex >= s.size()) {
            results.push_back(path);
            return;
        }

        for (int i = startIndex; i < s.size(); ++i) {

            string partition = s.substr(startIndex, i - startIndex + 1);
            if (isPalindrome(partition)) {
                path.push_back(partition);
                backtrack(s, path, i + 1, results);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> results;

        for (int i = 0; i < s.size(); ++i) {

            vector<string> path;
            string partition = s.substr(0, i + 1);

            if (isPalindrome(partition)) {
                path.push_back(partition);
                backtrack(s, path, i + 1, results);
                path.pop_back();
            }
        }
        return results;
    }
};

int main() {
    Solution sln;
    auto results = sln.partition("aab");
    for (const vector<string>& partitions : results) {
        for (const string& s : partitions) {
            std::cout << "[" << s << "],";
        }
        std::cout << std::endl;
    }
    return 0;
}
