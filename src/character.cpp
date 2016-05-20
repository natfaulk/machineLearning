#include "character.hpp"

Character::Character(){
  mWidth = CHAR_WIDTH;
  mHeight = CHAR_HEIGHT;
  mGravityAffected = true;
  mMoveable = true;
}

void Character::draw(SDL_Renderer *ren, int heightJumped){
  SDL_Rect fillRect = { int(mXpos - mWidth/2), int(this->getTransformedYpos(heightJumped) - mHeight), mWidth, mHeight };
  SDL_SetRenderDrawColor( ren, 0xFF, 0x00, 0x00, 0xFF );
  SDL_RenderFillRect( ren, &fillRect );
}
