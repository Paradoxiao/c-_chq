#include <iostream>
using namespace std;
class Person {
private:
  int age;
  bool sex;

public:
  Person() {}
  void set(int age, bool sex) {
    this->age = age;
    this->sex = sex;
  }
  int divide() {
    if (age <= 20 && sex)
      return 1;
    if (age <= 20 && !sex)
      return -1;
    return 0;
  }
};
int main() {
  int n;
  cin >> n;
  int m = 0, w = 0;
  int age;
  bool sex;
  Person persons[n];
  for (int i = 0; i < n; i++) {
    cin >> age >> sex;
    persons[i].set(age, sex);
  }
  for (int i = 0; i < n; i++) {
    if (persons[i].divide() == 1)
      m++;
    if (persons[i].divide() == -1)
      w++;
  }
  cout << m << " " << w << endl;
  return 0;
}
