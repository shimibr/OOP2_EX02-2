#include "HotelBookingForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date
#include <FieldToInputSelect.h>

HotelBookingForm::HotelBookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager) 
{ 
	m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Hotel Name:"));
	m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Check-in Date:"));
	m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Check-out Date:"));
	m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Number of Guests:"));
	m_inputFields.push_back(std::make_unique<FieldToInputSelect>(m_yOffset += 50, "Room Type:", std::vector<std::string>{ "Single Room","Double Room","Family Room","Presidential Suite" },0,0));
    setbuttons();
}

std::string HotelBookingForm::getFormType() const {
    return "Hotel Booking";
}


