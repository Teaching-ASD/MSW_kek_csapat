#ifndef SVG_RENDERER_H
#define SVG_RENDERER_H

#include "Renderer.h"
#include <iostream>

class SVGRenderer : public Renderer {

protected:
    const std::string& filename;
public:
    SVGRenderer(const std::string& filename) : filename(filename) {}

};

#endif // SVG_RENDERER_H