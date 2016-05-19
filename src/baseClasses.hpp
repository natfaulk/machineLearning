#ifndef BASE_CLASSES_HPP
#define BASE_CLASSES_HPP

#include <SDL2/SDL.h>

class DrawableObject{
public:
  DrawableObject();
  virtual void draw(SDL_Renderer *ren) = 0;
  void setPos(double xpos, double ypos);
  void move(void);
  void setVelocity(double xvel, double yvel);
  double getXvelocity(void);
  double getYvelocity(void);
  double getXpos(void);
  double getYpos(void);

protected:
  double mXpos;
  double mYpos;
  double mXvel;
  double mYvel;
};

#endif
