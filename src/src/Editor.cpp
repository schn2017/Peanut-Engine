#include "Editor.h"
#include <SFML/Graphics.hpp>

#include <imgui-SFML.h>
#include <imgui.h>
#include "spdlog/spdlog.h"
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;

#include <unistd.h>
#include <limits.h>
inline std::string getWorkingDirectory()
{
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != nullptr)
        return std::string(cwd) + std::string("/") + std::string("resources/");

    return "";
}

Editor::Editor()
    :m_window(sf::VideoMode({1280, 720}), "Editor")
{
    spdlog::info("Creating to Editor!");

    m_window.setFramerateLimit(60);
    ImGui::SFML::Init(m_window);
}

void Editor::process()
{
    while (m_window.isOpen())
    {
        while (const std::optional event = m_window.pollEvent()) 
        {
            ImGui::SFML::ProcessEvent(m_window, *event);
            if (event->is<sf::Event::Closed>())
                m_window.close();
        }

        ImGui::SFML::Update(m_window, m_deltaClock.restart());
        
        sf::Texture coin;
        coin.loadFromFile(getWorkingDirectory() + "sprites/coin.png");

        std::cout << coin.getSize().x << ", " << coin.getSize().y << std::endl;

        sf::Sprite coinSprite(coin, sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(20, 20))); 
        /*
        m_window.draw(coinSprite);

        sf::Texture knight;
        coin.loadFromFile(getWorkingDirectory() + "sprites/knight.png");

        sf::Sprite knightSprite(coin, sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(20, 20))); 
        m_window.draw(knightSprite);
        */

        ImGui::Image(coinSprite);
        ImGui::ShowDemoWindow();
        m_window.clear();
        ImGui::SFML::Render(m_window);
        m_window.display();
    }

    ImGui::SFML::Shutdown();


}