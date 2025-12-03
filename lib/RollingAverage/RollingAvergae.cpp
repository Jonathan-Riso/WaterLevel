#include <vector>
#include <RollingAverage.hpp>


RollingAverage::RollingAverage(int size): max_size(size), sum(0.0), index(0), current_count(0) {
    buffer.resize(size, 0.0);
} 
    
void RollingAverage::addValue(double value){
    sum -= buffer[index];
    sum += value;
    buffer[index] = value;

    index = (index+1) % max_size;

    if (current_count<max_size) current_count++;
} 

double RollingAverage::getAverage() const {
    if (current_count<max_size) return 0;
    return sum/current_count;
}
