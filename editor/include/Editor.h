#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

#include "EntityTree.h"

class Editor
{
public: 
    Editor();

    void process();

private:
    sf::RenderWindow m_window;
    sf::Clock m_deltaClock;
    EntityTree m_entityTree;
};