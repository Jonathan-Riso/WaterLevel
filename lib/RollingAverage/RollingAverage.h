#include <vector>

class RollingAverage{
    private:
        int max_size;
        int current_count;
        int index;
        double sum;
        std::vector<double> buffer; 
    public:
        RollingAverage(int size);
        void addValue(double value);
        double getAverage() const;
}