#include <iostream>
using namespace std;
class Date {
private:
  int year, month, day;

public:
  Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {
    cout << "Date is created.\n";
  }
  ~Date() {
    cout << "Date is erased.\n";
  }
  int getYear() const {
    return year;
  }
  int getMonth() const {
    return month;
  }
  int getDay() const {
    return day;
  }
};
class Person {
private:
  Date birthday;

public:
  Person(int year, int month, int day) : birthday(year, month, day) {
    cout << "Person is created.\n";
  }
  Person() {}
  // Person(int year, int month, int day) {
  //   cout << "Person is created.\n";
  //   birthday = Date(year, month, day);
  // }
  ~Person() {
    cout << "Person is erased.\n";
  }
  void print() {
    cout << birthday.getYear() << "-" << birthday.getMonth() << "-" << birthday.getDay() << endl;
  }
};
int main() {
  // Person person(1, 1, 1);
  // int a(1);
  // double b(2.0);
  // char c('3');
  // cout << a << b << c << endl;
  // person.print();
  Person d;
  return 0;
}
