#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include "baseClasses.hpp"
#include "Constants.hpp"

class Platform: public DrawableObject{
public:
  Platform();
  Platform(double xpos, double ypos, int width);
  void draw(SDL_Renderer *ren);
  void setWidth(int width);
  bool checkCollision(double x, double y);
private:
  int mWidth;
  int mHeight;
};

#endif
