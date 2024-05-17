#include <bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>>& matrix, int i, int n) {
    for(int j=0;j<n;j++) {
        if(matrix[i][j] == 0) {
            matrix[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>>& matrix, int j, int n) {
    for(int i=0;i<n;i++) {
        if(matrix[i][j] == 0) {
            matrix[i][j] = -1;
        }
    }
}

// Time Complexity : O(n^3)
// Space Complexity : O(2*n)
void Method1(vector<vector<int>>& matrix, int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(matrix[i][j] == 0) {
                markRow(matrix, i, n);
                markCol(matrix, j, n);
            }
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
}

// Time Complexity : O(n^2)
// Space Complexity : O(2*n)
vector<vector<int>> Method2(vector<vector<int>> &matrix, int n, int m) {

    int row[n] = {0}; // row array
    int col[m] = {0}; // col array

    // Traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark ith index of row wih 1:
                row[i] = 1;

                // mark jth index of col wih 1:
                col[j] = 1;
            }
        }
    }

    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

// Time Complexity : O(n^2)
// Space Complexity : O(1)
vector<vector<int>> Method3(vector<vector<int>> &matrix, int n, int m) {

    // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]

    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    //step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> matrix[i][j];
        }
    }

    Method1(matrix, n);

    cout << "Final Matrix :" << endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}