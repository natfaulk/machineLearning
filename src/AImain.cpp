#include "AImain.hpp"

#include <cstdlib> // rand()

AI::AI(){
  for(int i = 0; i<6;i++){ // char, platform above and below, x and y coords
    mInputNeurons.push_back(InputNeuron());
  }
  // std::cout << "Length of input Neurons :"<< mInputNeurons.size() << std::endl;
  // HiddenNeuron tempHiddenNeuron;
  // tempHiddenNeuron.addInput(&mInputNeurons.at(0), 1);
  // tempHiddenNeuron.addInput(&mInputNeurons.at(4), -1);
  // tempHiddenNeuron.mThreshold = 0;
  // mHiddenNeurons.push_back(tempHiddenNeuron);
  

  // IMPORTANT
  // TODO
  // VERY HACKY FIX
  // Because neirons point to item in vector, if vector resized when new items
  // added everything goes wrong and now pointing at garbage memory
  // get a seg fault
  // need a fundamental rewrite of neuron system
  mHiddenNeurons.reserve(20);
  mOutputNeurons.reserve(20);
}

void AI::printNeurons(void){
  std::cout << "Input neurons: ";
  for (int i = 0; i < mInputNeurons.size(); i++){
    std::cout << mInputNeurons.at(i).mID << " ";
  }
  std::cout << std::endl;

  std::cout << "Hidden neurons: \r\n";
  for (int i = 0; i < mHiddenNeurons.size(); i++){
    std::cout << mHiddenNeurons.at(i).mID << ":" << std::endl;
    for (int j = 0; j < mHiddenNeurons.at(i).mInputs.size(); j++){
      std::cout << mHiddenNeurons.at(i).mInputs.at(j)->mID << " ";
    }
    std::cout << std::endl;    
  }
  std::cout << std::endl;

  std::cout << "Output neurons: \r\n";
  for (int i = 0; i < mOutputNeurons.size(); i++){
    std::cout << mOutputNeurons.at(i).mID << ":" << std::endl;
    for (int j = 0; j < mOutputNeurons.at(i).mInputs.size(); j++){
      std::cout << mOutputNeurons.at(i).mInputs.at(j)->mID << " ";
    }
    std::cout << std::endl;    
  }
  std::cout << std::endl;
}

int AI::addOutput(bool *output){
  // mOutputs.push_back(output);
  mOutputNeurons.push_back(OutputNeuron(output));
  mOutputNeurons.back().mThreshold = 0;
  return mOutputNeurons.back().mID;
}

void AI::addOutputHiddenNeuron(int outputID, int inputID1, double weight1, int inputID2, double weight2){
  for (int i = 0; i < mOutputNeurons.size(); i++){
    if(mOutputNeurons.at(i).mID == outputID){
      HiddenNeuron tempHiddenNeuron;
      tempHiddenNeuron.addInput(&mInputNeurons.at(inputID1), weight1);
      tempHiddenNeuron.addInput(&mInputNeurons.at(inputID2), weight2);
      tempHiddenNeuron.mThreshold = 0;
      mHiddenNeurons.push_back(tempHiddenNeuron);
      mOutputNeurons.at(i).addInput(&(mHiddenNeurons.at(mHiddenNeurons.size() - 1)), 1);
    }
  }
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
  // for (int i = 0; i < mOutputs.size(); i++){
  //   (* mOutputs.at(i)) = bool(rand()%2);
  // }

  
  for (int i = 0; i < mOutputNeurons.size(); i++){
    mOutputNeurons.at(i).updateOutputs();
  }

  // if platform abovetot the left move left else move right
  // if(mHiddenNeurons.at(0).resolveOutput()>mHiddenNeurons.at(0).mThreshold){
  //   (* mOutputNeurons[0].mOuput) = true;
  //   (* mOutputNeurons[1].mOuput) = false;
  // }else if(mHiddenNeurons.at(0).resolveOutput()<mHiddenNeurons.at(0).mThreshold){
  //   (* mOutputNeurons[0].mOuput) = false;
  //   (* mOutputNeurons[1].mOuput) = true;
  // }else{
  //   (* mOutputNeurons[0].mOuput) = false;
  //   (* mOutputNeurons[1].mOuput) = false;
  // }

  // if ()
}
