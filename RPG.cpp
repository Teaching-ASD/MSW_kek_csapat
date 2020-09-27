#include <iostream>
#include "Game.h"

int main(int argc, char** argv)
{
    
    if(argc==1){
      std::cerr << "Nem adott meg parametert!" << std::endl;
   }

   else if (argc < 3){
      std::cerr << "Nem adott meg eleg! Ket fajl neve kell!" << std::endl;
   }
   else if(argc > 3) {
        std::cerr << "Tul sok input! Nem csinalok semmit! Ket fajl neve kell!" << std::endl;
   }
   else {

      Player* p1;
      Player* p2;
   

      try{
  
         //Fiel read, data parse, return Player*
         p1 = Player::parseUnit(*(argv+1));
         p2 = Player::parseUnit(*(argv+2));


         if(p1!=nullptr && p2!=nullptr){
            //Initialize game, fight and free memorye
            Game* game = new Game(p1,p2); 
            game->Fight();
            delete game;
         }
   
      }
      catch (const std::exception& e) {
         
         std::cerr << "File dosnt exist!" << std::endl;
         std::cerr << "Error: " << e.what() << std::endl;
       
         if(p1!=nullptr) delete p1;
      } 
    
     
   }

   
   return 0;

}