#pragma once
#include "BookingForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date
#include "RectanglText.h"

BookingForm::BookingForm(sf::RenderWindow& win, DialogueManager* manager) :window(win), formManager(manager) {

    m_inputFields = { FieldToInput(sf::Vector2f(250, 60), "Name:"), FieldToInput(sf::Vector2f(250, 110), "ID:")
                    ,FieldToInput(sf::Vector2f(250, 160), "Address:"), FieldToInput(sf::Vector2f(250, 210), "Email:") };
    fieldLabels = { "Name:", "ID:", "Address:", "Email:" };  // ✅ Add common fields
    userInput.resize(fieldLabels.size(), "");  // Initialize input fields
}
//==========================================
void BookingForm::render(sf::RenderWindow& window)
{
    RectanglText submit(20, sf::Vector2f(140, 40), sf::Vector2f(20, m_yOffset)
        , sf::Color(50, 150, 50), sf::Color::White, "DONE");

    submit.drawRec(window);

    RectanglText cancel(20, sf::Vector2f(140, 40), sf::Vector2f(200, m_yOffset)
        , sf::Color(180, 0, 0), sf::Color::White, "CANCEL");

    cancel.drawRec(window);
}
//==========================================
void BookingForm::openConfirmationWindow() {
    const std::string& formTitle = getFormType();
    sf::RenderWindow confirmWindow(sf::VideoMode(500, 600), "Confirm " + formTitle);

    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");

    bool approved = false;

    while (confirmWindow.isOpen()) {
        sf::Event event;
        while (confirmWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                confirmWindow.close();

            sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

            if (event.type == sf::Event::MouseButtonPressed) {
                if (mousePos.x >= 280 && mousePos.x <= 400 && mousePos.y >= 300 && mousePos.y <= 345) {
                    confirmWindow.close();
                }
                if (mousePos.x >= 100 && mousePos.x <= 220 && mousePos.y >= 300 && mousePos.y <= 345) {
                    std::cout << formTitle << " Confirmed! Returning to main menu." << std::endl;
                    approved = true;
                    confirmWindow.close();
                }
            }
        }

        confirmWindow.clear(sf::Color(240, 240, 240));

        sf::Text title("Confirm " + formTitle, font, 22);
        title.setFillColor(sf::Color::Black);
        title.setStyle(sf::Text::Bold);
        title.setPosition(130, 20);
        confirmWindow.draw(title);

		int yOffset = 150;
        for (std::size_t i = 0; i < m_inputFields.size(); ++i) {
            m_inputFields[i].drawToPresent(confirmWindow, yOffset);
			yOffset += 40;
        }
        //std::string bookingInfo;
        //for (size_t i = 0; i < fieldLabels.size(); ++i) {
        //    //פה צריך להכניס את הבדיקה
        //    bookingInfo += fieldLabels[i] + " " + userInput[i] + "\n";
        //}

        //sf::Text details(bookingInfo, font, 18);
        //details.setFillColor(sf::Color::Black);
        //details.setPosition(50, 80);
        //confirmWindow.draw(details);

        // ✅ Approve Button
		RectanglText approveText(18, sf::Vector2f(120, 40), sf::Vector2f(100, 300)
                        , sf::Color(50, 150, 50), sf::Color::White, "APPROVE");

        approveText.drawRec(confirmWindow);


        // ✅ Cancel Button
        RectanglText cancelButton(18, sf::Vector2f(120, 40), sf::Vector2f(280, 300)
            , sf::Color(180, 0, 0), sf::Color::White, "CANCEL");

        cancelButton.drawRec(confirmWindow);

        confirmWindow.display();
    }

    if (approved) {
        formManager->closeForm();
    }
}
