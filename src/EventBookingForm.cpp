#pragma once

#include "EventBookingForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  
#include <FieldToInputSelect.h>
#include "YesOrNo.h"
#include "GustOneSelect.h"
#include "Name.h"
#include "Address.h"
#include "Data.h"
#include "Between.h"
#include <Wheelchair.h>
#include <SeatingPreference.h>

EventBookingForm::EventBookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager)
{
    m_inputFields.push_back(std::make_unique<Name>(m_yOffset += 50, "Event Name:"));
    m_inputFields.push_back(std::make_unique<Address>(m_yOffset += 50, "Venue:"));
    m_inputFields.push_back(std::make_unique<Data>(m_yOffset += 50, "Event Date:"));
    m_inputFields.push_back(std::make_unique<Between>(m_yOffset += 50, "Number of Tickets:", 1, 15));
    m_inputFields.push_back(std::make_unique<Wheelchair>(m_yOffset += 50));
    m_inputFields.push_back(std::make_unique<SeatingPreference>(m_yOffset += 50));
    setbuttons();
}

std::string EventBookingForm::getFormType() const {
    return "Event Booking";
}

bool EventBookingForm::checkCrossField()
{
    SeatingPreference* seatingPreference = dynamic_cast<SeatingPreference*>(m_inputFields[9].get());
    return (m_inputFields[8]->crossFieldTest(*seatingPreference));
}

