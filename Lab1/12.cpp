/*Write a program that generates an nxn matrix filled with concentric layers of characters. The matrix is filled starting from a given character, with each concentric layer using the next character in the alphabet.

Description
Given a size n and a starting character c, create an nxn matrix where each concentric layer is filled with increasing characters starting from c. The outermost layer uses the starting character c, the next layer uses the character c+1 and so on. Characters should wrap around from z to a if necessary.

Input format:
1. The first line of input contains an integer n, representing the size of the matrix.
2. The second line of input contains a single character c, representing the starting character.

Output format:
Print the nxn matrix where each layer is filled with the appropriate character

Constraints
n lies between 1 to 20
c is a lowercase English character from a to z

Example:
Input:
5
b

Output:
bbbbb
bcccb
bcdcb
bcccb
bbbbb*/

#include <iostream>
#include <vector>
using namespace std;

class CharacterMatrix {
private:
    int n;
    char startChar;
    vector<vector<char>> matrix;

public:
    // Constructor to initialize the matrix size and starting character
    CharacterMatrix(int size, char ch) : n(size), startChar(ch), matrix(size, vector<char>(size, ' ')) {}

    // Method to generate the concentric character matrix
    void generateMatrix() {
        int layers = (n + 1) / 2;
        for(int layer = 0; layer < layers; layer++) {
            char currentChar = startChar + layer;
            if(currentChar > 'z') {
                currentChar = 'a' + (currentChar - 'z' - 1);
            }
            for(int i = layer; i < n - layer; i++) {
                matrix[layer][i] = currentChar;
                matrix[n - layer - 1][i] = currentChar;
                matrix[i][layer] = currentChar;
                matrix[i][n - layer - 1] = currentChar;
            }
        }
    }

    // Method to print the generated matrix
    void printMatrix() const {
        for(const auto& row : matrix) {
            for(char c : row) {
                cout << c;
            }
            cout << '\n';
        }
    }
};

int main() {
    int n;
    char startChar;

    // Read the size of the matrix
    cin >> n;
    // Read the starting character
    cin >> startChar;

    // Create a CharacterMatrix object
    CharacterMatrix cm(n, startChar);

    // Generate and print the character matrix
    cm.generateMatrix();
    cm.printMatrix();

    return 0;
}