#include "algorithm_player.h"
#include <thread>
#include <chrono>

template <typename Structure>
AlgorithmPlayer<Structure>::AlgorithmPlayer(
    AlgorithmRunner<Structure>& runner,
    Visualizator<Structure>& visualizator) :
    runner(runner), visualizator(visualizator) {
}

template <typename Structure>
void AlgorithmPlayer<Structure>::play(int pause) {
    while(runner.hasNext()) {
        visualizator.visualize(runner.stepForward());
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    }
}
