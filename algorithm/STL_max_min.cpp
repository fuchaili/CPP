#include <iostream>     
#include <algorithm>    
using namespace std;

int main () {
  cout << "min(1,2)==" <<min(1,2) << '\n';
  cout << "max(2,1)==" <<max(2,1) << '\n';
  cout << "min('a','z')==" <<min('a','z') << '\n';
  cout << "max('a','z')==" <<max('a','z') << '\n';
  cout << "min(3.14,2.72)==" <<min(3.14,2.72) << '\n';
  cout << "max(3.14,2.73)==" <<max(3.14,2.73) << '\n';
  return 0;
}