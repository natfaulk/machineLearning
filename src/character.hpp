#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "baseClasses.hpp"
#include "Constants.hpp"

class Character: public DrawableObject{
public:
  Character();
  void draw(SDL_Renderer *ren, int heightJumped);
private:
  int mWidth;
  int mHeight;
};

#endif
