#include "ObserverTextRenderer.h"


ObserverTextRenderer::ObserverTextRenderer(std::ostream& customOutput): TextRenderer(customOutput) {

}


void ObserverTextRenderer::render(const Game& game) const {

    const Map* map =  game.getMap();
    
    std::size_t height = map->getHeight();
    output.get() << left_TopCorner;
    std::size_t width= map->getWidth();
    for(std::size_t i=0;i<width*2;i++)
    {
        output.get()<<topAndBotFrame;
    }
    output.get()<<right_TopCorner;
    output.get()<<std::endl;
    for(std::size_t r =0; r<height; r++){
        
        std::size_t lenght = map->getRowLenght(r);
        output.get()<<leftAndRightFrame;
        for(std::size_t c =0; c<lenght; c++){
            
            switch(map->get(r, c))
            {
            case Map::type::Free:
                output.get()<<Free;
                output.get()<<Free;
                break;
            case Map::type::Wall:
                output.get()<<Wall;
                output.get()<<Wall;
                break;
            case Map::type::Hero:
                output.get()<<hero;
                break;
            case Map::type::Monster1:
            case Map::type::Monster2: 
            case Map::type::Monster3:
                output.get()<<monster;
                output.get()<<Free;
                break;
            default:
                break;
            }
            
        }

        for (std::size_t i = lenght; i < width; i++)
        {
            output.get()<<Wall;
            output.get()<<Wall;
        }
        output.get()<<leftAndRightFrame;
        output.get() << std::endl;
    }

    output.get()<<left_BotCorner;

    for (std::size_t i= 0; i < width*2 ;i++)
    {
        output.get()<<topAndBotFrame;
    }

    output.get()<<right_BotCorner;
    output.get() << std::endl;
}