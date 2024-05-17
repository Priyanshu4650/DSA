#include <bits/stdc++.h>
using namespace std;

/*

Variation 1 : Given r and c calculate corresponding value in the triangle
Variation 2 : Given r calculate the corresponding row
Variation 3 : Given r calculate all the corresponding rows above it

*/

long long nCr(int n, int r) {
    long long res = 1;

    for(int i=0;i<r;i++) {
        res += res * (n - i);
        res /= (i + 1);
    }

    return res;
}

// Variation 2
void pascalTriangle2(int n) {
    long long ans = 1;
    cout << ans << " ";

    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

// Variation 3
vector<vector<int>> pascalTriangle3(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}

int main() {
    // V1
    int r, c;
    cout << "Enter r and c for variation 1 :";
    cin >> r >> c;

    cout << "Value in corresponding row and column is : " << nCr(r-1, c-1) << endl;

    // V2
    int n;
    cin >> n;
    pascalTriangle2(n);

    // V3
    cin >> n;
    vector<vector<int>> res = pascalTriangle3(n);
    
    cout << "Pascal's Triangle" << endl;
    for(int i=0;i<res.size();i++) {
        for(int j=0;res[i].size();j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}