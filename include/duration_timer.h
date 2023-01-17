#ifndef DURATION_TIMER_H
#define DURATION_TIMER_H

#include <chrono>

class DurationTimer {

public:
    DurationTimer(const std::chrono::microseconds interval);
    DurationTimer(const std::chrono::milliseconds interval);
    DurationTimer(const std::chrono::seconds interval);

    bool is_expired();
    void restart();
    void set_interval(const std::chrono::microseconds interval);
    void set_interval(const std::chrono::milliseconds interval);
    void set_interval(const std::chrono::seconds interval);

private:
    std::chrono::microseconds interval_;
    std::chrono::high_resolution_clock::time_point target_;

};


#endif // DURATION_TIMER_H
