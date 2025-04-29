#include "EventBookingForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date
#include <FieldToInputSelect.h>
#include "YesOrNo.h"
#include "GustOneSelect.h"
#include "Name.h"
#include "Address.h"
#include "Data.h"
#include "Between.h"

EventBookingForm::EventBookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager)
{
    m_inputFields.push_back(std::make_unique<Name>(m_yOffset += 50, "Event Name:"));
    m_inputFields.push_back(std::make_unique<Address>(m_yOffset += 50, "Venue:"));
    m_inputFields.push_back(std::make_unique<Data>(m_yOffset += 50, "Event Date:"));
    m_inputFields.push_back(std::make_unique<Between>(m_yOffset += 50, "Number of Tickets:"));
    m_inputFields.push_back(std::make_unique<YesOrNo>(m_yOffset += 50, "Wheelchair Accessibility?"));
    m_inputFields.push_back(std::make_unique<GustOneSelect>(m_yOffset += 50, "Seating Preference:", std::vector<std::string>{ "General Admission", "Front Row", "VIP Section", "Aisle Seat" }, 0, 0));
    setbuttons();
}

std::string EventBookingForm::getFormType() const {
    return "Event Booking";
}

