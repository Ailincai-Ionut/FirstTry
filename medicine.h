#ifndef MEDICINE_H
#define MEDICINE_H

#include <string>

class Medicine
{
public:
    Medicine(std::string name,float price);
    inline std::string get_name() {return name;};
    inline float get_price(){return price;};

    inline void set_name(std::string new_name){name = new_name;};
    inline void set_price(float new_price){price = new_price;};

private:
    std::string name;
    float price;
};

#endif // MEDICINE_H
