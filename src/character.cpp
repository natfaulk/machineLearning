#include "character.hpp"

Character::Character(){
  mWidth = 10;
  mHeight = 20;
  mGravityAffected = true;
  mMoveable = true;
}

void Character::draw(SDL_Renderer *ren ){
  SDL_Rect fillRect = { int(mXpos - mWidth/2), int(mYpos - mHeight), mWidth, mHeight };
  SDL_SetRenderDrawColor( ren, 0xFF, 0x00, 0x00, 0xFF );
  SDL_RenderFillRect( ren, &fillRect );
}
