#ifndef ENTITY_H
#define ENTITY_H

#define CELL_SIZE 32

#include <mingl/graphics/vec2d.h>

#include "map.cpp"

namespace nsGame
{
    /**
     * @class Entity
     * @brief Defines the Entity class
     * @author Thomas Cardon
     */
    class Entity
    {
        public:
            unsigned hearts = 3;
            double movementSpeed = 1.0;

            nsGraphics::Vec2D pos;

            /**
             * @brief This function is used to get the position on the screen/canvas/window, whatever you want to call it
             * @fn virtual nsGraphics::Vec2D getCoordinates();
             */
            virtual nsGraphics::Vec2D getCoordinates();

             /**
              * @brief Gets the coordinates compared to the map.
              * @fn virtual nsGraphics::Vec2D getPosition();
              */
            virtual nsGraphics::Vec2D getPosition();

            /**
             * @brief Checks if entity can be hit by another entity.
             * @fn virtual bool canBeHitBy(Entity entity);
             */
            virtual bool canBeHitBy(Entity entity);

            /**
             * @brief Teleports the entity at its spawn
             */
            virtual void spawn(CMyParam params);
    };
}

#endif // ENTITY_H
