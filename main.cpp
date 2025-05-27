#include <iostream>
using namespace std;
class CPU {
private:
  double f;

public:
  CPU(double f) : f(f) {
    cout << "CPU is created.\n";
  }

  ~CPU() {
    cout << "CPU is destroyed.\n";
  }
};
class Disk {
private:
  double capacity;

public:
  Disk(double size) : capacity(size) {
    cout << "Disk is created.\n";
  }
  ~Disk() {
    cout << "Disk is destroyed.\n";
  }
};
class Memory {
private:
  double capacity;

public:
  Memory(double size) : capacity(size) {
    cout << "Memory is created.\n";
  }
  ~Memory() {
    cout << "Memory is destroyed.\n";
  }
};
class Computer {
private:
  CPU cpu;
  Disk disk;
  Memory ram;

public:
  Computer(double f, double disk, double ram) : cpu(f), disk(disk), ram(ram) {
    cout << "computer is created.\n";
  }
  ~Computer() {
    cout << "computer is destroyed.\n";
  }
};
int main() {
  Computer my_computer(1, 1, 1);
  return 0;
}
