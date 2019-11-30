#include "RandomUtil.hpp"

std::random_device RandomUtil::randomDevice;
std::mt19937 RandomUtil::randomGenerator(randomDevice());
std::uniform_int_distribution<uint8_t> RandomUtil::randomChar(0,255);

bool RandomUtil::generateEvent(double probability)
{
	std::bernoulli_distribution randomDistribution(probability);
	return randomDistribution(randomGenerator);
}

uint8_t RandomUtil::generateChar() {
	return randomChar(randomGenerator);
}
