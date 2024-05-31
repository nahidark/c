#include <iostream>
#include <vector>
using namespace std;

// Sequential Search
int sequentialSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;  // Return the index where the target is found
        }
    }
    return -1;  // Return -1 if target is not found
}

// Binary Search
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;  // Return the index where the target is found
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;  // Return -1 if target is not found
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int minIndex = i;
        
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        swap(arr[i], arr[minIndex]);
    }
}

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int choice;
    vector<int> data;

    cout << "Enter the number of elements: ";
    int n;
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        data.push_back(num);
    }

    cout << "Select an algorithm:\n";
    cout << "1. Sequential Search\n";
    cout << "2. Binary Search\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Selection Sort\n";
    cout << "5. Bubble Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            // Sequential Search
            cout << "Enter the target element: ";
            int target;
            cin >> target;
            int result = sequentialSearch(data, target);
            if (result == -1) {
                cout << "Target element not found.\n";
            } else {
                cout << "Target element found at index: " << result << "\n";
            }
            break;
        
        case 2:
            // Binary Search
            cout << "Enter the target element: ";
            cin >> target;
            result = binarySearch(data, target);
            if (result == -1) {
                cout << "Target element not found.\n";
            } else {
                cout << "Target element found at index: " << result << "\n";
            }
            break;
        
        case 3:
            // Insertion Sort
            insertionSort(data);
            cout << "Array after sorting:\n";
            for (int num : data) {
                cout << num << " ";
            }
            cout << endl;
            break;
        
        case 4:
            // Selection Sort
            selectionSort(data);
            cout << "Array after sorting:\n";
            for (int num : data) {
                cout << num << " ";
            }n
            cout << endl;
            break;
        
        case 5:
            // Bubble Sort
            bubbleSort(data);
            cout << "Array after sorting:\n";
            for (int num : data) {
                cout << num << " ";
            }
            cout << endl;
            break;
        
        default:
            cout << "Invalid choice.\n";
            break;
    }

    return 0;
}