#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;
class MySet {
private:
  int *array;
  int len;

public:
  MySet();
  MySet(int *, int);
  MySet(const MySet &);
  ~MySet();
  MySet &operator=(const MySet &); // 拷贝赋值
  MySet operator+(const MySet &);  // 并集
  MySet operator-(const MySet &);  // 差集
  MySet operator*(const MySet &);  // 交集
  MySet operator++();              // 每个元素加1
  MySet operator++(int);           // 每个元素加1
  int operator[](int);             // 返回下标
  operator int();                  // 元素之和
  operator double();               // 元素平均值
  friend ostream &operator<<(ostream &, const MySet &);
  friend istream &operator>>(istream &, MySet &);
};

using namespace std;
int main() {
  // A: 5 1 2 3 4 5
  // B: 4 3 4 5 6
  // 5 1 2 3 4 5 4 3 4 5 6
  MySet A, B;
  cin >> A, cin >> B;
  // 并集
  MySet C = A + B, D = A - B, E = A * B;
  cout << "A + B : " << C << endl;
  // 差集
  cout << "A - B : " << D << endl;
  // 交集
  cout << "A * B : " << E << endl;
  // 前置++
  cout << "++A: " << ++A << endl;
  // 后置++
  cout << "B++: " << B++ << endl;
  cout << "B after B++: " << B << endl;
  // 下标访问
  cout << "C[0]: " << C[0] << endl;
  // 转int（元素和）
  cout << "(int)A : " << (int)A << endl;
  // 转double（平均值）
  cout << "(double)B : " << (double)B << endl;
  return 0;
}

MySet::MySet() : array(nullptr), len(0) {}
MySet::MySet(int *arr, int n) {
  array = new int[n];
  copy(arr, arr + n, array);
  sort(array, array + n);
  len = unique(array, array + n) - array;
}
MySet::MySet(const MySet &other) {
  array = new int[other.len];
  copy(other.array, other.array + other.len, array);
  len = other.len;
}
MySet::~MySet() {
  delete[] array;
}
MySet &MySet::operator=(const MySet &other) {
  delete[] array;
  array = new int[other.len];
  copy(other.array, other.array + other.len, array);
  len = other.len;
  return *this;
}
MySet MySet::operator+(const MySet &other) {
  MySet result;
  result.array = new int[len + other.len];
  result.len = set_union(array, array + len, other.array, other.array + other.len, result.array) - result.array;
  return result;
}
MySet MySet::operator-(const MySet &other) {
  MySet result;
  result.array = new int[len];
  result.len = set_difference(array, array + len, other.array, other.array + other.len, result.array) - result.array;
  return result;
}
MySet MySet::operator*(const MySet &other) {
  MySet result;
  result.array = new int[min(len, other.len)];
  result.len = set_intersection(array, array + len, other.array, other.array + other.len, result.array) - result.array;
  return result;
}
MySet MySet::operator++() {
  for (int i = 0; i < len; i++)
    array[i]++;
  return *this;
}
MySet MySet::operator++(int) {
  MySet temp = *this;
  for (int i = 0; i < len; i++)
    array[i]++;
  return temp;
}
int MySet::operator[](int i) {
  if (i < 0 || i >= len)
    exit(1);
  return array[i];
}
MySet::operator int() {
  int sum = 0;
  for (int i = 0; i < len; i++)
    sum += array[i];
  return sum;
}
MySet::operator double() {
  return accumulate(array, array + len, 0.0) / len;
}
ostream &operator<<(ostream &os, const MySet &my_set) {
  for (int i = 0; i < my_set.len; i++)
    os << (i ? " " : "") << my_set.array[i];
  return os;
}
istream &operator>>(istream &is, MySet &my_set) {
  int n;
  is >> n;
  delete[] my_set.array;
  my_set.array = new int[n];
  my_set.len = n;
  for (int i = 0; i < n; i++)
    is >> my_set.array[i];
  sort(my_set.array, my_set.array + n);
  my_set.len = unique(my_set.array, my_set.array + n) - my_set.array;
  return is;
}