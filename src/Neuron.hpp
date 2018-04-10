#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>

// TODO Potentially add dedicated output neurons, memory neurons.

class BaseNeuron{
public:
  BaseNeuron();
  virtual double resolveOutput(void) = 0;
  int mID;
private:

};

class InputNeuron: public BaseNeuron{
public:
  double resolveOutput(void);
  void updateInput(double inputValue);
private:
  double mInputValue;
};

class HiddenNeuron: public BaseNeuron{
public:
  double resolveOutput(void);
  void addInput(BaseNeuron *neuron, double weight);
  std::vector<BaseNeuron *> mInputs;
  std::vector<double> mWeights; // between -1 and 1?
  double mThreshold;
private:
};

class OutputNeuron: public HiddenNeuron{
public:
  OutputNeuron(bool* _output);
  void updateOutputs(void);
  bool* mOuput;
};
#endif
