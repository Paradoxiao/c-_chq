bool is_inset(int *a, int size, int n) {
  int l = 0, r = size - 1;
  while (l <= r) {
    int m = l + ((r - l) >> 1);
    if (a[m] > n)
      r = m - 1;
    else if (a[m] < n)
      l = m + 1;
    else
      return true;
  }
  return false;
}
int main() {
  return 0;
}
