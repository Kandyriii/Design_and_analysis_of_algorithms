#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int>& A, int start, int end) {
    while (start < end) {
        swap(A[start], A[end]);
        start++;
        end--;
    }
}

vector<int> circular_shift(vector<int>& A, int k) {
    int n = A.size();
    k = k % n;  // Handle shifts greater than the length of the array

    // Step 1: Reverse the entire array
    reverse(A, 0, n - 1);

    // Step 2: Reverse the first k elements
    reverse(A, 0, k - 1);

    // Step 3: Reverse the remaining elements
    reverse(A, k, n - 1);

    return A;
}

int main() {
    vector<int> original_array = {5, 15, 29, 35, 42};
    int k = 2;
    vector<int> shifted_array = circular_shift(original_array, k);

    cout << "Original array: ";
    for (int num : original_array) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Shifted array: ";
    for (int num : shifted_array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

