#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "baseClasses.hpp"

const int CHAR_HEIGHT = 30;
const int CHAR_WIDTH = 18;
const double CHAR_JUMP_VELOCITY = 20;

class Character: public DrawableObject{
public:
  Character();
  void draw(SDL_Renderer *ren);
private:
  int mWidth;
  int mHeight;
};

#endif
