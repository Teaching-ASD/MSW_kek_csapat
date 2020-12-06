#include "ObserverSVGRenderer.h"
#include <fstream>


ObserverSVGRenderer::ObserverSVGRenderer(const std::string& filename) : SVGRenderer(filename){

}


void ObserverSVGRenderer::render(const Game& game) const {

    const Map* gameMap = game.getMap();
    std::ofstream file(filename);

    std::size_t height = gameMap->getHeight();
    std::size_t width = gameMap->getWidth();
  
    std::string wallHref = game.getTextureFile("wall_texture");
    std::string freeHref = game.getTextureFile("free_texture");
    std::string monster1Href = game.getCharacterTextureFile("Fallen");
    std::string monster2Href = game.getCharacterTextureFile("Zombie");
    std::string monster3Href = game.getCharacterTextureFile("Blood Raven");
    std::string heroHref = game.getCharacterTextureFile("Prince Aidan of Khanduras");
    
	file << "<svg xmlns=\"http://www.w3.org/2000/svg\" width='300' height='300'>\n";
    
    for(std::size_t r=0; r< height; r++){
            std::size_t lenght = gameMap->getRowLenght(r);
        for(std::size_t c = 0; c< lenght; c++){
                std::string stringR = std::to_string(c*10);
                std::string stringC = std::to_string(r*10);
                switch(gameMap->get(r,c))
                {
                case Map::type::Free:
                    file << "<image x=\'" + stringR + "\' y=\'" + stringC +"\' width = '10' height = '10' href = \""+ freeHref + "\"/>";
                    break;
                case Map::type::Wall:
                    file << "<image x=\'" + stringR + "\' y=\'" + stringC +"\' width = '10' height = '10' href = \""+ wallHref + "\"/>";
                    break;
                case Map::type::Hero:
                    file << "<image x=\'" + stringR + "\' y=\'" + stringC +"\' width = '10' height = '10' href = \""+ heroHref + "\"/>";
                    break;
                case Map::type::Monster1:
                    file << "<image x=\'" + stringR + "\' y=\'" + stringC +"\' width = '10' height = '10' href = \""+ monster1Href + "\"/>";
                    break;
                case Map::type::Monster2: 
                    file << "<image x=\'" + stringR + "\' y=\'" + stringC +"\' width = '10' height = '10' href = \""+ monster2Href + "\"/>";
                    break;
                case Map::type::Monster3:
                    file << "<image x=\'" + stringR + "\' y=\'" + stringC +"\' width = '10' height = '10' href = \""+ monster3Href + "\"/>";
                     break;
                default:
                    break;
                }
            }

            
            for (std::size_t i = lenght; i < width; i++)
            {
                    file << "<image x=\'" + std::to_string(i*10) + "\' y=\'" +  std::to_string(r*10) +"\' width = '10' height = '10' href = \""+ wallHref + "\"/>";
            }
               
     
            file << "<br/>";
        }
        
    file << "</svg>\n";
        
}
  