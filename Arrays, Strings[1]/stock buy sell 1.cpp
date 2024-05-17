#include <bits/stdc++.h>
using namespace std;

int stock_buy_sell(vector<int>& arr) {
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    
    return maxPro;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++) 
        cin >> arr[i];

    cout << "Maxiumum Profit is : " << stock_buy_sell(arr) << endl;   
}