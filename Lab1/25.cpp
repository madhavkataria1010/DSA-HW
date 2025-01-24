#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Matrix {
    private:

    public:
    int n, m;
    vector<vector<int>> M;
    
    Matrix(int rowsize, int colsize) {
        n = rowsize;
        m = colsize;
        M = vector<vector<int>>(n, vector<int>(m, 0));
    }

    void print_averages(int row, int col) {
        double rowSum = 0;
        for (int j = 0; j < m; j++) {
            rowSum += M[row][j];
        }
        double rowAverage = rowSum / m;
        
        double colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += M[i][col];
        }
        double colAverage = colSum / n;
        
        cout << fixed << setprecision(2) << rowAverage << " " << colAverage;
    }
};

int main(){
    int n, m;
    
    cin >> n >> m;
    
    Matrix mat(n, m);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat.M[i][j];
        }
    }
    
    int row, col;
    cin >> row >> col;
    
    mat.print_averages(row, col);
    
    return 0;
}