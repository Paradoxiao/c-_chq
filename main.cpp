#include <iostream>
using namespace std;
int k = 0;
void permute(int *a, int n, int l, int r) {
  if (l == r - 1) {
    cout << ++k << ":";
    for (int i = 0; i < n; i++)
      cout << a[i] << " ";
    cout << endl;
    return;
  }
  for (int i = l; i < r; i++) {
    swap(a[l], a[i]);
    permute(a, n, l + 1, r);
    swap(a[l], a[i]);
  }
}
int main() {
  int a[] = {1, 2, 3, 4, 5};
  permute(a, 5, 0, 5);
  return 0;
}
