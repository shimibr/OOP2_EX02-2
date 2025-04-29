#include "EventBookingForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date
#include <FieldToInputSelect.h>

EventBookingForm::EventBookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager)
{
    m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Event Name:"));
    m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Venue:"));
    m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Event Date:"));
    m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Number of Tickets:"));
    m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Wheelchair Accessibility?"));
    m_inputFields.push_back(std::make_unique<FieldToInputSelect>(m_yOffset += 50, "Seating Preference:", std::vector<std::string>{ "General Admission", "Front Row", "VIP Section", "Aisle Seat" }, 0, 0));
    setbuttons();
}

std::string EventBookingForm::getFormType() const {
    return "Event Booking";
}

