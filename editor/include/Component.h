#pragma once

class ComponentBleh {
    public: 
        ComponentBleh() {};
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(ComponentBleh, m_uid);
    private:
        int m_uid = 0;
};