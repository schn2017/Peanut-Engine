#pragma once

class Component {
    public: 
        Component() {};
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Component, m_uid);
    private:
        int m_uid = 0;
};