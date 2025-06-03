#include <iostream>
using namespace std;
class Person {
protected:
  int age;

public:
  Person(int a) {
    age = a;
  }
  void print() {
    cout << age << endl;
  }
};
class Student : public Person {
private:
  string major;

public:
  Student(int a, string major) : Person(a), major(major) {}
  Student(const Student &other) : Person(other), major(other.major) {}
  void print() {
    cout << major << " " << age << endl;
  }
};
int main() {
  Student s1(10, "a");
  Student s2(s1);
  Person *s3 = &s1;
  Person &s4 = s2;
  Person p(20);
  s1.print();
  s2.print();
  s3->print();
  return 0;
}
