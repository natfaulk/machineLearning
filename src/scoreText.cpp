#include "scoreText.hpp"
#include <iostream>

ScoreText::ScoreText(){
  mXpos = 0;
  mYpos = 0;

  mRobotoTTF = TTF_OpenFont("res/Roboto-Regular.ttf", 24);
  if(mRobotoTTF == nullptr){
    std::cout << "Couldn't load font: " << TTF_GetError() << std::endl;
		exit (EXIT_FAILURE);
  }
  mMessageRect.x = mXpos;  //controls the rect's x coordinate
  mMessageRect.y = mYpos; // controls the rect's y coordinte
  mMessageRect.w = 0; // controls the width of the rect
  mMessageRect.h = 0; // controls the height of the rect
}

ScoreText::~ScoreText(){
  // might need to destroy mMessage somehow
  SDL_FreeSurface( mMessageSurface );
  SDL_DestroyTexture(mMessageTexture);
  TTF_CloseFont( mRobotoTTF );
}


void ScoreText::draw(SDL_Renderer *ren, int heightJumped){
  mMessageRect.x = mXpos;
  mMessageRect.y = mYpos;
  // fast but no antialiasing
  mMessageSurface = TTF_RenderText_Solid(mRobotoTTF, std::to_string(heightJumped).c_str(),{0,0,0});
  // Slow but anti-aliased
  // mMessageSurface = TTF_RenderText_Blended(mRobotoTTF, std::to_string(heightJumped).c_str(),{0,0,0});
  mMessageTexture= SDL_CreateTextureFromSurface(ren, mMessageSurface);
  // get the text width and height
  SDL_QueryTexture(mMessageTexture, NULL, NULL, &mMessageRect.w, &mMessageRect.h);
  SDL_RenderCopy(ren, mMessageTexture, NULL, &mMessageRect);
}
