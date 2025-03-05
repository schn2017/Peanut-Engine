#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

class Editor
{
public: 
    Editor();

    void process();

private:
    sf::RenderWindow m_window;
    sf::Clock m_deltaClock;
};