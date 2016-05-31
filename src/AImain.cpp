#include "AImain.hpp"

#include <cstdlib> // rand()

AI::AI(){

}

void AI::addOutput(bool *output){
  mOutputs.push_back(output);
}

void AI::updateOutputs(void){
  for (int i = 0; i < mOutputs.size(); i++){
    (* mOutputs.at(i)) = bool(rand()%2);
  }
}
