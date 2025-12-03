#include <vector>
#include <RollingAverage.h>

class RollingAverage{
    private:
        int max_size;
        int current_count;
        int index;
        double sum = 0.0;

        std::vector<double> buffer; 
    public:
        RollingAverage(int size) : max_size(size), sum(0.0), index(0), current_count(0) {
            buffer.resize(size, 0.0);
        } 
            
        void addValue(double value){
            sum -= buffer[index];
            sum += value;
            buffer[index] = value;

            index = (index+1) % max_size;

            if (current_count<max_size) current_count++;
        } 

        double getAverage() const {
            if (current_count<max_size) return 0;
            return sum/current_count;
        }
}