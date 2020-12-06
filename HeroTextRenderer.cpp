#include "HeroTextRenderer.h"


HeroTextRenderer::HeroTextRenderer(std::ostream& customOutput): TextRenderer(customOutput) {

}


void HeroTextRenderer::render(const Game& game) const {
   const Map* map = game.getMap();
   map->getHeight();
}