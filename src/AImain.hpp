#ifndef AI_MAIN_HPP
#define AI_MAIN_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Neuron.hpp"
#include "character.hpp"
#include "platform.hpp"

class AI{
public:
  AI();
  // inputs ie game outputs
  // outputs ie inputs
  // set outputs
  void addOutput(bool *output);
  // curently random number generation
  void updateOutputs(const std::vector<Platform>& platforms, const Character& character);
private:
  // pass the AI pointers to bools which can then be checked by the game
  // seems a very C way of doing it (as opposed to a C++ way) however the ideal
  // would be to use references but one cannot have a vector of references
  std::vector<bool *> mOutputs;

  // Neurons
  std::vector<InputNeuron> mInputNeurons;
  std::vector<HiddenNeuron> mOutputNeurons;
  std::vector<HiddenNeuron> mHiddenNeurons;
};

#endif
