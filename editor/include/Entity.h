#pragma once

#include "Component.h"
#include <nlohmann/json.hpp>

#include "string"
#include <vector>

class Entity {
    public:
        Entity() {};

        int uid() const { return m_uid; };

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Entity, m_uid, m_components, m_properties);
    private:
        int m_uid = 0;
        std::vector<Component> m_components;
        std::vector<Property> m_properties;
};