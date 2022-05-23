#include "farmacycontroller.h"

#include <fstream>

FarmacyController::FarmacyController(){}

FarmacyController::~FarmacyController()
{
    for(int i = 0;i<meds.size();i++)
        delete meds[i];
}

bool FarmacyController::addMedicine(std::string name, float price)
{
    for(int i = 0;i<meds.size();i++)
        if(meds[i]->get_name() == name)
             return false;
    Medicine* m = new Medicine(name,price);
    meds.push_back(m);
    return true;
}

bool FarmacyController::removeMedicine(std::string name)
{
    for(auto it = meds.begin();it!=meds.end();it++)
        if((*it)->get_name() == name){
            delete *it;
            meds.erase(it);
            return true;
        }
    return false;
}

Medicine *FarmacyController::get_at(int index)
{
    if(index>=0&&index<meds.size())
           return meds[index];
    return nullptr;
}

void FarmacyController::saveCSV(std::string filename)
{
    std::ofstream out(filename);
    for(int i = 0;i<meds.size();i++)
        out<<meds[i]->get_name()<<','<<meds[i]->get_price()<<std::endl;
}

