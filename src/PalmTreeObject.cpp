/*
 * File:   PalmTreeObject.cpp
 * Author: jamie
 *
 * Created on 06 January 2012, 01:26
 */

#include "PalmTreeObject.hpp"

#include <Tank/Graphics/Image.hpp>
#include "MainWorld.hpp"
#include "Tile.hpp"

PalmTreeObject::PalmTreeObject(tank::Vectorf pos)
    : Object(pos)
{
    makeGraphic<tank::Image>(MainWorld::palmtree);
    tank::Rectd hb = { 30, static_cast<double>(Tile::TILE_SIZE) * 2 - 4, 16, 6 };
    hb.y -= hb.h;
    setHitbox(hb);

    setType("solid");
}
