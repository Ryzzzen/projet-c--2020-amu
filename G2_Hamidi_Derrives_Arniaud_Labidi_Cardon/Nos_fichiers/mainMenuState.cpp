#include <mingl/gui/sprite.h>
#include <mingl/audio/audioengine.h>

#include "state.h"
#include "cooldowns.h"

#include "definitions.h"

/**
 *
 * \file    mainMenuState.cpp
 * \author  Thomas Cardon
 * \date    9 janvier 2021
 * \version 1.0
 * \brief   Main menu state
 */

using namespace nsGame;

class MainMenuState : public State {
    /**
     * @class MainMenuState
     * @brief Defines the main menu
     * @authors Thomas Cardon, Alexandre Arniaud
     */
    public:
        nsAudio::AudioEngine audio;

        nsGui::Sprite background = nsGui::Sprite(RES_PATH + "/gui/background.i2s", nsGraphics::Vec2D(0, 0));

        nsGui::Sprite btn_play = nsGui::Sprite(RES_PATH + "/gui/btn_play.i2s", nsGraphics::Vec2D(409, 432));
        nsGui::Sprite btn_quit = nsGui::Sprite(RES_PATH + "/gui/btn_quit.i2s", nsGraphics::Vec2D(409, 530));
        nsGui::Sprite btn_credits = nsGui::Sprite(RES_PATH + "/gui/btn_credits.i2s", nsGraphics::Vec2D(410, 482));

        nsGui::Sprite btn_play_hover = nsGui::Sprite(RES_PATH + "/gui/btn_play_hover.i2s", nsGraphics::Vec2D(417, 429));
        nsGui::Sprite btn_quit_hover = nsGui::Sprite(RES_PATH + "/gui/btn_quit_hover.i2s", nsGraphics::Vec2D(399, 529));
        nsGui::Sprite btn_credits_hover = nsGui::Sprite(RES_PATH + "/gui/btn_credits_hover.i2s", nsGraphics::Vec2D(401, 478));

        nsGui::Sprite appuyer_a = nsGui::Sprite(RES_PATH + "/gui/appuyer_a.i2s", nsGraphics::Vec2D(0, 0));

        bool canMove = true;
        int hovering = -1;

        void load() override {
            Cooldowns::createCooldown("mainMenu_move", 500);

            audio.loadSound(RES_PATH + "/audio/button-select.wav");
            audio.loadSound(RES_PATH + "/audio/button-click.wav");
        }

        void events(nsEvent::Event_t event) override {
            std::cout << event.eventType << std::endl;
        }

        void update(MinGL & window, unsigned delta) override {
            if (Cooldowns::isCooldownOver("mainMenu_move")) canMove = true;
            if (!canMove) return;

            if (window.isPressed({ 'a', false })) {
                if (hovering == 0) this->setState(1);
                else if (hovering == 1) this->setState(99);
                else if (hovering == 2) window.stopGaphic();

                audio.playSoundFromBuffer(RES_PATH + "/audio/button-click.wav");
                return;
            }

            if (window.isPressed({ 's', false })) { // UP
                if (hovering == -1 || hovering == 2) hovering = 0;
                else hovering++;
            }
            else if (window.isPressed({ 'z', false })) { // DOWN
                if (hovering == -1 || hovering == 0) hovering = 2;
                else --hovering;
            }
            else return;

            canMove = false;
            audio.playSoundFromBuffer(RES_PATH + "/audio/button-select.wav");
        }

        void render(MinGL & window) override {
            window << background;
            window << appuyer_a;

            window << (hovering == 0 ? btn_play_hover : btn_play);
            window << (hovering == 1 ? btn_credits_hover : btn_credits);
            window << (hovering == 2 ? btn_quit_hover : btn_quit);
        }
};
