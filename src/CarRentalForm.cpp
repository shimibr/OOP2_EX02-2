#include "CarRentalForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date

CarRentalForm::CarRentalForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager) {  // ✅ Calls base constructor
	m_inputFields.insert(m_inputFields.end(), {
		FieldToInput(sf::Vector2f(250, 260), "Pickup Location:"),
		FieldToInput(sf::Vector2f(250, 310), "Pickup Date:"),
		FieldToInput(sf::Vector2f(250, 360), "Rent total days:"),
		FieldToInput(sf::Vector2f(250, 410), "GPS needed?"),
		FieldToInput(sf::Vector2f(250, 460), "Child Seat needed:"), 
        FieldToInput(sf::Vector2f(250, 510), "Car Type:")});
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
		m_inputFields[i].drawToForm(window);
	}
    int yOffset = 260;
    for (std::size_t i = 20; i < fieldLabels.size(); ++i) {
        sf::Text label(fieldLabels[i], font, 18);
        label.setFillColor(sf::Color(60, 60, 60));
        label.setPosition(20, yOffset);
        window.draw(label);

        sf::RectangleShape inputBox(sf::Vector2f(250, 35));
        inputBox.setPosition(250, yOffset - 5);
        inputBox.setFillColor(sf::Color::White);
        inputBox.setOutlineThickness(2);
        inputBox.setOutlineColor(i == activeField ? sf::Color(0, 120, 255) : sf::Color(160, 160, 160));
        window.draw(inputBox);

        std::string displayText = userInput[i];
        if (i == activeField && cursorVisible) {
            displayText += "|";
        }

        sf::Text inputText(displayText, font, 16);
        inputText.setFillColor(sf::Color::Black);
        inputText.setPosition(255, yOffset);
        window.draw(inputText);

        yOffset += 50;
    }
    yOffset -= 10;
    float carTypeButtonX = 20;
    for (int i = 0; i < carTypeSelection.size(); ++i) {
        sf::RectangleShape roomButton(sf::Vector2f(90, 30));
        roomButton.setPosition(carTypeButtonX, yOffset);
        roomButton.setFillColor(selectedCarType == i ? sf::Color(0, 120, 255) : sf::Color::White);  // ✅ Highlight selected
        roomButton.setOutlineThickness(2);
        roomButton.setOutlineColor(sf::Color(160, 160, 160));
        window.draw(roomButton);

        sf::Text roomText(carTypeSelection[i], font, 16);
        roomText.setFillColor(selectedCarType == i ? sf::Color::White : sf::Color::Black);
        roomText.setPosition(carTypeButtonX+10, yOffset + 5);
        window.draw(roomText);

        carTypeButtonX += 105;  // ✅ Increased spacing
    }
    // ✅ "Done" and "Cancel" Buttons (positioned dynamically)
    m_yOffset = yOffset + 40;

    BookingForm::render(window);
}

void CarRentalForm::handleInput(sf::Event event) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == '\b' && !userInput[activeField].empty()) {
            if(activeField < 20)
				m_inputFields[activeField].setInputBack();

            userInput[activeField].pop_back();
        }
        else if (event.text.unicode >= 32 && event.text.unicode < 128) {
			if (activeField < 20)
				m_inputFields[activeField].setInput(static_cast<char>(event.text.unicode));

            userInput[activeField] += static_cast<char>(event.text.unicode);
        }
    }
    else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Tab) {
            activeField = (activeField + 1) % userInput.size();
        }
        if (event.key.code == sf::Keyboard::Return) {
            std::cout << "Entered Data: ";
            for (const auto& field : userInput) std::cout << field << " ";
            std::cout << std::endl;
        }
    }
    else if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
        int yOffset = 60;

		for (std::size_t i = 0; i < m_inputFields.size(); ++i) {
			if (m_inputFields[i].isInputBox(mousePos)) {
				activeField = i;
			}
		}

        for (std::size_t i = 0; i < fieldLabels.size(); ++i) {
            sf::FloatRect inputBoxBounds(240, yOffset - 5, 250, 35);
            if (inputBoxBounds.contains(mousePos)) {
                activeField = i;
                return;
            }
            yOffset += 50;
        }
        yOffset -= 10;
        // ✅ Handle Car Type Button Click          
        float carTypeButtonX = 20;
        for (int i = 0; i < carTypeSelection.size(); ++i) {
            sf::FloatRect timeButtonBounds(carTypeButtonX, yOffset, 90, 30);
            if (timeButtonBounds.contains(mousePos)) {
                selectedCarType = i;
                //Update the "Car Type" input box
                userInput[9] = carTypeSelection[i];

                return;
            }
            carTypeButtonX += 105;  // Move to next button
        }
         yOffset += 40;

        if (mousePos.x >= 20 && mousePos.x <= 160 && mousePos.y >= yOffset && mousePos.y <= yOffset + 40) {
            std::cout << "Car Rental Confirmed!\n";
            openConfirmationWindow();
            return;
        }

        if (mousePos.x >= 200 && mousePos.x <= 340 && mousePos.y >= yOffset && mousePos.y <= yOffset + 40) {
            std::cout << "Cancelled Car Rental\n";
            formManager->closeForm();
            return;
        }
    }
}


