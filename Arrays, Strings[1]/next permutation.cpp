#include <bits/stdc++.h>
using namespace std;

void helper(vector<int>& arr, set<vector<int>>& s, int ind) {
    if(ind == arr.size() - 1) {
        s.insert(arr);
        return;
    }
    for(int i=ind;i<arr.size();i++) {
        vector<int> temp(arr);
        swap(temp[i], temp[ind]);
        helper(temp, s, ind + 1);
    }
}

// Variation 1
void nextPermutation1(vector<int>& arr) {
    set<vector<int>> s;
    helper(arr, s, 0);
    for(auto it : s) {
        for(int i=0;i<it.size();i++) {
            cout << it[i] << " ";
        }
        cout << endl;
    }
}

// Variation 2
void nextPermutation2(vector<int>& arr) {
    next_permutation(arr.begin(), arr.end());
    for(int i=0;i<arr.size();i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Variation 3
void nextPermutation3(vector<int>& arr) {
    int ind = -1;
    for(int i=arr.size() - 2;i >= 0; i--) {
        if(arr[i] < arr[i+1]) {
            ind = i;
            break;
        }
    }

    if(ind == -1) {
        reverse(arr.begin(), arr.end());
        for(int i=0;i<arr.size();i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else {
        int newind = -1;
        for(int i=ind;i<arr.size();i++) {
            if(arr[i] > arr[ind]) {
                swap(arr[i], arr[ind]);
                break;
            }
        }

        reverse(arr.begin() + ind, arr.begin() + arr.size() - 1);
        for(int i=0;i<arr.size();i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    // Variation 1
    cout << "NEXT 1" << endl;
    nextPermutation1(arr);

    // Variation 2
    cout << "NEXT 2" << endl;
    nextPermutation2(arr);

    // Variation 3
    cout << "NEXT 3" << endl;
    nextPermutation3(arr);

    return 0;
}