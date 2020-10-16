#include <iostream>
#include "Game.h"
#include "ReadFileError.h"
#include <any>



int main(int argc, char** argv)
{
   
   if(argc!=3 && argc!=1){
      std::cerr << "BadRun Error:\nExcpected run:\n[1] ./auto example1.json example2.json\n" 
      << "[2] ./auto {\\\"name\\\":\\\"Kakarott\\\"\\\"hp\\\":10\\\"dmg\\\":5}" 
      << "{\\\"name\\\":\\\"pista\\\"\\\"hp\\\":20\\\"dmg\\\":2}" << std::endl;
      return 1;
   }   
   else {
          Game* game;
      try{
     
         if(argc==1){
            std::cout << "You don't add file or string to command line argument.\nYou can type the json now.\nWhen you finished one json hit enter after Crtl+Z.\n";
            game = new Game(std::cin);
         }
         else{
            game = new Game(argv);
         }
    
         game->Fight();
         delete game;
      }
      catch (const ReadFileError& re) {
         delete game;
         return 1;
      } 
      catch (const std::bad_any_cast& bac){
         std::cout << bac.what() << std::endl;
         delete game;
         return 1;
      }
      catch(const std::exception& ex){
         std::cout << ex.what() << std::endl;
         delete game;
         return 1;
      }
    
     
   }

   return 0;

}