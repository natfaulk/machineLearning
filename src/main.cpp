#include <iostream>
#include <SDL2/SDL.h>
#include <fstream> // file operations
#include <ctime> // time()
#include "gameEngine.hpp"
#include "debugPane.hpp"
#include "textBox.hpp"
#include "AImain.hpp"

GameEngine game;
DebugPane debugPane;

const bool AI_CONTROLLED = true;

int main(int, char**){
	// srand(time(0));
	bool quit = false;
	SDL_Event e;

	game.myChar.setPos(100,-50);

	bool leftPressed = false;
	bool rightPressed = false;

	AI_Init();

	NronId leftID = AI_addOutput(&leftPressed);
	NronId rightID = AI_addOutput(&rightPressed);

	std::vector<NronId> tempInputs;
	std::vector<int> tempWeights;

	NronId tempId;
	tempId.type = NEURON_INPUT;

	tempId.id = 0;
	tempInputs.push_back(tempId);
	tempWeights.push_back(1);

	tempId.id = 4;
	tempInputs.push_back(tempId);
	tempWeights.push_back(-1);

	AI_addHiddenNeuron(leftID, tempInputs, tempWeights);

	tempInputs.clear();
	tempWeights.clear();

	tempId.id = 0;
	tempInputs.push_back(tempId);
	tempWeights.push_back(-1);

	tempId.id = 4;
	tempInputs.push_back(tempId);
	tempWeights.push_back(1);
	
	AI_addHiddenNeuron(rightID, tempInputs, tempWeights);

	// ai.addOutputHiddenNeuron(leftID, 0, 1, 4, -1);
	// ai.addOutputHiddenNeuron(rightID, 0, -1, 4, 1);
	// ai.addOutputHiddenNeuron(leftID, 0, 1, 2, -1);
	// ai.addOutputHiddenNeuron(rightID, 0, -1, 2, 1);
	

	AI_printNeurons();

	Uint32 previousTime = SDL_GetTicks();

	TextBox fpsText(GAME_WIDTH + 10, 10);
	fpsText.updateText("Hello World!");
	fpsText.setColour({0xFF,0xFF,0xFF});

	while(!quit){
		fpsText.updateText(std::to_string(1000.0/double(1+(SDL_GetTicks()-previousTime))));
		// std::cout << 1000.0/(1+(SDL_GetTicks()-previousTime)) << std::endl;
		previousTime = SDL_GetTicks();
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 ) {

			//User requests quit
			if( e.type == SDL_QUIT ) {
				quit = true;

			} else if( e.type == SDL_KEYDOWN ) {
				if(!AI_CONTROLLED){
					if(e.key.keysym.sym == SDLK_LEFT){
						leftPressed = true;
					} else if(e.key.keysym.sym == SDLK_RIGHT){
						rightPressed = true;
					}
				}
			} else if( e.type == SDL_KEYUP ) {
				if(!AI_CONTROLLED){
					if(e.key.keysym.sym == SDLK_LEFT){
						leftPressed = false;
					} else if(e.key.keysym.sym == SDLK_RIGHT){
						rightPressed = false;
					}
				}
			}
		}

		if(AI_CONTROLLED){
			// pass position information from game engine to AI
			AI_updateOutputs(game.getPlatforms(), game.getCharacter());
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
		fpsText.draw(game.getRenderer());

		SDL_RenderPresent( game.getRenderer() );

		if(game.gameOver()){
			quit = true;

			std::cout << "Final score: "<< game.getHeightJumped() << std::endl;
		}
	}

	std::ofstream myfile;
	myfile.open("scores.txt", std::ios::app);
	if(myfile.is_open()){
		myfile << game.getHeightJumped() << std::endl;
  	myfile.close();
	}else{
		std::cout<<"Unable to open file"<<std::endl;
	}

	game.cleanup();
	return 0;
}
