#pragma once

#include "Email.h"

Email::Email(int& yOffset)
    :FieldToInput(yOffset, "Email:") {
}

//=========================================
bool Email::validateInput(sf::RenderWindow& window, int& yOffset)
{
        if (m_inputString.find(' ') != std::string::npos) {
            return false;
        }

        size_t atPos = m_inputString.find('@');
        if (atPos == std::string::npos || m_inputString.find('@', atPos + 1) != std::string::npos) {
            return false;
        }

        std::string username = m_inputString.substr(0, atPos);
        std::string domainAndSuffix = m_inputString.substr(atPos + 1);

        if (username.empty()) {
            return false;
        }
        for (char c : username) {
            if (!isValidChar(c)) {
                return false;
            }
        }

        size_t lastDotPos = domainAndSuffix.rfind('.');
        if (lastDotPos == std::string::npos || lastDotPos == 0 || lastDotPos == domainAndSuffix.length() - 1) {
            return false;
        }

        std::string domain = domainAndSuffix.substr(0, lastDotPos);
        std::string suffix = domainAndSuffix.substr(lastDotPos + 1);

        if (domain.empty()) {
            return false;
        }
        for (char c : domain) {
            if (!isValidChar(c)) {
                return false;
            }
        }

        if (suffix.length() < 2) {
            return false;
        }
        for (char c : suffix) {
            if (!std::isalpha(static_cast<unsigned char>(c))) {
                return false;
            }
        }

        return true;
}
//=========================================
void Email::drawToPresent(sf::RenderWindow& window, int& yOffset)
{
    FieldToInput::drawToPresent(window, yOffset);
    if (!validateInput(window, yOffset))
    {
        m_PresentError.setString("The input does not adhere to the expected format");
        m_PresentError.setPosition(50, yOffset);
        window.draw(m_PresentError);
    }
}
//=========================================
bool Email::isValidChar(char c) const
{
    return std::isalnum(static_cast<unsigned char>(c)) || c == '.' || c == '-' || c == '_';
}