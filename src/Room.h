#ifndef GAME_ROOM_H
#define GAME_ROOM_H

#include <SFML/Graphics/Color.hpp>

#include <map>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Rock.h"
#include "Hole.h"
#include "Chest.h"
#include "Wall.h"
#include "Door.h"
#include "Hatch.h"
#include "Projectile.h"

class Room : public sf::Drawable{

public:

    enum Type{

        Common = 0,
        Start,
        CommonStart,
        Boss,
        Boost,
        N,
        E,
        S,
        W,
        NS1,
        NS2,
        WE1,
        WE2,
        NE,
        ES,
        SW,
        NW,
        NES,
        ESW,
        NSW,
        NEW,
        NESW1,
        NESW2,
        None
    };

    enum class Tile{

        Nothing = 0,
        Hole,
        Rock,
        Chest,
        Boost
    };

public:

    Room() = delete;
    Room(TextureManager*, Type roomType = Type::Common);
    ~Room();

public: // Functions
    
    void setType(Type roomType);

    Type getType() const;

    void addDoor(const Orientation &orient, const Door::State &state = Door::State::Closed);

    void affectType(unsigned seed);
    
    void placeTiles();
    
    std::pair<Entity::Type, Orientation> checkRoomCollisions(Entity&);
    
    void checkMonsterCollisions(Entity&);

    Entity::Type checkProjectileCollisions(Entity&);

    void update(sf::Time);
    
    void openDoors();

    void closeDoors();

    void addProjectile(Projectile *proj);

    void deleteProjectiles();

private:

    std::string getTilesPath(int roomId); // return Room path witch type corresponding

    void placeWalls();

    int returnStoi(std::istringstream &ss);

    void draw(sf::RenderTarget&, sf::RenderStates) const override;
    
private: // Variables
    
    sf::Sprite background;
    sf::Color color;
    
    std::vector<std::unique_ptr<Door>> doors;
    std::vector<std::unique_ptr<Wall>> walls;
    std::vector<std::unique_ptr<Hole>> holes;
    std::vector<std::unique_ptr<Rock>> rocks;
    std::vector<std::unique_ptr<Chest>> chests;
    std::vector<std::unique_ptr<Hatch>> hatchs;
    std::vector<std::unique_ptr<Projectile>> projectiles;

    Type type;
    
    TextureManager* textureMgr;
};

#endif
