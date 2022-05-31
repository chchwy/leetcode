// 242. Valid Anagram
// String, Hash Table

#include <string>
#include <iostream>
using std::string;

class Solution {
public:
    bool isAnagram(string s, string t) {

        const int len = 26;
        int letters[len];

        for (int i = 0; i < len; ++i) {
            letters[i] = 0;
        }

        for (int i = 0; i < s.length(); ++i) {
            letters[s[i] - 'a']++;
        }

        for (int i = 0; i < t.length(); ++i) {
            letters[t[i] - 'a']--;
        }

        for (int i = 0; i < len; ++i) {
            if (letters[i] != 0)
                return false;
        }
        return true;
    }
};

int main()
{
    string s = "anagram", t = "nagaram";
    Solution sln;
    std::cout << sln.isAnagram(s, t) << std::endl;
}