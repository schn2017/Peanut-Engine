#pragma once
#include <vector>
#include "Property.h"
#include "EntityDef.h"

enum NodeType {
    ENTITY,
    COMPONENT
};

class Node {
    public:
        Node(){};
        Node(NodeType node) : m_node(node) {

        }

        // Required interface
        virtual const std::string& name() const = 0;
        virtual int uid() const = 0;

    private:
        NodeType m_node;
};

class ComponentNode : public Node {
    public:
        ComponentNode() : Node(NodeType::COMPONENT) {

        }
        const std::string& name() const override {
            return "";
        }

        int uid() const override {
            return 0;
        }

    private:
        ComponentDef m_component;
};

class EntityNode : public Node {
    public:
        EntityNode() : Node(NodeType::ENTITY) {

        }
        const std::string& name() const override {
            return "";
        }

        int uid() const override {
            return 0;
        }
    private:
        EntityDef m_entity;
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