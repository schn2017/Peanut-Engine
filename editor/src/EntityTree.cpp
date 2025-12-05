#include "EntityTree.h"

#include <imgui.h>

EntityTree::EntityTree()
{
    if (ImGui::TreeNode("Entities"))
    {
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
            if (ImGui::TreeNode("", "Entity %d", i))
            {
                ImGui::Text("Components");
                ImGui::SameLine();
                if (ImGui::SmallButton("button")) {}
                
                ImGui::SameLine();
                ImGui::Text("Shalom");

                ImGui::TreePop();
            }

            ImGui::PopID();
        }
        
        ImGui::TreePop();     
    }
}