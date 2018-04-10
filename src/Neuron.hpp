#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>

// TODO Potentially add dedicated output neurons, memory neurons.

enum NeuronType {NEURON_BASE, NEURON_INPUT, NEURON_HIDDEN, NEURON_OUTPUT};

struct NronId{
  int id;
  NeuronType type;
};

class BaseNeuron{
public:
  BaseNeuron();
  virtual double resolveOutput(void) = 0;
  NronId mID;
private:

};

class InputNeuron: public BaseNeuron{
public:
  InputNeuron();
  double resolveOutput(void);
  void updateInput(double inputValue);
private:
  double mInputValue;
};

class HiddenNeuron: public BaseNeuron{
public:
  HiddenNeuron();
  double resolveOutput(void);
  void addInput(NronId neuron, double weight);
  std::vector<NronId> mInputs;
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
