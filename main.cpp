#include <iostream>
using namespace std;
class MySet {
private:
  int *my_array;
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

// #include <algorithm>
// #include <numeric>
MySet::MySet() : my_array(nullptr), len(0) {}
MySet::MySet(int *arr, int n) {
  my_array = new int[n];
  for (int i = 0; i < n; i++)
    my_array[i] = arr[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (my_array[j] > my_array[j + 1]) {
        int _ = my_array[j];
        my_array[j] = my_array[j + 1];
        my_array[j + 1] = _;
      }
  //  sort(array, array + len);
  len = n;
}
MySet::MySet(const MySet &other) {
  my_array = new int[other.len];
  for (int i = 0; i < other.len; i++)
    my_array[i] = other.my_array[i];
  //  copy(other.array, other.array + other.len, array);
  len = other.len;
}
MySet::~MySet() {
  delete[] my_array;
}
MySet &MySet::operator=(const MySet &other) {
  delete[] my_array;
  my_array = new int[other.len];
  for (int i = 0; i < other.len; i++)
    my_array[i] = other.my_array[i];
  //  copy(other.array, other.array + other.len, array);
  len = other.len;
  return *this;
}
MySet MySet::operator+(const MySet &other) {
  MySet result;
  result.my_array = new int[len + other.len];
  int i = 0, j = 0, k = 0;
  while (i < len && j < other.len)
    if (my_array[i] < other.my_array[j])
      result.my_array[k++] = my_array[i++];
    else if (my_array[i] > other.my_array[j])
      result.my_array[k++] = other.my_array[j++];
    else
      result.my_array[k++] = my_array[i++], j++;
  while (i < len)
    result.my_array[k++] = my_array[i++];
  while (j < other.len)
    result.my_array[k++] = other.my_array[j++];
  result.len = k;
  // result.len = set_union(array, array + len, other.array, other.array + other.len, result.array) - result.array;
  return result;
}
MySet MySet::operator-(const MySet &other) {
  MySet result;
  result.my_array = new int[len];
  int i = 0, j = 0, k = 0;
  while (i < len && j < other.len)
    if (my_array[i] < other.my_array[j])
      result.my_array[k++] = my_array[i++];
    else if (my_array[i] > other.my_array[j])
      j++;
    else
      i++, j++;
  while (i < len)
    result.my_array[k++] = my_array[i++];
  result.len = k;
  // result.len = set_difference(array, array + len, other.array, other.array + other.len, result.array) - result.array;
  return result;
}
MySet MySet::operator*(const MySet &other) {
  MySet result;
  result.my_array = new int[len < other.len ? len : other.len];
  int i = 0, j = 0, k = 0;
  while (i < len && j < other.len)
    if (my_array[i] < other.my_array[j])
      i++;
    else if (my_array[i] > other.my_array[j])
      j++;
    else
      result.my_array[k++] = my_array[i++], j++;
  // result.len = set_intersection(array, array + len, other.array, other.array + other.len, result.array) - result.array;
  result.len = k;
  return result;
}
MySet MySet::operator++() {
  for (int i = 0; i < len; i++)
    my_array[i]++;
  return *this;
}
MySet MySet::operator++(int) {
  MySet temp = *this;
  for (int i = 0; i < len; i++)
    my_array[i]++;
  return temp;
}
int MySet::operator[](int i) {
  if (i < 0 || i >= len)
    exit(1);
  return my_array[i];
}
MySet::operator int() {
  int sum = 0;
  for (int i = 0; i < len; i++)
    sum += my_array[i];
  return sum;
}
MySet::operator double() {
  double sum = (int)*this;
  return sum / len;
  // return accumulate(array, array + len, 0.0) / len;
}
ostream &operator<<(ostream &os, const MySet &my_set) {
  os << "{";
  for (int i = 0; i < my_set.len; i++)
    os << (i ? " " : "") << my_set.my_array[i];
  os << "}";
  return os;
}
istream &operator>>(istream &is, MySet &my_set) {
  int n;
  is >> n;
  int *array = new int[n];
  for (int i = 0; i < n; i++)
    is >> array[i];
  my_set = MySet(array, n);
  return is;
}
