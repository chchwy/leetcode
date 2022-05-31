// 1002. Find Common Characters
// String, Hash Table

#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;

int min(int a, int b) { return (a < b) ? a : b; }

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        constexpr int numCharacters = 26;
        int commonCharacters[numCharacters] = { 0 };

        const string w0 = words[0];
        for (int i = 0; i < w0.size(); ++i) {
            commonCharacters[w0[i] - 'a']++;
        }
        for (int k = 1; k < words.size(); ++k) {

            int characters[numCharacters] = { 0 };
            const string& s = words[k];
            for (int i = 0; i < s.size(); ++i) {
                characters[s[i] - 'a']++;
            }

            for (int i = 0; i < numCharacters; ++i) {
                commonCharacters[i] = min(commonCharacters[i], characters[i]);
            }
        }

        std::vector<string> result;
        for (int i = 0; i < numCharacters; ++i) {

            int count = commonCharacters[i];
            for (int j = 0; j < count; ++j)
                result.push_back(string(1, 'a' + i));
        }

        return result;
    }
};

int main()
{
    Solution sln;

    vector<string> words = 
    {
        {"bella"}, {"label"}, {"roller"}
    };
    vector<string> commons = sln.commonChars(words);
    for (const string& s : commons)
        std::cout << s << " ";
    std::cout << std::endl;
    return 0;
}