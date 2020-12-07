#ifndef TEXT_RENDERER_H
#define TEXT_RENDERER_H

#include "Renderer.h"
#include <iostream>

class TextRenderer : public Renderer {

protected:

    std::reference_wrapper<std::ostream> output;

    const std::string hero = "\u251C\u2524";
    const std::string monster = "M";
    const std::string monsters = "MM";
    const std::string Free = "\u2591";
    const std::string Wall = "\u2588";
    const std::string left_TopCorner = "\u2554";
    const std::string right_TopCorner = "\u2557";
    const std::string topAndBotFrame = "\u2550";
    const std::string leftAndRightFrame = "\u2551";
    const std::string left_BotCorner = "\u255A";
    const std::string right_BotCorner ="\u255D";

public:
    TextRenderer(std::ostream& customOutput=std::cout);
    void setOutputStream(std::ostream& customOutput);

};


#endif // TEXT_RENDERER_H