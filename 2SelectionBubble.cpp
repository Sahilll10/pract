#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<float>& arr) {
    int n = arr.size(), comp = 0, swaps = 0;
    cout << "\nSelection Sort:\n";
    for (int i = 0; i <n-1 ; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            comp++;
            if (arr[j] < arr[minIndex]) {
               minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swaps++;
        }
        cout << "Pass " << i + 1 << ": ";
        for (float x : arr) cout << x << " ";
        cout << endl;
    }
    cout << "Comparisons: " << comp << endl;
    cout << "Swaps: " << swaps << endl;
}

void bubbleSort(vector<float>& arr) {
    int n = arr.size(), comp = 0, swaps = 0;
    cout << "\nBubble Sort:\n";
    for (int i = 0; i < n - 1; i++){
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
    selectionSort(arr1);
    bubbleSort(arr2);
}

