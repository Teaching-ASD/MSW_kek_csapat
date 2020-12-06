#include "TextRenderer.h"




TextRenderer::TextRenderer(std::ostream& customOutput) : output(customOutput){}
    
void TextRenderer::setOutputStream(std::ostream& customOutput){
    output=customOutput;
}