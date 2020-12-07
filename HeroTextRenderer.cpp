#include "HeroTextRenderer.h"


HeroTextRenderer::HeroTextRenderer(std::ostream& customOutput): TextRenderer(customOutput) {

}


void HeroTextRenderer::render(const Game& game) const {

   const Map* gameMap = game.getMap();
   const Hero* gameHero = game.getHero();

    int height = gameMap->getHeight();
    
    int width=gameMap->getWidth();
    int lr= gameHero->getLightRadius();
    int MaxFrame=0;
    int X=gameHero->getPositionX();
    int Y=gameHero->getPositionY();
   
    for (int i=0;i<lr*2+1;i++){

        if(Y-lr+i>=0&&width>Y-lr+i){
            MaxFrame++;
        }
    }
    
    output.get()<<left_TopCorner;
    for(int i=0;i<MaxFrame*2;i++)
    {
        output.get()<<topAndBotFrame;
    }
    output.get()<<right_TopCorner;
    output.get()<<std::endl;
    bool write = true;
    int r;
    int c;
    for(r=0; r<lr*2+1; r++){

        if(write && (X-lr+r)<height){
          
            output.get()<<leftAndRightFrame;

        }
        try{
        for(c = 0; c<lr*2+1; c++){
            
            if(X-lr+r>=0 && Y-lr+c>=0 && X-lr+r<height && Y-lr+c<width){
                write=true;
                switch(gameMap->get(X-lr+r, Y-lr+c))
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
            }else if(Y-lr+c<width){
                write=false;
            }
        }

        }catch(Map::WrongIndexException &e){

                for (int i = 0; (Y-lr)+i+c <width; i++)
                {
                    if((Y-lr)+i+c <= Y+lr){
                        output.get()<<Wall;
                        output.get()<<Wall;
                    }
           
                }  
        }

        if (write && X-lr+r<height){
            write = true;
            output.get() << leftAndRightFrame;
            output.get() << std::endl;
        }

    }

    output.get()<<left_BotCorner;
    
    for (int i= 0; i < MaxFrame*2 ;i++)
    {
        output.get()<<topAndBotFrame;
    }

    output.get() << right_BotCorner;
    output.get() << std::endl;

}