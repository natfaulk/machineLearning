#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>

// TODO Potentially add dedicated output neurons, memory neurons.

class BaseNeuron{
public:
  virtual double resolveOutput(void) = 0;
private:

};

class InputNeuron: public BaseNeuron{
public:
  double resolveOutput(void);
  void updateInput(double inputValue);
private:
  double mInputValue;
};

// class OutputNeuron: public BaseNeuron{
//
// };

class HiddenNeuron: public BaseNeuron{
public:
  double resolveOutput(void);
  void addInput(BaseNeuron *neuron, double weight);
private:
  std::vector<BaseNeuron *> mInputs;
  std::vector<double> mWeights; // between -1 and 1?
};

#endif
