#include "Pos.h"
    

Pos::Pos(){
    
}

Pos::Pos(int x, int y) : x(x), y(y) {
    
}
    
void Pos::set(int newX, int newY){
    x=newX;
    y=newY;
}

int Pos::getX()const{
    return x;
}

int Pos::getY()const{
    return y;
}

void Pos::IDX(bool IorD){
    x += IorD ? 1 : -1;
}

void Pos::IDY(bool IorD){
    y += IorD ? 1 : -1;
}