#include "platform.hpp"

Platform::Platform(){
  mWidth = 0;
  mHeight = PLATFORM_HEIGHT;
}

Platform::Platform(double xpos, double ypos, int width){
  mXpos = xpos;
  mYpos = ypos;
  mWidth = width;
  mHeight = PLATFORM_HEIGHT;
}

void Platform::draw(SDL_Renderer *ren, int heightJumped){
  SDL_Rect fillRect = { int(mXpos - mWidth/2), int(this->getTransformedYpos(heightJumped)), mWidth, mHeight };
  SDL_SetRenderDrawColor( ren, 0x00, 0x00, 0x00, 0xFF );
  SDL_RenderFillRect( ren, &fillRect );
}

void Platform::setWidth(int width){
  mWidth = width;
}

bool Platform::checkCollision(double x, double y){
  x -= mXpos;
  y -= mYpos;
  if(x<=mWidth / 2 && x>=-mWidth/2 && y>=0 && y<mHeight){
    return true;
  }else{
    return false;
  }
}
