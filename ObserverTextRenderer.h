#ifndef OBSERVER_TEXT_RENDERER_H
#define OBSERVER_TEXT_RENDERER_H

#include "TextRenderer.h"

class ObserverTextRenderer : public TextRenderer {

public:
    ObserverTextRenderer(std::ostream& customOutput=std::cout);
    void render(const Game&) const override;

};


#endif // OBSERVER_TEXT_RENDERER_H