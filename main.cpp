#include <iostream>
#include <ostream>
#include <typeinfo>
using namespace std;
class Person {
private:
  int age;

public:
  Person(int age = 20) : age(age) {
    cout << "Person" << endl;
  }
  Person(const Person &other) : age(other.age) {
    cout << "Copy Person" << endl;
  }
  friend ostream &operator<<(ostream &os, Person p) {
    os << p.age;
    return os;
  }
};
template <typename T> class Data {
private:
  T mem;

public:
  Data(T mem) : mem(mem) {
    if (typeid(T) == typeid(int)) {
      cout << "Int Constructor" << endl;
      return;
    }
    if (typeid(T) == typeid(double)) {
      cout << "Double Constructor" << endl;
      return;
    }
    if (typeid(T) == typeid(Person)) {
      cout << "Person Constructor" << endl;
      return;
    }
  }
  friend ostream &operator<<(ostream &os, Data<T> data) {
    os << data.mem << "<<";
    return os;
  }
  void print() {
    cout << mem << endl;
  }
};
int main() {
  // Data<int> data1(10);
  // Data<double> data2(20);
  // data1.print();
  // data2.print();
  Person p;
  Data<Person> data3(p);
  cout << data3;
  return 0;
}
