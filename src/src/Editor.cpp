#include "Editor.h"

#include <imgui-SFML.h>
#include <imgui.h>
#include "spdlog/spdlog.h"

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

        ImGui::ShowDemoWindow();
        
        m_window.clear();
        ImGui::SFML::Render(m_window);
        m_window.display();
    }

    ImGui::SFML::Shutdown();


}