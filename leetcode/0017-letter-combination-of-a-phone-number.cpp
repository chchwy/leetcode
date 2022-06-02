// 17. Letter Combinations of a Phone Number
// Backtracking

#include <vector>
#include <iostream>

using std::vector;
using std::string;


class Solution {
public:
	string letters[10];

	void backtrack(string& path, const string& digits, int next, vector<string>& results) {

		if (path.size() == digits.size()) {
			results.push_back(path);
			return;
		}

		int n = digits[next] - '0';
		string s = letters[n];

		for (int i = 0; i < s.size(); ++i) {
			path.push_back(s[i]);
			backtrack(path, digits, next + 1, results);
			path.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {

		if (digits.empty())
			return {};

		letters[2] = "abc";
		letters[3] = "def";
		letters[4] = "ghi";
		letters[5] = "jkl";
		letters[6] = "mno";
		letters[7] = "pqrs";
		letters[8] = "tuv";
		letters[9] = "wxyz";

		// digits 23
		// 2 to abc
		vector<string> results;
		string path = "";
		backtrack(path, digits, 0, results);

		return results;
	}
};

int main() {
	Solution sln;
	auto results = sln.letterCombinations("23");

	for (const string& s : results) {
		std::cout << s << std::endl;
	}
	return 0;
}