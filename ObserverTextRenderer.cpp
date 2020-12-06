#include "ObserverTextRenderer.h"


ObserverTextRenderer::ObserverTextRenderer(std::ostream& customOutput): TextRenderer(customOutput) {

}


void ObserverTextRenderer::render(const Game& game) const {

    const Map* map =  game.getMap();
    
    std::size_t height = map->getHeight();
    std::cout<<left_TopCorner;
    std::size_t width= map->getWidth();
    for(std::size_t i=0;i<width*2;i++)
    {
        std::cout<<topAndBotFrame;
    }
    std::cout<<right_TopCorner;
    std::cout<<std::endl;
    for(std::size_t r =0; r<height; r++){
        
        std::size_t lenght = map->getRowLenght(r);
        std::cout<<leftAndRightFrame;
        for(std::size_t c =0; c<lenght; c++){
            
            switch(map->get(r, c))
            {
            case Map::type::Free:
                std::cout<<Free;
                std::cout<<Free;
                break;
            case Map::type::Wall:
                std::cout<<Wall;
                std::cout<<Wall;
                break;
            case Map::type::Hero:
                std::cout<<hero;
                break;
            case Map::type::Monster1:
            case Map::type::Monster2: 
            case Map::type::Monster3:
                std::cout<<monster;
                std::cout<<Free;
                break;
            default:
                break;
            }
            
        }

        for (std::size_t i = lenght; i < width; i++)
        {
            std::cout<<Wall;
            std::cout<<Wall;
        }
        std::cout<<leftAndRightFrame;
        std::cout << std::endl;
    }

    std::cout<<left_BotCorner;

    for (std::size_t i= 0; i < width*2 ;i++)
    {
        std::cout<<topAndBotFrame;
    }

    std::cout<<right_BotCorner;
    std::cout << std::endl;
}