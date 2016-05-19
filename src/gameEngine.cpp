#include "gameEngine.hpp"
#include <iostream>

void GameEngine::setup(void){
  if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		exit (EXIT_FAILURE);;
	}

	mSdlWindow = SDL_CreateWindow("Hello World!", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (mSdlWindow == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit (EXIT_FAILURE);
	}

	mSdlRenderer = SDL_CreateRenderer(mSdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (mSdlRenderer == nullptr){
		SDL_DestroyWindow(mSdlWindow);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit (EXIT_FAILURE);;
	}

  mPlatforms.push_back(Platform(SCREEN_WIDTH/2, SCREEN_HEIGHT-20, SCREEN_WIDTH));
  mPlatforms.push_back(Platform(200, 300, 50));
  mPlatforms.push_back(Platform(400, 500, 50));
}

void GameEngine::cleanup(void){
  SDL_DestroyRenderer(mSdlRenderer);
	SDL_DestroyWindow(mSdlWindow);
	SDL_Quit();
}

void GameEngine::render(void){
  SDL_SetRenderDrawColor( mSdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
  SDL_RenderClear( mSdlRenderer );

  myChar.draw(mSdlRenderer);
  for(int i = 0; i<mPlatforms.size(); i++){
    mPlatforms.at(i).draw(mSdlRenderer);
  }

  // for (int i = 0; i<mDrawableObjects; i++){
  //   mDrawableObjects.at(i).draw();
  // }

  //Update screen
  SDL_RenderPresent( mSdlRenderer );
}

void GameEngine::update(void){
  myChar.setVelocity(myChar.getXvelocity(),myChar.getYvelocity() + GRAVITY);
  double tempCharX = myChar.getXpos();
  double tempCharY = myChar.getYpos();
  myChar.move();

  for(int j = 0; j<mPlatforms.size(); j++){

    int tempDiffX = myChar.getXpos() - tempCharX;
    int tempDiffY = myChar.getYpos() - tempCharY;
    if (tempDiffY!=0){
      for(int i = 0; i<=tempDiffY;i++){
        if(mPlatforms.at(j).checkCollision(tempCharX + i*tempDiffX/tempDiffY, tempCharY + i)){
          myChar.setVelocity(myChar.getXvelocity(),-CHAR_JUMP_VELOCITY);
          myChar.setPos(tempCharX + i*tempDiffX/tempDiffY, tempCharY + i);
          break;
        }
      }
    }
  }

  if(myChar.getXpos()<0){
    myChar.setXpos(SCREEN_WIDTH);
  }
  if(myChar.getXpos()>SCREEN_WIDTH){
    myChar.setXpos(0);
  }

  if (myChar.getYpos() > SCREEN_HEIGHT){
    // game over
    myChar.setPos(myChar.getXpos(), 0);
  }
}
