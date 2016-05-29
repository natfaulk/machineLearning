#include "scoreText.hpp"
#include <iostream>

ScoreText::ScoreText(){
  mWidth = 200;
  mHeight = 50;
  mXpos = GAME_WIDTH - mWidth;
  mYpos = 0;

  mRobotoTTF = TTF_OpenFont("res/Roboto-Regular.ttf", 24);
  if(mRobotoTTF == nullptr){
    std::cout << "Couldn't load font: " << TTF_GetError() << std::endl;
		exit (EXIT_FAILURE);
  }
  mMessageRect.x = 0;  //controls the rect's x coordinate
  mMessageRect.y = 0; // controls the rect's y coordinte
  mMessageRect.w = mWidth; // controls the width of the rect
  mMessageRect.h = mHeight; // controls the height of the rect
}

ScoreText::~ScoreText(){
  // might need to destroy mMessage somehow
  SDL_FreeSurface( mSurfaceMessage );
  TTF_CloseFont( mRobotoTTF );
}


void ScoreText::draw(SDL_Renderer *ren, int heightJumped){
  mSurfaceMessage = TTF_RenderText_Solid(mRobotoTTF, "put your text here", {0,0,0});
  mMessage = SDL_CreateTextureFromSurface(ren, mSurfaceMessage);
  SDL_RenderCopy(ren, mMessage, NULL, &mMessageRect);
}
