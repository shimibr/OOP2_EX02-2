#pragma once
#include "BookingForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date
#include "RectanglText.h"
#include "Name.h"
#include "Id.h"
#include "Address.h"
#include "Email.h"

BookingForm::BookingForm(sf::RenderWindow& win, DialogueManager* manager) :window(win), formManager(manager) {
	m_yOffset = 60;
    m_inputFields.push_back(std::make_unique<Name>(m_yOffset));
    m_inputFields.push_back(std::make_unique<Id>(m_yOffset += 50));
    m_inputFields.push_back(std::make_unique<Address>(m_yOffset += 50));
    m_inputFields.push_back(std::make_unique<Email>(m_yOffset += 50)) ;

    fieldLabels = { "Name:", "ID:", "Address:", "Email:" };  // ✅ Add common fields
    userInput.resize(fieldLabels.size(), "");  // Initialize input fields
}
//==========================================
void BookingForm::render(sf::RenderWindow& window)
{
    RectanglText submit(20, sf::Vector2f(140, 40), sf::Vector2f(20, m_yOffset+50)
        , sf::Color(50, 150, 50), sf::Color::White, "DONE");

    submit.drawRec(window);

    RectanglText cancel(20, sf::Vector2f(140, 40), sf::Vector2f(200, m_yOffset+50)
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

		int yOffset = 100;
        for (std::size_t i = 0; i < m_inputFields.size(); ++i) {
            m_inputFields[i]->drawToPresent(confirmWindow, yOffset);
			yOffset += 40;
        }

        // ✅ Approve Button
		RectanglText approveText(18, sf::Vector2f(120, 40), sf::Vector2f(100, yOffset)
                        , sf::Color(50, 150, 50), sf::Color::White, "APPROVE");

        approveText.drawRec(confirmWindow);


        // ✅ Cancel Button
        RectanglText cancelButton(18, sf::Vector2f(120, 40), sf::Vector2f(280, yOffset)
            , sf::Color(180, 0, 0), sf::Color::White, "CANCEL");

        cancelButton.drawRec(confirmWindow);

        confirmWindow.display();
    }

    if (approved) {
        formManager->closeForm();
    }
}
