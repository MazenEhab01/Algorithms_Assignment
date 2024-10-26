#include <iostream>
using namespace std;

int Sequential_Search_Iterative(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; 
}

int Sequential_Search_Recursive(int arr[], int size, int target, int index = 0) {
    if (index >= size) {
        return -1;
    }
    if (arr[index] == target) {
        return index;
    }
    return Sequential_Search_Recursive(arr, size, target, index + 1);
}

int Binary_Search_Iterative(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (arr[middle] == target) {
            return middle;
        }
        if (arr[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1; // Element not found
}

int Recursive_Binary_Search(int arr[], int left, int right, int target) {
    if (left == right) {
        if (arr[left] == target) {
            return left;
        } else {
            return -1;
        }
    }

    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        return mid;
    }
    if (arr[mid] > target) {
        return Recursive_Binary_Search(arr, left, mid - 1, target);
    }
    return Recursive_Binary_Search(arr, mid + 1, right, target);
}

void displayMenu() {
    cout << "------------------- SEARCH ALGORITHMS MENU -------------------" << endl;
    cout << "1] Sequential Search (Iterative)" << endl;
    cout << "2] Sequential Search (Recursive)" << endl;
    cout << "3] Binary Search (Iterative)" << endl;
    cout << "4] Binary Search (Recursive)" << endl;
    cout << "0] Exit" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

void printArray(int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// for binary search when a user enters an unsorted array 
bool isSorted(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int choice;
    bool continueProgram = true;

    while (continueProgram) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                // Sequential Search Iterative
                int n, target;
                cout << "Enter size of array: ";
                cin >> n;
                int arr[n];
                cout << "Enter elements of the array: ";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                cout << "Array entered: ";
                printArray(arr, n);

                cout << "Enter target element to search: ";
                cin >> target;

                int result = Sequential_Search_Iterative(arr, n, target);
                if (result != -1) {
                    cout << "Element found at index " << result << " using Sequential Search (Iterative)." << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            }
            case 2: {
                // Sequential Search Recursive
                int n, target;
                cout << "Enter size of array: ";
                cin >> n;
                int arr[n];
                cout << "Enter elements of the array: ";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                cout << "Array entered: ";
                printArray(arr, n);

                cout << "Enter target element to search: ";
                cin >> target;

                int result = Sequential_Search_Recursive(arr, n, target);
                if (result != -1) {
                    cout << "Element found at index " << result << " using Sequential Search (Recursive)." << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            }
            case 3: {
                // Binary Search Iterative
                int n, target;
                cout << "Enter size of array: ";
                cin >> n;
                int arr[n];
                cout << "Enter sorted elements of the array: ";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                cout << "Array entered: ";
                printArray(arr, n);

                if (!isSorted(arr, n)) {
                    cout << "Error: The array is not sorted. Binary Search requires a sorted array." << endl;
                    break;
                }

                cout << "Enter target element to search: ";
                cin >> target;

                int result = Binary_Search_Iterative(arr, n, target);
                if (result != -1) {
                    cout << "Element found at index " << result << " using Binary Search (Iterative)." << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            }
            case 4: {
                // Binary Search Recursive
                int n, target;
                cout << "Enter size of array: ";
                cin >> n;
                int arr[n];
                cout << "Enter sorted elements of the array: ";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                cout << "Array entered: ";
                printArray(arr, n);

                if (!isSorted(arr, n)) {
                    cout << "Error: The array is not sorted. Binary Search requires a sorted array." << endl;
                    break;
                }

                cout << "Enter target element to search: ";
                cin >> target;

                int result = Recursive_Binary_Search(arr, 0, n - 1, target);
                if (result != -1) {
                    cout << "Element found at index " << result << " using Binary Search (Recursive)." << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            }
            case 0:
                cout << "Exiting the program." << endl;
                continueProgram = false;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
