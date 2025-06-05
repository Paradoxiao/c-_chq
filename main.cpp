#include <cstring>
#include <iomanip>
#include <iostream>
#include <ostream>
using namespace std;
class Time {
private:
  int hour, minute, second;
  char *name;

public:
  Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
  // void print() {
  //   cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << endl;
  // }
  operator int() {
    return hour * 3600 + minute * 60 + second;
  }
  void operator=(const Time &other) {
    hour = other.hour;
    minute = other.minute;
    second = other.second;
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
  }
  Time operator++() {
    *this += 1;
    return *this;
  }
  Time operator++(int) {
    Time temp = *this;
    *this += 1;
    return temp;
  }
  Time operator+=(int seconds) {
    *this = *this + seconds;
    return *this;
  }
  Time operator+(int seconds) {
    int totalSeconds = hour * 3600 + minute * 60 + second + seconds;
    while (totalSeconds < 0)
      totalSeconds += 3600 * 24;
    totalSeconds %= 3600 * 24;
    return Time(totalSeconds / 3600, (totalSeconds % 3600) / 60, totalSeconds % 60);
  }
  int operator-(const Time &other) {
    int thisTotalSeconds = hour * 3600 + minute * 60 + second;
    int otherTotalSeconds = other.hour * 3600 + other.minute * 60 + other.second;
    return (thisTotalSeconds - otherTotalSeconds + 3600 * 24) % (3600 * 24);
  }
  // NOTE: 友元函数不是成员函数
  friend istream &operator>>(istream &is, Time &other);
  friend ostream &operator<<(ostream &os, const Time &other);
  // {
  //   os << setw(2) << setfill('0') << other.hour << ":" << setw(2) << setfill('0') << other.minute << ":" << setw(2) << setfill('0') << other.second << endl;
  //   return os;
  // }
};
ostream &operator<<(ostream &os, const Time &t) {
  os << setw(2) << setfill('0') << t.hour << ":" << setw(2) << setfill('0') << t.minute << ":" << setw(2) << setfill('0') << t.second << endl;
  return os;
}
istream &operator>>(istream &is, Time &t) {
  char _;
  is >> t.hour >> _ >> t.minute >> _ >> t.second;
  return is;
}
int main() {
  Time one(10, 1, 1), two(9, 9, 9), time(0, 0, 0);
  void *p = &one;
  cin >> one >> two >> time;
  // cout << (one + -300000);
  // cout << one - two << endl;
  cout << one << two << time;
  cout << (int)one << endl;
  cout << *(unsigned long long *)p << endl;
  return 0;
}
