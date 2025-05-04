#include "CarRentalForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date
#include <FieldToInputSelect.h>
#include "Address.h"
#include "Between.h"
#include "Data.h"
#include "YesOrNo.h"
#include "GustOneSelect.h"
#include <Gps.h>
#include <CarType.h>

CarRentalForm::CarRentalForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager) {
        m_inputFields.push_back(std::make_unique<Address>(m_yOffset+=50, "Pickup Location:"));  
        m_inputFields.push_back(std::make_unique<Data>(m_yOffset += 50, "Pickup Date:"));
        m_inputFields.push_back(std::make_unique<Between>(m_yOffset += 50, "Rent total days:", 1, 999));
        m_inputFields.push_back(std::make_unique<Gps>(m_yOffset += 50));
        m_inputFields.push_back(std::make_unique<YesOrNo>(m_yOffset += 50, "Child Seat needed:"));
        m_inputFields.push_back(std::make_unique<CarType>(m_yOffset += 50));
        setbuttons();
}
//=========================================
std::string CarRentalForm::getFormType() const {
    return "Car Rental";
}
//=========================================
bool CarRentalForm::checkCrossField()
{
	CarType* carType = dynamic_cast<CarType*>(m_inputFields[9].get());
    if(!m_inputFields[7]->crossFieldTest(*carType))
    {
		return false;
    }

	return true;
}


