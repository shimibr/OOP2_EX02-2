#pragma once
#include "Input.h"  

class InputInt : public Input<int>  
{  
public:  
   InputInt(int& yOffset, std::string nameBox);
   std::string inputToString() override;
 
private:  

};
