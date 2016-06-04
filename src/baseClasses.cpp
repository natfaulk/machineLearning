#include "baseClasses.hpp"

DrawableObject::DrawableObject(){
  mXpos=0;
  mYpos=0;
  mXvel=0;
  mYvel=0;
  mGravityAffected = false;
  mMoveable = false;
}


void DrawableObject::setPos(double xpos, double ypos){
  mXpos = xpos;
  mYpos = ypos;
}

void DrawableObject::setVelocity(double xvel, double yvel){
  mXvel = xvel;
  mYvel = yvel;
}

double DrawableObject::getXpos(void) const{
  return mXpos;
}

double DrawableObject::getYpos(void) const{
  return mYpos;
}

double DrawableObject::getXvelocity(void) const{
  return mXvel;
}

double DrawableObject::getYvelocity(void) const{
  return mYvel;
}

void DrawableObject::move(void){
  mXpos += mXvel;
  mYpos += mYvel;
}

void DrawableObject::setXpos(double xpos){
  mXpos = xpos;
}
void DrawableObject::setYpos(double ypos){
  mYpos = ypos;
}

double DrawableObject::getTransformedYpos(int heightJumped) const{
  return (heightJumped - mYpos) + JUMPING_THRESHOLD_HEIGHT;
}
