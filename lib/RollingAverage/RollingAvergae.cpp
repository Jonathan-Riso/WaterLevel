#include <RollingAverage.hpp>


RollingAverage::RollingAverage(): max_size(50), current_count(0), index(0), sum(0.0) {
    for(int i = 0; i<max_size; i++) buffer[i] = 0;
} 
    
void RollingAverage::addValue(int value){
    sum -= buffer[index];
    sum += value;
    buffer[index] = value;

    index = (index+1) % max_size;

    if (current_count<max_size) current_count++;
} 

float RollingAverage::getAverage() const {
    if (current_count==0) return 0;
    return sum/current_count;
}
