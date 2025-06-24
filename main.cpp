#include <iostream>
using namespace std;
class Shape {
private:
public:
  virtual void draw() {
    cout << "Draw a shape." << endl;
  }
};
class Circle : public Shape {
public:
  void draw() {
    cout << "Draw a circle." << endl;
  }
};
class Square : public Shape {
public:
  void draw() {
    cout << "Draw a square." << endl;
  }
};
class Line : public Shape {
public:
  void draw() {
    cout << "Draw a line." << endl;
  }
};
void drawShape(Shape &s) {
  s.draw();
}
void drawShape(Shape *s) {
  s->draw();
}
int main() {
  Circle c;
  Square s;
  Line l;
  // drawShape(c);
  // drawShape(s);
  // drawShape(&c);
  // drawShape(&s);
  // Shape &shape1[3];
  // shape1[0] = c;
  // shape1[1] = s;
  // for (int i = 0; i < 2; i++)
  //   shape1[i].draw();
  Shape **shape2;
  shape2 = new Shape *[3];
  shape2[0] = &c, shape2[1] = &s, shape2[2] = &l;
  // shape2[0] = new Circle, shape2[1] = new Shape, shape2[2] = new Line;
  for (int i = 0; i < 2; i++)
    shape2[i]->draw();
  Shape *shape3[3];
  shape3[0] = &c, shape3[1] = &s, shape3[2] = &l;
  // shape3[0] = new Circle, shape3[1] = new Shape, shape3[2] = new Line;
  for (int i = 0; i < 2; i++)
    shape3[i]->draw();
  return 0;
}
