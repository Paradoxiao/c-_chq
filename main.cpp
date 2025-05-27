// const
// 常数数据成员
// 常成员函数
// 常对象
// static
// 类成员
#include <iostream>
using namespace std;
class Person {
private:
  int age;
  const bool sex;
  static int cnt;

public:
  Person(int a, bool s) : sex(s) {
    age = a;
    cnt++;
  }
  void print() const {
    // age = 20;
    cout << age << " " << sex << endl;
  }
  static void setAge(int a) {
    age = a;
  }
  static int getCnt() {
    return cnt;
  }
  // void setSex(bool s) {    sex = s;  }
};
int Person::cnt = 0;
int main() {
  const Person person(18, false);
  person.setAge(10);
  cout << Person::getCnt() << " " << person.getCnt() << endl;
  person.print();
  // Person.setAge(20);
  person.print();
  return 0;
}
