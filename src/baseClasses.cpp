#include "baseClasses.hpp"

DrawableObject::DrawableObject(){
  mXpos=0;
  mYpos=0;
  mXvel=0;
  mYvel=0;
}


void DrawableObject::setPos(double xpos, double ypos){
  mXpos = xpos;
  mYpos = ypos;
}

void DrawableObject::setVelocity(double xvel, double yvel){
  mXvel = xvel;
  mYvel = yvel;
}

double DrawableObject::getXpos(void){
  return mXpos;
}

double DrawableObject::getYpos(void){
  return mYpos;
}

double DrawableObject::getXvelocity(void){
  return mXvel;
}

double DrawableObject::getYvelocity(void){
  return mYvel;
}

void DrawableObject::move(void){
  mXpos += mXvel;
  mYpos += mYvel;
}
