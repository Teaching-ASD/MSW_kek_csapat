#ifndef SVG_RENDERER_H
#define SVG_RENDERER_H

#include "Renderer.h"
#include <iostream>

class SVGRenderer : public Renderer {

protected:
     std::string& filename;
public:
    SVGRenderer(std::string& filename) : filename(filename) {}

};

#endif // SVG_RENDERER_H