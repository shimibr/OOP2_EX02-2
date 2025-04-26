#include "TrainBookingForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date
#include <RectanglText.h>

TrainBookingForm::TrainBookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager) {  // ✅ Calls base constructor
    fieldLabels.insert(fieldLabels.end(), {
        "Departure Station:", "Arrival Station:", "Departure Date:",
        "Number of Passengers:","Preferred Time:", "Special Requests:", 
        });

    userInput.resize(fieldLabels.size(), "");  // ✅ Resize input fields
    setDefaultValues();
}

void TrainBookingForm::setDefaultValues() {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);  // ✅ Safe alternative to localtime()

    userInput[6] = std::to_string(1900 + ltm.tm_year) + "-" +
        std::to_string(1 + ltm.tm_mon) + "-" +
        std::to_string(ltm.tm_mday);
	userInput[8] = "Don't Care";
    userInput[9] = "None";
}

std::string TrainBookingForm::getFormType() const {
    return "Train Booking";
}

void TrainBookingForm::render(sf::RenderWindow& window) {
    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");

    window.clear(sf::Color(235, 235, 235));

    // ✅ Title
    sf::Text title("Train Booking Form", font, 26);
    title.setFillColor(sf::Color(20, 20, 20));
    title.setStyle(sf::Text::Bold);
    title.setPosition(20, 10);
    window.draw(title);

    bool cursorVisible = (cursorTimer.getElapsedTime().asMilliseconds() % 1000 < 500);

    // ✅ Render input fields dynamically
    int yOffset = 60;
    for (std::size_t i = 0; i < fieldLabels.size(); ++i) {

        std::string displayText = userInput[i];
        if (i == activeField && cursorVisible) {
            displayText += "|";
        }

        RectangleToFill field(fieldLabels[i], 16, sf::Vector2f(350, 35), sf::Vector2f(240, yOffset - 5)
            , sf::Color::White, sf::Color(60, 60, 60), displayText);
        field.setOutline(i == activeField ? sf::Color(0, 120, 255) : sf::Color(160, 160, 160));

        field.drawRec(window);


        if (i == 8)
        {
            yOffset += 40;
            // ✅ Time Selection Buttons
            float timeButtonX = 10;
            for (std::size_t i = 0; i < timeSelection.size(); ++i) {

                RectanglText sButton(16, sf::Vector2f(100, 30), sf::Vector2f(timeButtonX, yOffset)
                    , timeSelection[i].second ? sf::Color(0, 120, 255) : sf::Color::White,
                    timeSelection[i].second ? sf::Color::White : sf::Color::Black, timeSelection[i].first);

                sButton.setOutline(sf::Color(160, 160, 160));
                sButton.drawRec(window);

               
                timeButtonX += 110;  // ✅ Increased spacing between buttons
            }
        } 
        if (i == 9)
        {
            yOffset += 40;
			// ✅ Special Selection Buttons
            float specialX = 10;
            for (std::size_t i = 0; i < specialSelection.size(); ++i) {

                RectanglText sButton(16, sf::Vector2f(150, 30), sf::Vector2f(specialX, yOffset)
                    , specialSelection[i].second ? sf::Color(0, 120, 255) : sf::Color::White,
                    specialSelection[i].second ? sf::Color::White : sf::Color::Black, specialSelection[i].first);

				sButton.setOutline(sf::Color(160, 160, 160));
                sButton.drawRec(window);

                specialX+= 160;  // ✅ Increased spacing between buttons
            }
        }
       
      yOffset += 50;
    }
   

    m_yOffset = yOffset;

    BookingForm::render(window);
}

void TrainBookingForm::handleInput(sf::Event event) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == '\b' && !userInput[activeField].empty()) {
            userInput[activeField].pop_back();
        }
        else if (event.text.unicode >= 32 && event.text.unicode < 128) {
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
        int yOffset = 60, timeOffset = 0, specialOffset = 0;
        for (std::size_t i = 0; i < fieldLabels.size(); ++i) {
            sf::FloatRect inputBoxBounds(240, yOffset - 5, 250, 35);
            if (inputBoxBounds.contains(mousePos)) {
                activeField = i;
                return;
            }
            if (i ==8)            
                timeOffset= yOffset +=40;
            if (i==9)
                specialOffset = yOffset +=40;
            yOffset += 50;
        }
        // ✅ Handle Time Selection Button Click          
        float timeButtonX = 10;

		for (int i = 0; i < timeSelection.size(); ++i) {
            sf::FloatRect timeButtonBounds(timeButtonX, timeOffset, 100, 30);
            if (timeButtonBounds.contains(mousePos)) {
                timeSelection[i].second = !timeSelection[i].second;
                //Update the "Preferred Time" input box
                userInput[8] = "";
                for (int i = 0; i < timeSelection.size(); ++i) {
                    if (timeSelection[i].second) {
                        if (!userInput[8].empty()) userInput[8] += "| ";  // ✅ Separate multiple selections
                        userInput[8] += timeSelection[i].first;
                    }
                }

                return;
            }
            timeButtonX += 110;  // Move to next button
        }
        // ✅ Handle Special Selection Botton click
        float sButtonX = 10;

		for (int i = 0; i < specialSelection.size(); ++i) {
            sf::FloatRect specialSelectionBounds(sButtonX, specialOffset, 150, 30);
            if (specialSelectionBounds.contains(mousePos)) {
                specialSelection[i].second = !specialSelection[i].second;
                //Update the "Preferred Time" input box
                userInput[9] = "";
                for (int i = 0; i < specialSelection.size(); ++i) {
                    if (specialSelection[i].second) {
                        if (!userInput[9].empty()) userInput[9] += "| ";  // ✅ Separate multiple selections
                        userInput[9] += specialSelection[i].first;
                    }
                }

                return;
            }
            sButtonX += 160;  // Move to next button
            
        }
        yOffset += 10;

        if (mousePos.x >= 20 && mousePos.x <= 160 && mousePos.y >= yOffset && mousePos.y <= yOffset + 40) {
            std::cout << "Train Booking Confirmed!\n";
            openConfirmationWindow();
            return;
        }

        if (mousePos.x >= 200 && mousePos.x <= 340 && mousePos.y >= yOffset && mousePos.y <= yOffset + 40) {
            std::cout << "Cancelled Train Booking\n";
            formManager->closeForm();
            return;
        }
    }
}
