#include "CharacterSVGRenderer.h"
#include <fstream>


CharacterSVGRenderer::CharacterSVGRenderer(std::string& filename) : SVGRenderer(filename){

}


void CharacterSVGRenderer::render(const Game& game) const {

    const Map* gameMap = game.getMap();
    const Hero* gameHero = game.getHero();
    std::ofstream file(filename);

    int height = gameMap->getHeight();
    int width = gameMap->getWidth();
    int lr= gameHero->getLightRadius();
    int MaxFrame=0;
    int X=gameHero->getPositionX();
    int Y=gameHero->getPositionY();
  
    std::string wallHref = game.getTextureFile("wall_texture");
    std::string freeHref = game.getTextureFile("free_texture");
    std::string monster1Href = game.getCharacterTextureFile("Fallen");
    std::string monster2Href = game.getCharacterTextureFile("Zombie");
    std::string monster3Href = game.getCharacterTextureFile("Blood Raven");
    std::string heroHref = game.getCharacterTextureFile("Prince Aidan of Khanduras");


    for (int i=0;i<lr*2+1;i++){

        if(Y-lr+i>=0&&width>Y-lr+i){
            MaxFrame++;
        }
    }
    
	file << "<svg xmlns=\"http://www.w3.org/2000/svg\" width='100' height='100'>\n";
    
    int r;
    int c;
    for(r=0; r<lr*2+1; r++){
        for(c = 0; c<lr*2+1; c++){

            if(X-lr+r>=0 && Y-lr+c>=0 && X-lr+r<height && Y-lr+c<width){
                int R = X-lr+r;
                int C = Y-lr+c;
                std::string stringR = std::to_string(C*10);
                std::string stringC = std::to_string(R*10);
                try{
                switch(gameMap->get(R,C))
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
                catch(Map::WrongIndexException &e){

                for (int i = 0; (Y-lr)+i+c <width; i++)
                {
                    if((Y-lr)+i+c <= Y+lr)  file << "<image x=\'" + stringR + "\' y=\'" +  stringC +"\' width = '10' height = '10' href = \""+ wallHref + "\"/>";
                } 
            }
        }
    }
     file << "<br/>";
    }
    file << "</svg>\n";
    file.close();
}