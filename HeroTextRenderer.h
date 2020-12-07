#ifndef HERO_TEXT_RENDERER_H
#define HERO_TEXT_RENDERER_H

#include "TextRenderer.h"

class HeroTextRenderer : public TextRenderer {

public:
    HeroTextRenderer(std::ostream& customOutput=std::cout);
    void render(const Game&) const override;

};


#endif // HERO_TEXT_RENDERER_H