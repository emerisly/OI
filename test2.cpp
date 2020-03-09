#include <utility>      // std::pair, std::get
#include <iostream>     // std::cout

int main () {
  std::pair <int,char> foo (10,'x');
  std::cout << "foo contains: ";
  std::cout << std::get<0>(foo) << " and " << std::get<1>(foo) << '\n';

  return 0;
}
