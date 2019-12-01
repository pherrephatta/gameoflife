#include "RandomUtil.hpp"

std::random_device RandomUtil::randomDevice;
std::mt19937 RandomUtil::randomGenerator(randomDevice());

bool RandomUtil::generateEvent(double probability)
{
	std::bernoulli_distribution randomDistribution(probability);
	return randomDistribution(randomGenerator);
}

uint8_t RandomUtil::generateChar() {
	std::uniform_int_distribution<int> randomChar(0, 255);
	return randomChar(randomGenerator);
}
