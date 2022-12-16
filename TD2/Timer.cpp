#include <chrono>
#include <memory>
#include <ctime>
#include <algorithm>


class Timer{
public :

    std::chrono::time_point<std::chrono::system_clock> debut;
    std::chrono::time_point<std::chrono::system_clock> fin;

    void start () {fin = std::chrono::system_clock::now();}
    void stop () {fin = std::chrono::system_clock::now();}
    void print () { std::cout << "Timer = " << fin - debut << std::endl;}
};