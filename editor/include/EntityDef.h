#pragma once

#include "Property.h"
#include "ComponentDef.h"
#include <nlohmann/json.hpp>

#include "string"
#include <vector>

class EntityDef {
    public:
        EntityDef() {};

        int uid() const { return m_uid; };

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(EntityDef, m_uid, m_components, m_properties);
    private:
        int m_uid = 0;
        std::vector<ComponentDef> m_components;
        std::vector<Property> m_properties;
};