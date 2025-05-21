#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
class Student
{
private:
  int age;
  bool sex;
  int grad;
public:
  void eat(string str="orange")
  {
    cout<<"I am eating "<<str<<"."<< endl;
  }
  void eat(int r=1)
  {
    if(r==1)cout<<"I am eating."<<endl;
    else cout<<"I am not eating."<<endl;
  }
  void lesson()
  {
    cout<<"I am in a lesson."<< endl;
  }
};
int main()
{
  Student a;
  a.eat("apple");
  a.eat();
  a.lesson();
}

