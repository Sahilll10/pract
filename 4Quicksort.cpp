#include <iostream>
using namespace std;
int comp = 0, swaps = 0;
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comp++;
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
            swaps++;
        }
    }
    swap(a[i + 1], a[high]);
    swaps++;
    return i + 1;
}
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}
void display(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}
int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    int marks[100];
    cout << "Enter marks:\n";
    for (int i = 0; i < n; i++) cin >> marks[i];

    quickSort(marks, 0, n - 1);
    cout << "\nSorted marks: ";
    display(marks, n);
    cout << "Comparisons: " << comp << endl;
    cout << "Swaps: " << swaps << endl;

    cout << "\nBest Case Example: (Already balanced partition)\n";
    int best[] = {40, 50, 60, 70, 80};
    comp = swaps = 0;
    quickSort(best, 0, 4);
    display(best, 5);
    cout << "Comparisons: " << comp << "  Swaps: " << swaps << endl;

    cout << "\nWorst Case Example: (Already sorted)\n";
    int worst[] = {10, 20, 30, 40, 50};
    comp = swaps = 0;
    quickSort(worst, 0, 4);
    display(worst, 5);
    cout << "Comparisons: " << comp << "  Swaps: " << swaps << endl;
}

void part(vector<int>&arr, int low, int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            comp++;
            i++;
            swap(arr[i],arr[j])
            swap++;
        }
    }
    swap(arr[i+1],pivot);
    swap++;
    return i+1;
}


