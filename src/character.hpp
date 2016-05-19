#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "baseClasses.hpp"

class Character: public DrawableObject{
public:
  Character();
  void draw(SDL_Renderer *ren);
private:
  int mWidth;
  int mHeight;
};

#endif
