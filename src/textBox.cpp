#include "textBox.hpp"
#include <iostream>

TextBox::TextBox(){
  mXpos = 0;
  mYpos = 0;

  this->init();
}

TextBox::TextBox(double xpos, double ypos){
  mXpos = xpos;
  mYpos = ypos;

  this->init();
}


void TextBox::init(void){
  mText = "";
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


TextBox::~TextBox(){
  // currently causing a seg fault due to TTF_Quit being called before this is deconstructed.
  // another reason to move all sdl setup stuff out of game engine

  // TODO uncomment this when sdl setup stuff sorted out

  // if(mMessageSurface!=nullptr){
  //   SDL_FreeSurface( mMessageSurface );
  // }
  // if(mMessageTexture!=nullptr){
  //   SDL_DestroyTexture(mMessageTexture);
  // }
  // if(mRobotoTTF!=nullptr){
  //   TTF_CloseFont( mRobotoTTF );
  // }
}

void TextBox::draw(SDL_Renderer *ren){
  mMessageRect.x = mXpos;
  mMessageRect.y = mYpos;
  // fast but no antialiasing
  mMessageSurface = TTF_RenderText_Solid(mRobotoTTF, mText.c_str(),mTextColor);
  // Slow but anti-aliased
  // mMessageSurface = TTF_RenderText_Blended(mRobotoTTF, std::to_string(heightJumped).c_str(),{0,0,0});
  mMessageTexture= SDL_CreateTextureFromSurface(ren, mMessageSurface);
  // get the text width and height
  SDL_QueryTexture(mMessageTexture, NULL, NULL, &mMessageRect.w, &mMessageRect.h);
  SDL_RenderCopy(ren, mMessageTexture, NULL, &mMessageRect);
}

void TextBox::updateText(std::string text){
  mText = text;
}

void TextBox::setColour(SDL_Color textColor){
  mTextColor = textColor;
}

void TextBox::setXpos(double xpos){
  mXpos = xpos;
}
void TextBox::setYpos(double ypos){
  mYpos = ypos;
}
