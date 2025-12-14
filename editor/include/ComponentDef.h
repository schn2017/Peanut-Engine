#pragma once

class ComponentDef {
    public: 
        ComponentDef() {};
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(ComponentDef, m_uid);
    private:
        int m_uid = 0;
};