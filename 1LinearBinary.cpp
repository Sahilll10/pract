#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == key) return i;
    return -1;
}

int binarySearch(vector<int>& arr, int key) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> ids = {101, 203, 305, 402, 512, 634};
    int key;
    cout << "Enter Customer Account ID to search: ";
    cin >> key;
    int lin = linearSearch(ids, key);
    if (lin != -1) cout << "Found using Linear Search at position " << lin + 1 << endl;
    else cout << "Not found using Linear Search" << endl;
    sort(ids.begin(), ids.end());
    int bin = binarySearch(ids, key);
    if (bin != -1) cout << "Found using Binary Search at position " << bin + 1 << endl;
    else cout << "Not found using Binary Search" << endl;
}
