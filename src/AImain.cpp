#include "AImain.hpp"

#include <cstdlib> // rand()

AI::AI(){
  for(int i = 0; i<6;i++){ // char, platform above and below, x and y coords
    mInputNeurons.push_back(InputNeuron());
  }
  std::cout << "Length of input Neurons :"<< mInputNeurons.size() << std::endl;


}

void AI::addOutput(bool *output){
  mOutputs.push_back(output);
}

// void AI::updateOutputs(void){
//   for (int i = 0; i < mOutputs.size(); i++){
//     (* mOutputs.at(i)) = bool(rand()%2);
//   }
// }

// TODO add platform widths as an input
void AI::updateOutputs(const std::vector<Platform>& platforms, const Character& character){

  // update input Neuron values with position of character and platform above
  // and below.
  double tempCharX = character.getXpos();
  double tempCharY = character.getYpos();
  mInputNeurons.at(0).updateInput(tempCharX);
  mInputNeurons.at(1).updateInput(tempCharY);

  // make sure that platforms is not empty
  if (platforms.size()>0){
    // get index of platform above
    int i = 0;
    while(tempCharY>platforms.at(i).getYpos()){
      i++;
      if(i>=platforms.size()){
        std::cout << "Problem is here!! AImain platfoms list index out of range" << std::endl;
        // Was having errors due to < instead of > in while loop above
        // TODO remove this after checking that it is fixed
      }
    }
    // platform above
    double tempPlatX = platforms.at(i).getXpos();
    double tempPlatY = platforms.at(i).getYpos();
    mInputNeurons.at(4).updateInput(tempPlatX);
    mInputNeurons.at(5).updateInput(tempPlatY);

    // platform below
    // incase character is below first platform will use same value as platform above
    if (i != 0){
      tempPlatX = platforms.at(i-1).getXpos();
      tempPlatY = platforms.at(i-1).getYpos();
    }
    mInputNeurons.at(2).updateInput(tempPlatX);
    mInputNeurons.at(3).updateInput(tempPlatY);
  }
  
  // still doing random numbers
  // TODO make it use the neurons!!!
  for (int i = 0; i < mOutputs.size(); i++){
    (* mOutputs.at(i)) = bool(rand()%2);
  }
}
