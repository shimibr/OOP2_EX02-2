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
#include <RecPress.h>

BookingForm::BookingForm(sf::RenderWindow& win, DialogueManager* manager) :window(win), formManager(manager) {
	m_yOffset = 60;
    m_inputFields.push_back(std::make_unique<Name>(m_yOffset));
    m_inputFields.push_back(std::make_unique<Id>(m_yOffset += 50));
    m_inputFields.push_back(std::make_unique<Address>(m_yOffset += 50, "Address:"));
    m_inputFields.push_back(std::make_unique<Email>(m_yOffset += 50)) ;
   
    fieldLabels = { "Name:", "ID:", "Address:", "Email:" };  // ✅ Add common fields
    userInput.resize(fieldLabels.size(), "");  // Initialize input fields
}
//==========================================
void BookingForm::render(sf::RenderWindow& window)
{

    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");

    window.clear(sf::Color(235, 235, 235));

    // ✅ Title
    sf::Text title(getFormType() + " Form", font, 26);
    title.setFillColor(sf::Color(20, 20, 20));
    title.setStyle(sf::Text::Bold);
    title.setPosition(20, 10);
    window.draw(title);

    for (std::size_t i = 0; i < m_inputFields.size(); ++i) {
        m_inputFields[i]->drawToForm(window);
    }
   
	for (std::size_t i = 0; i < m_buttons.size(); ++i) {
		m_buttons[i].drawRec(window);
	}

}
//=========================================
void BookingForm::handleInput(sf::Event event)
{
    checkAllFieldsFilled();

    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == '\b') {
            m_inputFields[activeField]->setInputBack();
        }
        else if (event.text.unicode >= 32 && event.text.unicode < 128) {
            m_inputFields[activeField]->setInput(static_cast<char>(event.text.unicode));
        }
    }
    else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Tab) {
            m_inputFields[activeField]->setIsSelected(false);
			activeField = (activeField + 1) % m_inputFields.size();
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
            if (m_inputFields[i]->isInputBox(mousePos)) {
                activeField = i;
            }
            yOffset += 50;//hyuijbhio
        }


        if (m_buttons[0].isRecPress(mousePos)&& m_allFieldsFilled) {
            std::cout << "Car Rental Confirmed!\n";
            openConfirmationWindow();
            return;
        }

        if (m_buttons[1].isRecPress(mousePos)) {
            std::cout << "Cancelled Car Rental\n";
            formManager->closeForm();
            return;
        }
    }
    m_inputFields[activeField]->setIsSelected(true);
}
//=========================================
void BookingForm::checkAllFieldsFilled()
{
    m_buttons[0].setColor(sf::Color(50, 150, 50));
    m_allFieldsFilled = true;
    for (std::size_t i = 0; i < m_inputFields.size(); ++i)
        if (!m_inputFields[i]->fieldIsFill())
        {
            m_buttons[0].setColor(sf::Color(150, 150, 150));
            m_allFieldsFilled = false;
            break;
        }
}
//=========================================
void BookingForm::setbuttons()
{
    m_buttons.push_back(RecPress(sf::Vector2f(30, m_yOffset + 50), 18, "DONE", sf::Color(150, 150, 150)));
    m_buttons.push_back(RecPress(sf::Vector2f(180, m_yOffset + 50), 18, "CANCEL", sf::Color(180, 0, 0)));
}
//===========================================
void BookingForm::setDefaultValues()
{
}
//==========================================
void BookingForm::openConfirmationWindow() {
    sf::RenderWindow confirmWindow(sf::VideoMode(500, 600), "Confirm " + getFormType());
    
    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");
    confirmWindow.clear(sf::Color(240, 240, 240));

    int yOffset = 80;
    for (std::size_t i = 0; i < m_inputFields.size(); ++i) {
        m_inputFields[i]->drawToPresent(confirmWindow, yOffset);
        yOffset += 25;
    }

	RecPress pressAPPROVE(sf::Vector2f(100, yOffset),18, "APPROVE", sf::Color(50, 150, 50));
    pressAPPROVE.drawRec(confirmWindow);

    RecPress pressCANCEL(sf::Vector2f(280, yOffset), 18, "CANCEL", sf::Color(180,0,0));
    pressCANCEL.drawRec(confirmWindow);


    sf::Text title("Confirm " + getFormType(), font, 22);
    title.setFillColor(sf::Color::Black);
    title.setStyle(sf::Text::Bold);
    title.setPosition(130, 20);
    confirmWindow.draw(title);

    confirmWindow.display();
    


    bool approved = false;

    while (confirmWindow.isOpen()) {
        sf::Event event;
        while (confirmWindow.waitEvent(event)) {
            if (event.type == sf::Event::Closed)
                confirmWindow.close();

            sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

            if (event.type == sf::Event::MouseButtonPressed) {
                if (pressCANCEL.isRecPress(mousePos)) {
                    confirmWindow.close();
                }
                if (pressAPPROVE.isRecPress(mousePos)) {
                    std::cout << getFormType() << " Confirmed! Returning to main menu." << std::endl;
                    approved = true;
                    confirmWindow.close();
                }
            }
        }

        
    }

    if (approved) {
        formManager->closeForm();
    }
}
