#ifndef LOGIC_H
#define LOGIC_H

/**
 *
 * @file    player.h
 * @author  Thomas Cardon
 * @date    8 janvier 2020
 * @version 1.0
 * @brief   Player
 *
 **/

#include <mingl/mingl.h>
#include "type.h"

namespace nsGame {
    /**
     * @class Logic
     * @brief Une classe pour différencier les divers états de jeu (dans les menu, en partie, etc.)
     * @author  Thomas Cardon
     */
    class Player {
        public:
            CPosition pos;
            std::string texture;

            Player() {
                this->texture = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile027.i2s";
            }

            Player(std::string texture) {
                this->texture = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/" + texture;
            }

            /**
             * @brief Loads player
             * @fn void load();
             */
            void load();

            /**
             * @brief Updates player
             * @fn int update(MinGL & window);
             */
            int update(MinGL & window);

            /**
             * @brief Renders resources
             * @fn void render(MinGL & window);
             */
            void render(MinGL & window);
    };
}

#endif // LOGIC_H