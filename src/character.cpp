#include "character.hpp"

Character::Character(){
  mWidth = 10;
  mHeight = 10;
}

void Character::draw(SDL_Renderer *ren ){
  SDL_Rect fillRect = { int(mXpos - mWidth/2), int(mYpos + mHeight), 50, 50 };
  SDL_SetRenderDrawColor( ren, 0xFF, 0x00, 0x00, 0xFF );
  SDL_RenderFillRect( ren, &fillRect );
}
