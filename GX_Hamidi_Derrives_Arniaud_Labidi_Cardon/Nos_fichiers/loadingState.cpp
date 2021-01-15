#include "mingl/gui/sprite.h"
#include "state.h"

/**
 *
 * \file    loadingState.cpp
 * \author  Thomas Cardon
 * \date    10 janvier 2020
 * \version 1.0
 * \brief   Loading state
 */

using namespace nsGame;

class LoadingState : public State {
    /**
     * @class LoadingState
     * @brief Defines the loading state
     * @author Thomas Cardon
     */
    public:
        void load() {}

        void update(MinGL & window, unsigned delta) {

        }

        void render(MinGL & window) {
            window.setBackgroundColor(nsGraphics::KCyan);
        }
};
