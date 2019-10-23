#include <unistd.h>
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

void foo(){
    cout << "Thread 1" << endl;
}
void bar(int x){
    sleep(3);
    cout << "Thread 2: " <<  x << endl;
}

int main(int argc, const char** argv) {
    thread first(foo);
    thread second(bar,31);
    cout << "main" << endl;   
    first.join();
    second.join();
    cout << "end" << endl;
    return 0;
}