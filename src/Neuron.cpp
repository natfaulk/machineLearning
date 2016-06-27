#include "Neuron.hpp"

// TODO cache this as there may be multiple recursive calls to it per tick
double HiddenNeuron::resolveOutput(void){
  double tempOutput = 0;
  for (int i = 0; i < mInputs.size(); i++){
    // TODO
    // Need to work on the resolving method (look up fuzzy logic again)
    // Maybe multiply all the inputs together
    tempOutput += (mInputs.at(i)->resolveOutput() * mWeights.at(i));
  }
  // divide by number of inputs?
  return tempOutput;
}

void HiddenNeuron::addInput(BaseNeuron *neuron, double weight){
  mInputs.push_back(neuron);
  mWeights.push_back(weight);
}

double InputNeuron::resolveOutput(void){
  return mInputValue;
}

void InputNeuron::updateInput(double inputValue){
  mInputValue = inputValue;
}
