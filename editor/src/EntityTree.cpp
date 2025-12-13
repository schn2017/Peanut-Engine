#include "EntityTree.h"
#include "Property.h"
#include <imgui.h>
#include "misc/cpp/imgui_stdlib.h"
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>
#include <Entity.h>
using json = nlohmann::json;

void EntityTree::drawProperty(Property* property)
{
    ImGui::TableNextRow();
    ImGui::PushID(property->name().c_str());
    ImGui::TableNextColumn();
    ImGui::AlignTextToFramePadding();
    ImGui::TextUnformatted(property->name().c_str());
    ImGui::TableNextColumn();

    switch (property->type()) {
        case (PropertyType::ComboBox): {
            break;
        }
        case (PropertyType::Text): {
            auto textProp = dynamic_cast<TextProperty*>(property);
            ImGui::InputText("##", &textProp->value());
            break;
        }
        case (PropertyType::Int): {
            break;
        }
        case (PropertyType::Float): {
            break;
        }
    }
    
    ImGui::PopID();
}

/*
void EntityTree::drawNode(Node* node) {

    ImGui::TableNextRow();
    ImGui::TableNextColumn();
    ImGui::PushID(node->m_uid);
    ImGuiTreeNodeFlags tree_flags = ImGuiTreeNodeFlags_None;
    tree_flags |= ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick;// Standard opening mode as we are likely to want to add selection afterwards
    tree_flags |= ImGuiTreeNodeFlags_SpanFullWidth;         // Span full width for easier mouse reach
    tree_flags |= ImGuiTreeNodeFlags_NavLeftJumpsBackHere;  // Left arrow support
    tree_flags |= ImGuiTreeNodeFlags_SpanFullWidth;         // Span full width for easier mouse reach
    
    if (m_selectedNode && node->m_uid == m_selectedNode->m_uid)
        tree_flags |= ImGuiTreeNodeFlags_Selected;


    if (node->m_children.size() == 0)
        tree_flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_Bullet;

    bool openNode = ImGui::TreeNodeEx(node->m_name.c_str(), tree_flags);
    if (ImGui::BeginPopupContextItem())
    {
        if (node->m_type == NodeType::EntityNode)
        {
            if (ImGui::MenuItem("Create Component"))
            { 
            }

            if (ImGui::MenuItem("Delete Node"))
            { 
            }
        } else if (node->m_type == NodeType::ComponentNode)
        {
            if (ImGui::MenuItem("Delete Component"))
            { 
            }
        }
        ImGui::EndPopup();
    }

    if (ImGui::IsItemFocused())
        m_selectedNode = node;

    if (openNode)
    {
        for (auto& child : node->m_children)
        {
            drawNode(child);
        }

        ImGui::TreePop();
    }

    ImGui::PopID();
};
*/

EntityTree::EntityTree()
{
    json j = {
        {"m_uid", 123},
        {"m_components", json::array()},
        {"m_properties", json::array()}
    };
    auto test = j.get<Entity>();
    std::cout << "The entity id: " << test.uid() << std::endl;

    json q = {
        {"m_uid", 1},
        {"m_type", PropertyType::Text},
        {"m_name", "Bleh"},
        {"m_defaultValue", "default"}, 
        {"m_value", "actual"}
    };
    auto prop = q.get<TextProperty>();
    std::cout << "The prop id: " << prop.uid() << ". The value is " << prop.value() << std::endl;
}

void EntityTree::draw()
{
    if (ImGui::BeginChild("##tree", ImVec2(300, 0), ImGuiChildFlags_ResizeX | ImGuiChildFlags_Borders | ImGuiChildFlags_NavFlattened | ImGuiTableFlags_ContextMenuInBody))
    {
        ImGui::SetNextItemWidth(-FLT_MIN);
        ImGui::SetNextItemShortcut(ImGuiMod_Ctrl | ImGuiKey_F, ImGuiInputFlags_Tooltip);
        ImGui::PushItemFlag(ImGuiItemFlags_NoNavDefaultFocus, true);
        ImGui::PopItemFlag();

        if (ImGui::BeginTable("##bg", 1, ImGuiTableFlags_RowBg))
        {
            for (auto& node : m_nodes)
            {
                //drawNode(node);
            }

            ImGui::EndTable();
        }
        if (ImGui::IsWindowHovered(ImGuiHoveredFlags_AllowWhenBlockedByPopup)
            && !ImGui::IsAnyItemHovered()
            && ImGui::IsMouseReleased(ImGuiMouseButton_Right))
        {
            ImGui::OpenPopup("table_context_menu");
        }

        // The actual popup
        if (ImGui::BeginPopup("table_context_menu"))
        {
            if (ImGui::MenuItem("Create Entity"))
            { 
                // Delete Entity
            }
            ImGui::EndPopup();
        }
        
    }

    ImGui::EndChild();

    ImGui::SameLine();

    ImGui::BeginGroup(); // Lock X position
    if (m_selectedNode) {
        /*

        ImGui::Text("%s", m_selectedNode->m_name.c_str());
        ImGui::TextDisabled("UID: 0x%08X", m_selectedNode->m_uid);
        ImGui::Separator();
        if (ImGui::BeginTable("##properties", 2, ImGuiTableFlags_Resizable | ImGuiTableFlags_ScrollY))
        {
        
            // Push object ID after we entered the table, so table is shared for all objects
            ImGui::PushID(m_selectedNode->m_uid);
            ImGui::TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed);
            ImGui::TableSetupColumn("", ImGuiTableColumnFlags_WidthStretch, 2.0f); // Default twice larger

            for (auto& property: m_selectedNode->m_properties) {
                drawProperty(property);
            }

            ImGui::PopID();
            ImGui::EndTable();           
        }
        */
    }
    ImGui::EndGroup();
}
