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

CarRentalForm::CarRentalForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager) {
        m_inputFields.push_back(std::make_unique<Address>(m_yOffset+=50, "Pickup Location:"));  
        m_inputFields.push_back(std::make_unique<Data>(m_yOffset += 50, "Pickup Date:"));
        m_inputFields.push_back(std::make_unique<Between>(m_yOffset += 50, "Rent total days:"));
        m_inputFields.push_back(std::make_unique<YesOrNo>(m_yOffset += 50, "GPS needed?"));
        m_inputFields.push_back(std::make_unique<YesOrNo>(m_yOffset += 50, "Child Seat needed:"));
        m_inputFields.push_back(std::make_unique<GustOneSelect>(m_yOffset += 50, "Car Type:", std::vector<std::string>{"Economy", "Compact", "Sedan", "SUV", "Luxury"}, 0, 0));
        setbuttons();
}

std::string CarRentalForm::getFormType() const {
    return "Car Rental";
}


