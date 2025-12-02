#include "Editor.h"

#include <imgui-SFML.h>
#include <imgui.h>
#include "spdlog/spdlog.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

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
        if(ImGui::TreeNode("Howdy")) {
            for (int i = 0; i < 5; i++)
            {
                // Use SetNextItemOpen() so set the default state of a node to be open. We could
                // also use TreeNodeEx() with the ImGuiTreeNodeFlags_DefaultOpen flag to achieve the same thing!
                if (i == 0)
                    ImGui::SetNextItemOpen(true, ImGuiCond_Once);

                // Here we use PushID() to generate a unique base ID, and then the "" used as TreeNode id won't conflict.
                // An alternative to using 'PushID() + TreeNode("", ...)' to generate a unique ID is to use 'TreeNode((void*)(intptr_t)i, ...)',
                // aka generate a dummy pointer-sized value to be hashed. The demo below uses that technique. Both are fine.
                ImGui::PushID(i);
                if (ImGui::TreeNode("", "Child %d", i))
                {
                    ImGui::Text("blah blah");
                    ImGui::SameLine();
                    if (ImGui::SmallButton("button")) {}
                    ImGui::TreePop();
                }
                ImGui::PopID();
            }
            ImGui::TreePop();
        }
        
        m_window.clear();
        ImGui::SFML::Render(m_window);
        m_window.display();
    }

    ImGui::SFML::Shutdown();


}