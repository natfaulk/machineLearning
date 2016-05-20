#ifndef SCORE_TEXT_HPP
#define SCORE_TEXT_HPP

#include <SDL2_ttf/SDL_ttf.h>
#include "baseClasses.hpp"
#include "Constants.hpp"

class ScoreText: public DrawableObject{
public:
  ScoreText();
  ~ScoreText();
  void draw(SDL_Renderer *ren, int heightJumped);
private:
  int mWidth;
  int mHeight;
  TTF_Font* mRobotoTTF;
  SDL_Surface* mSurfaceMessage;
  SDL_Texture* mMessage;
  SDL_Rect mMessageRect;
};

#endif
