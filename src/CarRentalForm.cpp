#include "CarRentalForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date
#include <FieldToInputSelect.h>

CarRentalForm::CarRentalForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager) {  // ✅ Calls base constructor
        m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset+=50, "Pickup Location:"));  
        m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Pickup Date:"));  
        m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Rent total days:"));  
        m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "GPS needed?"));  
        m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Child Seat needed:"));  
        m_inputFields.push_back(std::make_unique<FieldToInputSelect>(m_yOffset += 50, "Car Type:", std::vector<std::string>{"Economy", "Compact", "Sedan", "SUV", "Luxury"}, 0));
	
    fieldLabels.insert(fieldLabels.end(), {
        "Pickup Location:",
        "Pickup Date:", "Rent total days:",
        "GPS needed?", "Child Seat needed?",
        "Car Type:"
        });

    userInput.resize(fieldLabels.size(), "");  // ✅ Resize input fields
    setDefaultValues();
}

void CarRentalForm::setDefaultValues() {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);  

    userInput[5] = std::to_string(1900 + ltm.tm_year) + "-" +
        std::to_string(1 + ltm.tm_mon) + "-" +
        std::to_string(ltm.tm_mday);
	userInput[9] = "Economy";
}

std::string CarRentalForm::getFormType() const {
    return "Car Rental";
}

void CarRentalForm::render(sf::RenderWindow& window) {
    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");

    window.clear(sf::Color(235, 235, 235));

    // ✅ Title
    sf::Text title("Car Rental Form", font, 26);
    title.setFillColor(sf::Color(20, 20, 20));
    title.setStyle(sf::Text::Bold);
    title.setPosition(20, 10);
    window.draw(title);

    bool cursorVisible = (cursorTimer.getElapsedTime().asMilliseconds() % 1000 < 500);

    // ✅ Render input fields dynamically
	for (std::size_t i = 0; i < m_inputFields.size(); ++i) {
		m_inputFields[i]->drawToForm(window);
	}

    BookingForm::render(window);
}

