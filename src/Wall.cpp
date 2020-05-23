#include "Wall.h"

/****************
 * Constructors *
 ****************/
Wall::Wall():
        Entity(nullptr, Type::Wall),
        left(collisionBox.left),
        top(collisionBox.top),
        width(collisionBox.width),
        height(collisionBox.height){}

Wall::Wall(float x, float y, float dx, float dy):
        Entity(nullptr, Type::Wall),
        left(collisionBox.left),
        top(collisionBox.top),
        width(collisionBox.width),
        height(collisionBox.height){
    
    left = x;
    top = y;
    width = dx;
    height = dy;
}

Wall::Wall(sf::FloatRect hitBox):
        Entity(nullptr, Type::Wall),
        left(collisionBox.left),
        top(collisionBox.top),
        width(collisionBox.width),
        height(collisionBox.height){
            
    collisionBox = hitBox;
}

/********
 * Draw *
 ********/
void Wall::draw(sf::RenderTarget& target, sf::RenderStates states) const{}
