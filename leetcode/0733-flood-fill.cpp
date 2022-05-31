// 733. Flood Fill
// Graph

#include <iostream>
#include <vector>
#include <deque>

using std::vector;
class Solution {
public:
    struct Pos
    {
        int r = 0; int c = 0;
    };

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        const int ROW = image.size();
        const int COL = image[0].size();

        int originalColor = image[sr][sc];

        if (originalColor == newColor)
            return image;

        std::deque<Pos> queue;
        queue.push_back(Pos{ sr, sc });

        while (!queue.empty()) {
            Pos pos = queue.front();
            queue.pop_front();

            image[pos.r][pos.c] = newColor;

            if (pos.r + 1 < ROW && image[pos.r + 1][pos.c] == originalColor)
                queue.push_back(Pos{ pos.r + 1, pos.c });

            if (pos.c + 1 < COL && image[pos.r][pos.c + 1] == originalColor)
                queue.push_back(Pos{ pos.r, pos.c + 1 });

            if (pos.r - 1 >= 0 && image[pos.r - 1][pos.c] == originalColor)
                queue.push_back(Pos{ pos.r - 1, pos.c });

            if (pos.c - 1 >= 0 && image[pos.r][pos.c - 1] == originalColor)
                queue.push_back(Pos{ pos.r, pos.c - 1 });
        }

        return image;
    }
};

int main() {
    Solution sln;

    vector<vector<int>> image1 = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };
    int sr = 1, sc = 1;
    int newColor = 2;

    sln.floodFill(image1, sr, sc, newColor);

    for (auto& row : image1) {
        for (int pixel : row) {
            std::cout << pixel;
        }
        std::cout << std::endl;
    }
}