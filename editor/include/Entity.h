#pragma once

#include "Component.h"
#include <nlohmann/json.hpp>

#include "string"
#include <vector>

/*
using json = nlohmann::json;

class NodeBleh {

};

class PropertyBleh {
    public:
        PropertyBleh(std::string name)
            :m_name(name) {

        };
        //NLOHMANN_DEFINE_TYPE_INTRUSIVE(PropertyBleh, m_name);

    private:
       std::string m_name = "";
};
*/

class Entity {
    public:
        Entity() {};

        int uid() const { return m_uid; };

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Entity, m_uid, m_components);
    private:
        int m_uid = 0;
        std::vector<Component> m_components;
};