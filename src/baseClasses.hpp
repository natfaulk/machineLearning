#ifndef BASE_CLASSES_HPP
#define BASE_CLASSES_HPP

#include <SDL2/SDL.h>
#include "Constants.hpp"

class DrawableObject{
public:
  DrawableObject();
  // derived classes get warning when you delete a dynamic version if base class
  // has no destructor and derived class does
  virtual ~DrawableObject(){};
  virtual void draw(SDL_Renderer *ren, int heightJumped) = 0;
  void setPos(double xpos, double ypos);
  void move(void);
  void setVelocity(double xvel, double yvel);
  double getXvelocity(void) const;
  double getYvelocity(void) const;
  double getXpos(void) const;
  double getYpos(void) const;
  double getTransformedYpos(int heightJumped) const;
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
