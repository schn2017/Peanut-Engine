#pragma once

#include <vector>
#include <string>
#include <utility>

enum PropertyType {
    Text,
    Int,
    Float,
    ComboBox
};

class Property {
    public:
        Property(PropertyType type, std::string name)
            :m_name(name),
            m_type(type)
        {
        };

        virtual ~Property() = default;

        std::string name() { return m_name; };
        PropertyType type() { return m_type; };

    private:
       PropertyType m_type;
       std::string m_name;
       int m_uid;
};

class TextProperty : public Property {
    public:
        TextProperty(std::string name):
            Property(PropertyType::Text, name){
        };

        void setValue(std::string newValue) {
            m_value = newValue;
        }
        std::string& value() { return m_value; };
        std::string defaultValue() { return m_defaultValue; };

    private:
        std::string m_defaultValue;
        std::string m_value;
};

class ComboBoxProperty : public Property {
    public: 
        ComboBoxProperty(std::string name):
            Property(PropertyType::ComboBox, name) {
        
        };
    private:
        std::string m_defaultValue;
        std::string m_value;
        std::vector<std::pair<std::string, std::string>> m_options; 
};

class IntProperty : public Property {
    public:
        IntProperty(std::string name):
            Property(PropertyType::Int, name) {
        };
    private:
        int m_defaultValue;
        int m_value;
};