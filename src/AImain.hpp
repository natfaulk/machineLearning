#ifndef AI_MAIN_HPP
#define AI_MAIN_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Neuron.hpp"
#include "character.hpp"
#include "platform.hpp"


void AI_Init(void);
// inputs ie game outputs
// outputs ie inputs
// set outputs, returns id of output
NronId AI_addOutput(bool *output);
// curently random number generation
void AI_updateOutputs(const std::vector<Platform>& platforms, const Character& character);

void AI_addHiddenNeuron(NronId outputID, std::vector<NronId> &_inputs, std::vector<int> &_weights);  

void AI_printNeurons(void);

BaseNeuron* AI_getNeuronById(NronId _id);


#endif
