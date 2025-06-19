#include <cstring>
#include <iostream>
using namespace std;
template <typename T> class Data {
protected:
  T mem;

public:
  Data(T mem = 0) : mem(mem) {}
  Data<T> &operator=(const Data<T> &other) {
    mem = other.mem;
    return *this;
  }
  bool operator>(const Data<T> &other) {
    return mem > other.mem;
  }
  friend ostream &operator<<(ostream &os, const Data<T> &other) {
    os << other.mem;
    return os;
  }
};
// NOTE: 模板类特化
template <> class Data<char *> {
private:
  char *mem;

public:
  Data(char *s) : mem(new char[strlen(s) + 1]) {
    strcpy(mem, s);
  }
  ~Data() {
    delete[] mem;
  }
  Data<char *> &operator=(const Data<char *> &other) {
    delete[] mem;
    mem = new char[strlen(other.mem) + 1];
    strcpy(mem, other.mem);
    return *this;
  }
  Data<char *> operator+(const Data<char *> &other) {
    char *newMem = new char[strlen(mem) + strlen(other.mem) + 1];
    strcpy(newMem, mem);
    strcat(newMem, other.mem);
    Data<char *> result(newMem);
    delete[] newMem;
    return result;
  }
  bool operator>(const Data<char *> &other) {
    return strcmp(mem, other.mem) > 0;
  }
  friend ostream &operator<<(ostream &os, const Data<char *> &other) {
    os << other.mem;
    return os;
  }
};
// NOTE: 模板类组合
class Student {
private:
  Data<char *> name;
  Data<int> age;
  Data<double> score;

public:
  Student(char *n, int a, double s) : name(n), age(a), score(s) {}
  void print() const {
    cout << age << " " << score;
  }
};
// NOTE: 模板类继承
class Data2 : public Data<int> {
public:
  Data2(int data) : Data<int>(data) {}
  void add() {
    mem++;
  }
};
int main() {
  return 0;
}
