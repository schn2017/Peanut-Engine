#pragma once
#include <vector>
#include "controls/PropertyControl.h"

enum NodeType {
    Entity,
    Component
};

class Node {
public:
    Node(std::string name, int id, NodeType type);

    std::string m_name;
    int m_uid = 0;
    NodeType m_type;

    std::vector<Node*> m_children;
    std::vector<Property*> m_properties;
};

class EntityTree
{
public: 
    EntityTree();

    void draw();

private:
    void loadEntityFiles();
    void getEntities();
    void drawNode(Node* node);
    void drawProperty(Property* property);

    Node* m_selectedNode = nullptr;
    std::vector<Node*> m_nodes;
};