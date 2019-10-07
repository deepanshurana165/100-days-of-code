// https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements/0

#include <iostream>

using namespace std;

void input_arr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}

void output_arr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void rotateArray(int arr[], int n, int k) {
  k = k % n;

  if (k == 0) {
    return;
  } else if (n < 2 * k) {
    for (int j = 0; j < n - k; j++) {
      for (int i = n - 1; i > 0; i--) {
        swap(arr[i], arr[i - 1]);
      }
    }
    return;
  }

  for (int i = 0; i < k; i++) {
    swap(arr[i], arr[n - k + i]);
  }

  rotateArray(arr, n - k, k);
}

int main(int argc, char const *argv[]) {
  int t_cases;
  cin >> t_cases;

  for (int i = 0; i < t_cases; i++) {
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    input_arr(arr, n);
    rotateArray(arr, n, k);
    output_arr(arr, n);
  }

  return 0;
}
