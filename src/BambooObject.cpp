#include "BambooObject.hpp"

#include "Engine/System/State.hpp"
#include "Engine/Graphics/Text.hpp"
#include "Tile.hpp"

BambooObject::BambooObject(Vectorf const& pos)
:Object( pos, "bamboo" ),
 _anim(_texture, { static_cast<float>(Tile::TILE_SIZE), 
                   static_cast<float>(Tile::TILE_SIZE) })
{
    _hitbox.x = 14;
    _hitbox.w = 24;
    _hitbox.y = 42;
    _hitbox.h = 8;
    _solid = true;
    _type = "bamboo";

    _anim.add("normal", {0}, 0);
    _anim.add("taken",  {1}, 0);
    _anim.select("normal",false); 
}

void BambooObject::update()
{
    if(!collide("player").empty())
    {
        _anim.select("taken",false);
        _type  = "bamboo_taken";
        if(_solid)
        {
            _state->addEntity(new Text({50,600},
                                       "You found some bamboo!",
                                       1000));
            _solid = false;
        }
    }
}

void BambooObject::draw(IRender* render)
{
    _anim.draw(render, _pos);
}
