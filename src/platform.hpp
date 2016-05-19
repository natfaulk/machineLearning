#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include "baseClasses.hpp"

class Platform: public DrawableObject{
public:
  Platform();
  void draw(SDL_Renderer *ren);
  void setWidth(int width);
private:
  int mWidth;
  int mHeight;
};

#endif
