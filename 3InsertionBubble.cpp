#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<float>& arr) {
    int n = arr.size(), comp = 0, swaps = 0;
    cout << "\nInsertion Sort:\n";
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comp++;
            arr[j + 1] = arr[j];
            j--;
            swaps++;
        }
        if (j >= 0) {
          comp++;
        }
        arr[j + 1] = key;
        cout << "Pass " << i << ": ";
        for (float x : arr) cout << x << " ";
         cout << endl;
    }
    cout << "Comparisons: " << comp << endl;
    cout << "Swaps: " << swaps << endl;
}

void bubbleSort(vector<float>& arr) {
    int n = arr.size(), comp = 0, swaps = 0;
    cout << "\nBubble Sort:\n";
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
        cout << "Pass " << i + 1 << ": ";
        for (float x : arr) cout << x << " ";
        cout << endl;
    }
    cout << "Comparisons: " << comp << endl;
    cout << "Swaps: " << swaps << endl;
}

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;
    vector<float> salaries(n);
    cout << "Enter employee salaries:\n";
    for (int i = 0; i < n; i++) cin >> salaries[i];
    vector<float> arr1 = salaries, arr2 = salaries;
    insertionSort(arr1);
    bubbleSort(arr2);
}
