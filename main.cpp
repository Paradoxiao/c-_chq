#include <iostream>
using namespace std;
class A {
protected:
  int m;

public:
  A(int x) : m(x) {
    cout << "A" << endl;
  }
  ~A() {
    cout << "~A" << endl;
  }
};
class B : virtual public A {
public:
  B(int x) : A(x) {
    cout << "B" << endl;
  }
  ~B() {
    cout << "~B" << endl;
  }
};
class C : virtual public A {
public:
  C(int x) : A(x) {
    cout << "C" << endl;
  }
  ~C() {
    cout << "~C" << endl;
  }
};
class D : public B, public C {
public:
  void print() {
    cout << B::m << endl;
  }
  D(int x) : A(x), B(x), C(x) {
    cout << "D" << endl;
  }
  ~D() {
    cout << "~D" << endl;
  }
};
int main() {
  D d(10);
  d.print();
  return 0;
}
