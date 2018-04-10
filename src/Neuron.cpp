#include "Neuron.hpp"
#include "AImain.hpp"

static int neuronId = 0;

BaseNeuron::BaseNeuron(){
  mID.id = neuronId++;
  mID.type = NEURON_BASE;
}

HiddenNeuron::HiddenNeuron(){
  mID.type = NEURON_HIDDEN;  
}

// TODO cache this as there may be multiple recursive calls to it per tick
double HiddenNeuron::resolveOutput(void){
  double tempOutput = 0;
  for (int i = 0; i < mInputs.size(); i++){
    // TODO
    // Need to work on the resolving method (look up fuzzy logic again)
    // Maybe multiply all the inputs together
    tempOutput += (AI_getNeuronById(mInputs.at(i))->resolveOutput() * mWeights.at(i));
    // tempOutput += (mInputs.at(i)->resolveOutput() * mWeights.at(i));
  }
  // divide by number of inputs?
  return tempOutput;
}

void HiddenNeuron::addInput(NronId neuron, double weight){
  mInputs.push_back(neuron);
  mWeights.push_back(weight);
}

InputNeuron::InputNeuron(){
  mID.type = NEURON_INPUT;  
}

double InputNeuron::resolveOutput(void){
  return mInputValue;
}

void InputNeuron::updateInput(double inputValue){
  mInputValue = inputValue;
}

OutputNeuron::OutputNeuron(bool* _output){
  mID.type = NEURON_OUTPUT;  
  mOuput = _output;
}

void OutputNeuron::updateOutputs(void){
  if (resolveOutput() > mThreshold){
    (* mOuput) = true;
  } else {
    (* mOuput) = false;
  }
}