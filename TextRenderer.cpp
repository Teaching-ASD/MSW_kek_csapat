#include "TextRenderer.h"




TextRenderer::TextRenderer(std::ostream& customOutput) : defaultOutput(&customOutput){}
    
void TextRenderer::setOutputStream(std::ostream& customOutput){
    defaultOutput=&customOutput;
}