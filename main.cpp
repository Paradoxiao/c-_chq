#include <iostream>
using namespace std;
class Array {
private:
  int arr[1000];
  int len;

public:
  Array(int l, int a[]) {
    len = l;
    int i;
    for (i = 0; i < len; i++)
      arr[i] = a[i];
    // for (; i < 1000; i++)
    //   arr[i] = 0;
  }
  Array() {}
  void print() {
    for (int i = 0; i < len; i++)
      cout << arr[i] << " ";
    cout << endl;
  }
  bool operator>(const Array &other) {
    int i;
    for (i = 0; i < len && i < other.len; i++) {
      if (arr[i] > other.arr[i])
        return 1;
      if (arr[i] < other.arr[i])
        return 0;
    }
    if (i < len)
      return 1;
    // if (i < other.len)
    //   return 0;
    return 0;
  }
  Array operator+(const Array &other) {
    int i = 0, j = 0, k = 0;
    Array sum;
    // sum.len = other.len > len ? other.len : len;
    while (i < len && j < other.len)
      sum.arr[k++] = arr[i++] + other.arr[j++];
    // if (i == len)
    while (j < other.len)
      sum.arr[k++] = other.arr[j++];
    // else
    while (i < len)
      sum.arr[k++] = arr[i++];
    sum.len = k;
    return sum;
  }
  Array operator=(const Array &other) {
    len = other.len;
    for (int i = 0; i < len; i++)
      arr[i] = other.arr[i];
    return *this;
  };
  void my_sort(Array arrs[], int n) {
    Array temp;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - i - 1; j++) {
        temp = arrs[i];
        if (arrs[j] > arrs[j + 1]) {
          arrs[i] = arrs[j + 1];
          arrs[j + 1] = temp;
        }
      }
    }
  }
};
int main() {
  Array arrs[10];
  int a[1000];
  int i;
  for (i = 0; i < 10; i++) {
    a[i] = i + 1;
  }
  Array array1(10, a);
  for (i = 0; i < 10; i++) {
    a[i] = i * 10 + 1;
  }
  Array array2(10, a);
  array1.print();
  array2.print();
  // Array array3 = array1 + array2;
  // array3.print();
  if (array1 > array2)
    cout << "Larger" << endl;
  else
    cout << "Lower" << endl;
  return 0;
}
