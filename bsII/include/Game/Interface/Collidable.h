#ifndef HITTABLE_H
#define HITTABLE_H

#include "Traits/Traits.h"

#include "Game/Interface/Drawable.h"

namespace BrickShooter
{
    class Collidable : public Drawable
    {
    public:
        ~Collidable() override = default;

        virtual void collide(int damage) = 0;

        virtual bool isDead() = 0;
    };
} // namespace BrickShooter

#endif
