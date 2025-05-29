class Base {
private:
  int a;

protected:
  int b;

public:
  int c;
};
class Derived : protected Base {
public:
};
class Derived_Derived : public Derived {
  void test() {
    a = 1;
    b = 2;
    c = 3;
  }
};
int main() {
  Derived_Derived dd;
  dd.c = 3;
  return 0;
}
