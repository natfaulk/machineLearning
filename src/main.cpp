#include <iostream>
#include <SDL2/SDL.h>
#include "gameEngine.hpp"
#include "debugPane.hpp"

GameEngine game;
DebugPane debugPane;

int main(int, char**){
	bool quit = false;
	SDL_Event e;

	game.myChar.setPos(100,-50);

	bool leftPressed = false;
	bool rightPressed = false;

	while(!quit){
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 ) {
			//User requests quit
			if( e.type == SDL_QUIT ) {
				quit = true;

			} else if( e.type == SDL_KEYDOWN ) {
				if(e.key.keysym.sym == SDLK_LEFT){
					leftPressed = true;
				} else if(e.key.keysym.sym == SDLK_RIGHT){
					rightPressed = true;
				}
			} else if( e.type == SDL_KEYUP ) {
				if(e.key.keysym.sym == SDLK_LEFT){
					leftPressed = false;
				} else if(e.key.keysym.sym == SDLK_RIGHT){
					rightPressed = false;
				}
			}
		}

		if (leftPressed){
			game.myChar.setVelocity(game.myChar.getXvelocity()-0.1,game.myChar.getYvelocity());
		}
		if (rightPressed){
			game.myChar.setVelocity(game.myChar.getXvelocity()+0.1,game.myChar.getYvelocity());
		}

		game.update();
		game.managePlatforms();
		game.render();

		// see comment by getRenderer() definition
		debugPane.draw(game.getRenderer());

		SDL_RenderPresent( game.getRenderer() );
	}


	game.cleanup();
	return 0;
}
