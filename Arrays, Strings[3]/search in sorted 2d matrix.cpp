#include <bits/stdc++.h>
using namespace std;

/*
    Method 1 :-> First and foremost way is to just go through the matrix and then check with time complexity of O(n*2)
    Method 2 :-> The better approach is to go through the all the rows and check whether the target element falls in the row and check in the row
    Method 3 :-> The optimal approach is to use binary search considering it as a unidimensional array. Time complexity will be O(log(n*n))

    We are implementing Method 3 directly
*/

string search(vector<vector<int>>& matrix, int n, int target) {
    //apply binary search:
    int low = 0, high = n * n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / n, col = mid % n;
        if (matrix[row][col] == target) return "Found";
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return "Not Found";
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    cout << search(matrix, n, target) << endl;
}