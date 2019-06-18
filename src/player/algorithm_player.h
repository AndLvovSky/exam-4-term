#ifndef ALGORITHM_PLAYER_H
#define ALGORITHM_PLAYER_H

#include "runner/algorithm_runner.h"
#include "visualization/visualizator.h"

template <typename Structure>
class AlgorithmPlayer {

    AlgorithmRunner<Structure>& runner;

    Visualizator<Structure>& visualizator;

public:

    AlgorithmPlayer(AlgorithmRunner<Structure>& runner,
        Visualizator<Structure>& visualizator);

    void play(int pause = 0);

};

#include "algorithm_player.tpp"

#endif // ALGORITHM_PLAYER_H
