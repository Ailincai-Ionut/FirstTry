#ifndef FARMACYCONTROLLER_H
#define FARMACYCONTROLLER_H

#include <vector>
#include <fstream>

#include "medicine.h"

class FarmacyController
{
public:
    FarmacyController();
    ~FarmacyController();

    bool addMedicine(std::string name,float price);
    bool removeMedicine(std::string name);

    inline int nr_meds(){return meds.size();};

    Medicine* get_at(int index);

    void saveCSV(std::string filename);

private:
    std::vector<Medicine*> meds;
};

#endif // FARMACYCONTROLLER_H
