#ifndef BASE_CLASSES_HPP
#define BASE_CLASSES_HPP

#include <SDL2/SDL.h>
#include "Constants.hpp"

class DrawableObject{
public:
  DrawableObject();
  virtual void draw(SDL_Renderer *ren, int heightJumped) = 0;
  void setPos(double xpos, double ypos);
  void move(void);
  void setVelocity(double xvel, double yvel);
  double getXvelocity(void);
  double getYvelocity(void);
  double getXpos(void);
  double getYpos(void);
  double getTransformedYpos(int heightJumped);
  void setXpos(double xpos);
  void setYpos(double ypos);

protected:
  double mXpos;
  double mYpos;
  double mXvel;
  double mYvel;
  bool mGravityAffected;
  bool mMoveable;
};

#endif
