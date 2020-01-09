#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class ReturRef{
    char *str ;
    public:
    ReturRef(){
        str = '\0';
    }
    ~ReturRef(){
        if(str) free(str);
    }
    void show (){
        cout<< str<<endl;
    }
    void set(char *input);
};
ReturRef input(){
    char s[80];
    ReturRef retRefObj;
    cin >> s;
    retRefObj.set(s);
    return s;
}
void ReturRef::set(char * input){ // Зарежда низ
    str = (char*) malloc(strlen(input) +1);
    if(!str){ exit(1); /* Allocation error*/ }
    strcpy(str,input);
}


int main() {
  int a = 0;
  add_one(a); // Not clear that a may be modified
  cout<< a << endl;
  int b = 0;
  add_one(&b); // 'a' is clearly being passed destructively
  cout<< a << endl;
}
