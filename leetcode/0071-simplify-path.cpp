// 71. Simplify Path
// String, Stack

#include <string>
#include <deque>
#include <sstream>
#include <iostream>

using std::string;
using std::deque;
using std::istringstream;

class Solution {
public:
    string simplifyPath(string path) {

        deque<string> pathStack;
        istringstream sin(path);
        string token;

        // skip the first slash
        std::getline(sin, token, '/');

        while (std::getline(sin, token, '/')) {

            if (token == "") {
                // do nothing
            }
            else if (token == ".") {
                // do nothing
            }
            else if (token == "..") {
                if (!pathStack.empty())
                    pathStack.pop_back();
            }
            else {
                pathStack.push_back(token);
            }
        }

        string canonicalPath;
        while (!pathStack.empty()) {

            canonicalPath.append("/");
            canonicalPath.append(pathStack.front());

            pathStack.pop_front();
        }

        if (canonicalPath.empty()) {
            canonicalPath.append("/");
        }
        return canonicalPath;
    }
};

int main() {

    Solution sln;
    std::cout << sln.simplifyPath("/home//foo/");

    return 0;
}