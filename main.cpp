#include <cstring>
#include <iostream>
using namespace std;
class Person {
private:
  char *name;

public:
  Person() {}
  Person(char *n) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
  }
  Person(const Person &other) {
    name = new char[strlen(other.name + 1)];
    strcpy(name, other.name);
  }
  void setName(char *n) {
    delete[] name;
    name = new char[strlen(n) + 1];
    strcpy(name, n);
  }
  char *getName() {
    return name;
  }
  ~Person() {
    delete name;
  }
};
class PersonList {
private:
  Person *persons;
  int n;

public:
  PersonList(int n) {
    persons = new Person[n];
    this->n = n;
  }
  void getName() {
    char name[100];
    for (int i = 0; i < n; i++) {
      cin >> name;
      persons[i].setName(name);
    }
  }
  int count() {
    int count = 0;
    for (int i = 0; i < n; i++) {
      char *temp = persons[i].getName();
      for (int j = 0; j < strlen(temp); j++)
        if (temp[j] == 'a' || temp[j] == 'A') {
          count++;
          break;
        }
    }
    return count;
  }
  ~PersonList() {
    delete[] persons;
  }
};
int main() {
  int n;
  cin >> n;
  PersonList persons(n);
  persons.getName();
  cout << persons.count();
  return 0;
}
