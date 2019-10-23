#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;

void print_block(int n, char c){
    //mtx.lock();
    cout << "Thread 1" << c << endl;
    for (int i = 0; i < n; i++){
        cout << c<< " " << endl;
    }
    cout << "\n" << endl;
    //mtx.unlock();
}

int main(int argc, const char** argv) {
    thread first(print_block,50 ,'*');
    thread second(print_block,50,'$');
    cout << "main" << endl;   
    first.join();
    second.join();
    cout << "end" << endl;
    return 0;
}