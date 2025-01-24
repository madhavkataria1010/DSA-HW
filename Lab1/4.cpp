#include <iostream>
using namespace std;

// use this matrix
int arr[101][101];

void col_wise_sum_of_transpose(int r,int c){
    for(int i=0; i<c; i++){
        int sum = 0;
        for(int j=0; j<r; j++){
            sum += arr[j][i];
        }
        cout << sum << " ";
    }
}

int main(){
    int r,c;
    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> arr[i][j];
        }
    }
    col_wise_sum_of_transpose(r,c);
    return 0;
}