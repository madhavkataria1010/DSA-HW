/*Write a program that converts a given string into a 2-D array (matrix) format. The width (number of columns) of the 2-D array should be equal to the length of the longest word in the input string. For words shorter than the longest word, fill the remaining columns in the row with spaces ' '.

Input: A single line of text consisting of words separated by spaces.
Output: Print the 2-D array where each row represents a word from the input string, and each row has a width equal to the length of the longest word. If a word is shorter than the longest word, the remaining spaces in that row should be filled with spaces ' '.
Example:
Input: Weny Wight wears white pants
Output: 
['W' 'e' 'n' 'y' ' ' ]
['W' 'i' 'g' 'h' 't' ]
['w' 'e' 'a' 'r' 's' ]
['w' 'h' 'i' 't' 'e' ]
['p' 'a' 'n' 't' 's' ]*/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


vector<vector<char>> convertTo2DArray(const string& str) {
    // Your code here
    vector<vector<char>> result;
    istringstream iss(str);
    string word;
    int max_len = 0;
    while(iss >> word) max_len = max(max_len, (int)word.size());
    iss.clear();
    iss.seekg(0, ios::beg);
    while(iss >> word){
        vector<char> row;
        for(auto &c : word) row.push_back(c);
        while((int)row.size() < max_len) row.push_back(' ');
        result.push_back(row);
    }
    return result;

    
}

int main() {
    string input;
    getline(cin, input);

    // Convert the input string to a 2D matrix
    vector<vector<char>> result = convertTo2DArray(input);

    // Print the matrix
    for (const auto& row : result) {
        cout << "[";
        for (size_t j = 0; j < row.size(); ++j) {
            cout << "'" << row[j] << "' ";
        }
        cout << "]" << endl;
    }

    return 0;
}