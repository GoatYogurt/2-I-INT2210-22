#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 5;
const int COLS = 5;

bool isSafe(int x, int y, vector<vector<int>>& image, int targetColor, int newColor) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && image[x][y] == targetColor);
}

void floodFillDFS(int x, int y, vector<vector<int>>& image, int targetColor, int newColor) {
    if (!isSafe(x, y, image, targetColor, newColor)) {
        return;
    }

    image[x][y] = newColor;

    floodFillDFS(x + 1, y, image, targetColor, newColor);
    floodFillDFS(x - 1, y, image, targetColor, newColor);
    floodFillDFS(x, y + 1, image, targetColor, newColor);
    floodFillDFS(x, y - 1, image, targetColor, newColor);
}

void floodFill(int x, int y, vector<vector<int>>& image, int newColor) {
    int targetColor = image[x][y];

    floodFillDFS(x, y, image, targetColor, newColor);
}

void printImage(const vector<vector<int>>& image) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1, 1, 1},
        {1, 2, 2, 1, 1},
        {1, 2, 2, 2, 1},
        {1, 1, 1, 2, 1},
        {1, 1, 1, 2, 2}
    };

    printImage(image);
    floodFill(1, 1, image, 3);
    printImage(image);

    return 0;
}
