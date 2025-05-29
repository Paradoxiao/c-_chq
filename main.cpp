#include <iostream>
#include <string>
using namespace std;
class Base {
public:
  Base() {
    cout << "Base is created.\n";
  }
  ~Base() {
    cout << "Base is erased.\n";
  }
};
class Date : public Base {
public:
  Date() {
    cout << "Date is created.\n";
  }
  ~Date() {
    cout << "Date is erased.\n";
  }
};
class Person {
protected:
  string name;
  int age;
  Date birthday;

public:
  Person(string n = "", int a = 0) : name(n), age(a) {
    cout << "Person is created.\n";
  }
  ~Person() {
    cout << "Person is erased.\n";
  }
  void print() {
    cout << name << " " << age << " ";
  }
};
class Student : public Person {
private:
  string major;
  Date time;

public:
  Student(string n = "", int a = 0, string m = "") : Person(n, a), major(m) {
    cout << "Student is created.\n";
  }
  void print() {
    cout << name << " " << age << " " << major << endl;
  }
  ~Student() {
    cout << "Student is erased.\n";
  }
};
int main() {
  Student Yunru("云茹", 18, "science");
  Yunru.print();
  // // Student student;
  // student.print();
  return 0;
}
