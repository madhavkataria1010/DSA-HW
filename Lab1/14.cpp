/*Write a function that takes an integer input n and returns an n×n matrix filled in a spiral order. The matrix should start filling from the top-left corner, proceeding right across the first row, then down the last column, then left across the bottom row, and finally back up the first column. This pattern should continue inward until the entire matrix is filled.

Example: For n=3
1 2 3
8 9 4
7 6 5*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> generateSpiralMatrix(int n)
{
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; ++i)
        {
            matrix[top][i] = num++;
        }
        top++;

        for (int i = top; i <= bottom; ++i)
        {
            matrix[i][right] = num++;
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; --i)
            {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; --i)
            {
                matrix[i][left] = num++;
            }
            left++;
        }
    }

    return matrix;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> spiralMatrix = generateSpiralMatrix(n);

    for (const auto &row : spiralMatrix)
    {
        for (auto elem : row)
        {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
