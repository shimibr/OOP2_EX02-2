#include "CarRentalForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date
#include <FieldToInputSelect.h>

CarRentalForm::CarRentalForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager) {
        m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset+=50, "Pickup Location:"));  
        m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Pickup Date:"));  
        m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Rent total days:"));  
        m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "GPS needed?"));  
        m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Child Seat needed:"));  
        m_inputFields.push_back(std::make_unique<FieldToInputSelect>(m_yOffset += 50, "Car Type:", std::vector<std::string>{"Economy", "Compact", "Sedan", "SUV", "Luxury"}, 0));
        setbuttons();
}

std::string CarRentalForm::getFormType() const {
    return "Car Rental";
}


