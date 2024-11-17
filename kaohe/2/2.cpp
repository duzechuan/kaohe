#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

using namespace std;

// 函数用于计算矩阵的行列式
double determinant(const vector<vector<double>>& matrix, int n) {
    double det = 0;

    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    for (int c = 0; c < n; c++) {
        vector<vector<double>> subMatrix(n - 1, vector<double>(n - 1));
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j < c) {
                    subMatrix[i - 1][j] = matrix[i][j];
                } else if (j > c) {
                    subMatrix[i - 1][j - 1] = matrix[i][j];
                }
            }
        }
        det += (c % 2 == 0 ? 1 : -1) * matrix[0][c] * determinant(subMatrix, n - 1);
    }
    return det;
}

// 函数用于计算矩阵的伴随矩阵
vector<vector<double>> adjoint(const vector<vector<double>>& matrix, int n) {
    vector<vector<double>> adj(n, vector<double>(n));
    if (n == 1) {
        adj[0][0] = 1;
        return adj;// 单位矩阵
    }

    int sign = 1;
    vector<vector<double>> subMatrix(n - 1, vector<double>(n - 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int subi = 0; 
            for (int x = 0; x < n; x++) {
                if (x == i) continue; 
                subi++;// 计算矩阵的第i行第j列的子矩阵的行数
                int subj = 0; 
                for (int y = 0; y < n; y++) {
                    if (y == j) continue; 
                    subMatrix[subi - 1][subj++] = matrix[x][y];// 计算矩阵的第i行第j列的子矩阵
                }
            }
            adj[j][i] = sign * determinant(subMatrix, n - 1); // 计算矩阵的第i行第j列的伴随矩阵元素
            sign = -sign;
        }
    }
    return adj;
}

// 函数用于计算逆矩阵
bool inverse(const vector<vector<double>>& matrix, vector<vector<double>>& inverseMatrix, int n) {
    double det = determinant(matrix, n);// 计算矩阵行列式
    if (det == 0) {
        return false; // 矩阵不可逆
    }

    vector<vector<double>> adj = adjoint(matrix, n);// 计算矩阵伴随矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverseMatrix[i][j] = adj[i][j] / det; // 计算逆矩阵元素
        }
    }
    return true; // 矩阵可逆
}

int main() {
    int n;
    cin >> n;
    vector<vector<double>> matrix(n, vector<double>(n));// 定义矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];// 输入矩阵元素
        }
    }

    vector<vector<double>> inverseMatrix(n, vector<double>(n));// 定义逆矩阵
    if (inverse(matrix, inverseMatrix, n)) {
        cout << "矩阵的逆矩阵为：\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << fixed << setprecision(2) << inverseMatrix[i][j] << " ";// 输出逆矩阵元素,保留两位小数
            }
            cout << endl;
        }
    } else {
        cout << "矩阵不可逆" << endl;
    }

    return 0;
}
