#ifndef OBSERVER_SVG_RENDERER_H
#define OBSERVER_SVG_RENDERER_H

#include "SVGRenderer.h"

class ObserverSVGRenderer : public SVGRenderer {

public:
    ObserverSVGRenderer(std::string& filename);
    void render(const Game&) const override;

};

#endif // OBSERVER_SVG_RENDERER_H