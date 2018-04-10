#include "AImain.hpp"

#include <cstdlib> // rand()

static std::vector<InputNeuron> mInputNeurons;
static std::vector<HiddenNeuron> mHiddenNeurons;
static std::vector<OutputNeuron> mOutputNeurons;

void AI_Init(void){
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
  mInputNeurons.reserve(20);
  mHiddenNeurons.reserve(20);
  mOutputNeurons.reserve(20);
}

void AI_printNeurons(void){
  std::cout << "Input neurons: ";
  for (int i = 0; i < mInputNeurons.size(); i++){
    std::cout << mInputNeurons.at(i).mID.id << " ";
  }
  std::cout << std::endl;

  std::cout << "Hidden neurons: \r\n";
  for (int i = 0; i < mHiddenNeurons.size(); i++){
    std::cout << mHiddenNeurons.at(i).mID.id << ":" << std::endl;
    for (int j = 0; j < mHiddenNeurons.at(i).mInputs.size(); j++){
      std::cout << AI_getNeuronById(mHiddenNeurons.at(i).mInputs.at(j))->mID.id << " ";
    }
    std::cout << std::endl;    
  }
  std::cout << std::endl;

  std::cout << "Output neurons: \r\n";
  for (int i = 0; i < mOutputNeurons.size(); i++){
    std::cout << mOutputNeurons.at(i).mID.id<< ":" << std::endl;
    for (int j = 0; j < mOutputNeurons.at(i).mInputs.size(); j++){
      std::cout << AI_getNeuronById(mOutputNeurons.at(i).mInputs.at(j))->mID.id << " ";
    }
    std::cout << std::endl;    
  }
  std::cout << std::endl;
}

NronId AI_addOutput(bool *output){
  // mOutputs.push_back(output);
  mOutputNeurons.push_back(OutputNeuron(output));
  mOutputNeurons.back().mThreshold = 0;
  return mOutputNeurons.back().mID;
}

void AI_addHiddenNeuron(NronId outputID, std::vector<NronId> &_inputs, std::vector<int> &_weights){
  HiddenNeuron tempHiddenNeuron;
  // output neuron drived from hidden neuron, therefore can still use this fctn with
  // hidden neurons as the output so can have multilevels of hidden neurons
  HiddenNeuron* tempOutputNeuron = (OutputNeuron *)AI_getNeuronById(outputID);

  for (int i = 0; i < _inputs.size(); i++){
    tempHiddenNeuron.addInput(_inputs.at(i), _weights.at(i));
  }
  mHiddenNeurons.push_back(tempHiddenNeuron);
  tempOutputNeuron->addInput(mHiddenNeurons.back().mID, 1);
  // for (int i = 0; i < mOutputNeurons.size(); i++){
  //   if(mOutputNeurons.at(i).mID.id == outputID){
      
  //     tempHiddenNeuron.addInput(&mInputNeurons.at(inputID1), weight1);
  //     tempHiddenNeuron.addInput(&mInputNeurons.at(inputID2), weight2);
  //     tempHiddenNeuron.mThreshold = 0;
  //     mHiddenNeurons.push_back(tempHiddenNeuron);
  //     mOutputNeurons.at(i).addInput(&(mHiddenNeurons.at(mHiddenNeurons.size() - 1)), 1);
  //   }
  // }
}

// void AI::updateOutputs(void){
//   for (int i = 0; i < mOutputs.size(); i++){
//     (* mOutputs.at(i)) = bool(rand()%2);
//   }
// }

// TODO add platform widths as an input
void AI_updateOutputs(const std::vector<Platform>& platforms, const Character& character){

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

BaseNeuron* AI_getNeuronById(NronId _id){
  if (_id.type == NEURON_INPUT){
    for (int i = 0; i < mInputNeurons.size(); i++){
      if (mInputNeurons[i].mID.id == _id.id) return &mInputNeurons[i];
    }
  } else if (_id.type == NEURON_HIDDEN){
    for (int i = 0; i < mHiddenNeurons.size(); i++){
      if (mHiddenNeurons[i].mID.id == _id.id) return &mHiddenNeurons[i];
    }
  } else if (_id.type == NEURON_OUTPUT){
    for (int i = 0; i < mOutputNeurons.size(); i++){
      if (mOutputNeurons[i].mID.id == _id.id) return &mOutputNeurons[i];
    }
  }

  // if reaches here have been given something wrong
  throw "ERROR: Tried to get invalid neuron";
}
