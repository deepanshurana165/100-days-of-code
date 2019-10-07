#include <cmath>
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

void rotate_array(int arr[], int start, int end) {
  for (int i = start; i < ceil((start + end) / 2.0); i++) {
    swap(arr[i], arr[end - i + start]);
  }
}

void k_rotate_array(int arr[], int n, int k) {
  k = k % n;
  rotate_array(arr, 0, k - 1);
  rotate_array(arr, k, n - 1);
  rotate_array(arr, 0, n - 1);
}

int main(int argc, char const *argv[]) {
  int t_cases;
  cin >> t_cases;

  for (int i = 0; i < t_cases; i++) {
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    input_arr(arr, n);
    k_rotate_array(arr, n, k);
    output_arr(arr, n);
  }

  return 0;
}
