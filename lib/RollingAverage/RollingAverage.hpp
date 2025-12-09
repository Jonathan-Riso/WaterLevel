#ifndef RollingAverage_H
#define RollingAverage_H

class RollingAverage{
    private:
        int max_size;
        int current_count;
        int index;
        int sum;
        int buffer[50]; 
    public:
        RollingAverage();
        void addValue(int value);
        float getAverage() const;
};

#endif