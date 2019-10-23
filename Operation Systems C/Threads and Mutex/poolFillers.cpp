#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

int maxPoolCapacity = 5000;
int currentPoolCapacity = 0;
mutex mutexPool;

void threadFunction(int updateVolume, int sleepMillisSec){
    bool sleepFlag = false;
    while (true){
        mutexPool.lock();
        if((currentPoolCapacity + updateVolume > maxPoolCapacity) || (currentPoolCapacity + updateVolume < 0)){
            sleepFlag = true;
        }else{
            currentPoolCapacity += updateVolume;
            std::cout << "added "<< updateVolume << " totalVolume:"<< currentPoolCapacity << std::endl;
            
        }
        mutexPool.unlock();

        if(sleepFlag){
            std::cout << "> Upper than 5k or less than 0, sleep 10 seconds" << std::endl;
            this_thread::sleep_for(chrono::seconds(10));
            sleepFlag= false;
        }else{
            this_thread::sleep_for(chrono::milliseconds(sleepMillisSec));
        }
    }
    
}

int main(int argc, char const *argv[])
{
    int timeRinning = 0;
    thread *t1, *t2, *t3;
    t1 = new thread(threadFunction,10 ,30);
    t2 = new thread(threadFunction,-50 ,70);
    t1 = new thread(threadFunction,-300 ,1000);

    while (true) {
        mutexPool.lock();
        printf("%d -> Pool Capacity %d\n",timeRinning,currentPoolCapacity);
        mutexPool.unlock();
        timeRinning ++;
        this_thread::sleep_for(chrono::seconds(1));
        t1->join();
        t2->join();
        t3->join();
    }

    return 0;
}
