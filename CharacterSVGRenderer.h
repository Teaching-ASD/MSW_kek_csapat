#ifndef CHARACTER_SVG_RENDERER_H
#define CHARACTER_SVG_RENDERER_H

#include "SVGRenderer.h"

class CharacterSVGRenderer : public SVGRenderer {

public:
    CharacterSVGRenderer(std::string& filename);
    void render(const Game&) const override;

};

#endif // CHARACTER_SVG_RENDERER_H