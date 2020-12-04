#ifndef POS_H
#define POS_H

class Pos {
    int x=-1;
    int y=-1;

public:
    Pos();
    Pos(int x, int y);
    
    void set(int newX, int newY);
    int getX() const ;
    int getY() const;
    void IDX(bool IorD);
    void IDY(bool IorD);


};

#endif //POS_H