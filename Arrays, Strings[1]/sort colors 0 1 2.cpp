#include <bits/stdc++.h>
using namespace std;

/*
    We can have 3 approaches where --->
    1 --> Normal sorting which take n*log(n) time
    2 --> Store occurences of all colors and then replace in the array with time complexity of O(2*N
    3 --> Is implemented here
*/

void sort(vector<int>& arr, int n) {
    int low = 0;
    int high = n - 1;
    int mid = 0;

    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low += 1;
            mid += 1;
        }
        else if(arr[mid] == 1) {
            mid += 1;
        }
        else {
            swap(arr[mid], arr[high]);
            high -= 1;
        }
    }

    cout << "Sorted Array" << endl;
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++)    
        cin >> arr[i];
    
    sort(arr, n);
}