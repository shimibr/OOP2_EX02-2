#pragma once  

#include "YesOrNo.h"  
#include "SeatingPreference.h"  

class Wheelchair : public YesOrNo  
{  
public:  
Wheelchair(int& yOffset);  
bool crossFieldTest(const SeatingPreference& seatingPreference) const;  

private:  

};