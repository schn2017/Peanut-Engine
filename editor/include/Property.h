#pragma once

#include <vector>
#include <string>
#include <utility>

#include <nlohmann/json.hpp>

enum PropertyType {
    Text,
    Int,
    Float,
    ComboBox
};

class Property {
    public:
        Property() {};

        Property(PropertyType type, std::string name)
            :m_name(name),
            m_type(type)
        {
        };

        virtual ~Property() = default;

        int uid() { return m_uid; };
        std::string name() { return m_name; };
        PropertyType type() { return m_type; };

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Property, m_uid, m_type, m_name);

    private:
       PropertyType m_type;
       std::string m_name;
       int m_uid;
};

class TextProperty : public Property {
    public:
        TextProperty() : Property(PropertyType::Text, "") {}

        TextProperty(std::string name):
            Property(PropertyType::Text, name) {
        };

        void setValue(std::string newValue) {
            m_value = newValue;
        }
        std::string& value() { return m_value; };
        std::string defaultValue() { return m_defaultValue; };

        NLOHMANN_DEFINE_DERIVED_TYPE_INTRUSIVE(TextProperty, Property, m_defaultValue, m_value);
    private:
        std::string m_defaultValue;
        std::string m_value;
};

class ComboBoxProperty : public Property {
    public: 
        ComboBoxProperty(std::string name):
            Property(PropertyType::ComboBox, name) {
        };

        NLOHMANN_DEFINE_DERIVED_TYPE_INTRUSIVE(ComboBoxProperty, Property, m_defaultValue, m_value, m_options);

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

        NLOHMANN_DEFINE_DERIVED_TYPE_INTRUSIVE(IntProperty, Property, m_defaultValue, m_value);

    private:
        int m_defaultValue;
        int m_value;
};