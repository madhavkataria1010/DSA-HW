/*You need to replace each element of the given array by the sum of the element to its right if the element is rightmost, you need to replace that element by zero.  You have to return the replaced array.[ANKIT]
Input:  Array = [[1, 2, 3, 4],
                [1, 2, 3, 4],
                [1, 2, 3, 4],
                [1, 2, 3, 4]])

Output: Array after interchange =   [[9, 7, 4, 0],
       						[9, 7, 4, 0],
       						[9, 7, 4, 0],
       						[9, 7, 4, 0]])*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> replaceElements(const std::vector<std::vector<int>>& array) {
    std::vector<std::vector<int>> replaced = array;
    for(auto &row : replaced) {
        int sum = 0;
        for(int i = row.size()-1; i >=0; --i){
            int temp = row[i];
            row[i] = sum;
            sum += temp;
        }
    }
    return replaced;
}

int main(){
    int rows, cols;
    std::cin >> rows;
    std::cin >> cols;

    std::vector<std::vector<int>> array(rows, std::vector<int>(cols));

    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            std::cin >> array[i][j];
        }
    }

    std::vector<std::vector<int>> replaced = replaceElements(array);

    for(const auto &row : replaced){
        for(auto elem : row){
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
