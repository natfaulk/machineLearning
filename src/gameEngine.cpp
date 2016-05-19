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

  ground.setPos(SCREEN_WIDTH/2,SCREEN_HEIGHT-20);
  ground.setWidth(SCREEN_WIDTH);
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
  ground.draw(mSdlRenderer);

  // for (int i = 0; i<mDrawableObjects; i++){
  //   mDrawableObjects.at(i).draw();
  // }

  //Update screen
  SDL_RenderPresent( mSdlRenderer );
}

void GameEngine::update(void){
  myChar.setVelocity(myChar.getXvelocity(),myChar.getYvelocity() + GRAVITY);
  myChar.move();
  if (myChar.getYpos() > SCREEN_HEIGHT){
    myChar.setPos(myChar.getXpos(), 0);
  }
}
