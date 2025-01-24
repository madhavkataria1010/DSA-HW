#include <iostream>
#include <vector>
using namespace std;

class SquareMatrix {
private:
    int n;
    vector<vector<int>> matrix;

public:
    SquareMatrix(int size) : n(size) {
        matrix.resize(n, vector<int>(n));
    }

    void inputMatrix() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
    }


    int calculateDiagonalSum() const {
        if(n == 1) {
            return matrix[0][0];
        }
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += matrix[i][i] + matrix[i][n - 1 - i];
        }
        return sum;
    }
};

int main() {
    int n;
    cin >> n;

    SquareMatrix mat(n);
    mat.inputMatrix();
    cout << mat.calculateDiagonalSum();

    return 0;
}