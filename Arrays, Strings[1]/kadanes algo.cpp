#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int>& arr) {
    int currMax = 0;
    int sumMax = 0;

    for(auto ele : arr) {
        sumMax += ele;
        currMax = max(currMax, sumMax);

        if(sumMax < 0) 
            sumMax = 0;   
    }

    return currMax;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    cout << "Maximum subarray sum :" << kadane(arr) << endl;
}