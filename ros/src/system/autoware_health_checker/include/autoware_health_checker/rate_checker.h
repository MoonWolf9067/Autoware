#ifndef RATE_CHECKER_H_INCLUDED
#define RATE_CHECKER_H_INCLUDED

//headers in ROS
#include <ros/ros.h>

//headers in STL
#include <vector>
#include <mutex>

//headers in Boost
#include <boost/optional.hpp>

class RateChecker
{
    public:
        RateChecker(double buffer_length);
        ~RateChecker();
        void check();
        boost::optional<double> getRate();
    private:
        ros::Time start_time_;
        void update();
        std::vector<ros::Time> data_;
        const double buffer_length_;
        std::mutex mtx_;
};
#endif //RATE_CHECKER_H_INCLUDED