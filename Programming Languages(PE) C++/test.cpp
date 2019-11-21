#include <iostream>
using namespace std;
void add_one(int& n) { n += 1; }
void add_one(int * const n) { *n += 1; }
//void add_one(int const* const n) { *n += 1; }

int main() {
  int a = 0;
  add_one(a); // Not clear that a may be modified
  cout<< a << endl;
  int b = 0;
  add_one(&b); // 'a' is clearly being passed destructively
  cout<< a << endl;
}

