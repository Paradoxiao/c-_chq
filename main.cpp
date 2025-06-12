#include <iostream>
using namespace std;
bool cmp_1(int a, int b) {
  return a > b;
}
bool cmp_2(int a, int b) {
  return a <= b;
}
class Solve {
private:
  int *arr, n;

public:
  void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> arr[i];
  }
  void sort() {
    int _;
    for (int i = 0; i < n / 2; i++) {
      for (int j = 0; j + 2 < n; j += 2)
        if (cmp_2(arr[j], arr[j + 2])) {
          _ = arr[j];
          arr[j] = arr[j + 2];
          arr[j + 2] = _;
        }
      for (int j = 1; j + 2 < n; j += 2)
        if (cmp_1(arr[j], arr[j + 2])) {
          _ = arr[j];
          arr[j] = arr[j + 2];
          arr[j + 2] = _;
        }
    }
  }
  void output() {
    cout << *arr;
    for (int i = 1; i < n; i++)
      cout << " " << arr[i];
  }
};
int main() {
  Solve solve;
  solve.input();
  solve.sort();
  solve.output();
  return 0;
}
