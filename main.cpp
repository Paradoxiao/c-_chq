#include <iostream>
using namespace std;
class Base1 {
protected:
  int mem;

public:
  Base1(int m) : mem(m) {
    cout << "Base1 is created." << endl;
  }
  ~Base1() {
    cout << "Base1 is erased." << endl;
  }
  void print() {
    cout << "Base1 " << mem << endl;
  }
};
class Base2 {
protected:
  int mem;

public:
  Base2(int m) : mem(m) {
    cout << "Base2 is created." << endl;
  }
  ~Base2() {
    cout << "Base2 is erased." << endl;
  }

  void print() {
    cout << "Base2 " << mem << endl;
  }
};
class Derived : public Base1, public Base2 {
private:
  int mem;

public:
  Derived(int m1, int m2, int m3) : Base1(m1), Base2(m2), mem(m3) {
    cout << "Derived is created." << endl;
  }
  void print() {
    // cout << Base1::mem << " " << Base2::mem << " " << mem << endl;
    Base1::print();
    Base2::print();
    cout << "Derived " << mem << endl;
  }
  ~Derived() {
    cout << "Derived is erased." << endl;
  }
};
int main() {
  Derived obj(1, 2, 3);
  obj.print();
  obj.Base1::print();
  return 0;
}
