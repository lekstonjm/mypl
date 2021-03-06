#include "reference.hpp"
#include <iostream>

struct Object {
  void method() { std::cout << "object" << std::endl; }
  virtual void virtMethod() { std::cout << "object" << std::endl;}
};
struct Derive : virtual Object {
  void method() { std::cout << "derive" << std::endl; }
  virtual void virtMethod() {std::cout << "derive" << std::endl;}
};

int main(int argc, char *argv[]) {
  Ref<Object> obj;
  Ref<Derive> derive(new Derive());
  obj.assign<Derive>(derive);
  derive.as<Object>()->method();
  obj.as<Derive>()->method();
  Ref<Derive> derive2;
  derive2.assign<Object>(obj);
  Ref<Derive> derive3;
  derive3 = obj.cast<Derive>();
  std::cout<<"ok"<<std::endl;
}
