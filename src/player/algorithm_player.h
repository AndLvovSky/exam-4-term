#ifndef ALGORITHM_PLAYER_H
#define ALGORITHM_PLAYER_H

#include "runner/algorithm_runner.h"
#include "visualization/visualizator.h"

/**
 * @brief The AlgorithmPlayer class used for transfering algorithm events from
 * AlgorithmRunner to Visulizator.
 *
 * The AlgorithmPlayer class keeps injected AlgorithmRunner and Visulizator
 * (pattern Dependency injection) and implements functionality of media player.
 */
template <typename Structure>
class AlgorithmPlayer {

    AlgorithmRunner<Structure>& runner;

    Visualizator<Structure>& visualizator;

public:

    AlgorithmPlayer(AlgorithmRunner<Structure>& runner,
        Visualizator<Structure>& visualizator);

    /**
     * Transfers algorithm events to the visualizator with specified pause
     * until the last event.
     */
    void play(int pause = 0);

};

#include "algorithm_player.tpp"

#endif // ALGORITHM_PLAYER_H
