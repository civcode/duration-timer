
#include <iostream>
#include <thread>
#include <vector>

#include "duration_timer.h"

using std::cout;
using std::endl;

int main() {

    DurationTimer loop_timer(std::chrono::seconds(2));
    DurationTimer interval_timer(std::chrono::milliseconds(100));

    auto t1 = std::chrono::high_resolution_clock::now();
    std::vector<double> data;    

    /* Change timer duration / interval */
    //interval_timer.set_interval(std::chrono::milliseconds(20));
    //interval_timer.set_interval(std::chrono::microseconds(2000));
    //interval_timer.set_interval(std::chrono::seconds(1));

    while (!loop_timer.is_expired()) {
        if (interval_timer.is_expired()) {
            auto now = std::chrono::high_resolution_clock::now();
            auto interval_duration = now-t1;
            t1 = now;
            int dt_ms = std::chrono::duration_cast<std::chrono::milliseconds>(interval_duration).count();
            cout << "dt = " << dt_ms << " ms" << endl;
            // int dt_us = std::chrono::duration_cast<std::chrono::microseconds>(interval_duration).count();
            // cout << "dt = " << dt_us << " us" << endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    cout << "loop_timer has expired" << endl;
    
    //cout << "restarting loo_timer" << endl;
    //loop_timer.restart();
    
    
    
    return 0;
}