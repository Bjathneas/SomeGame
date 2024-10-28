///
/// \file Config.h
/// \brief Definitions Config file loading from TOML format
/// \author Benajah Baskin
/// \date 10/23/24
///

/*
 * Load registered variables from a toml config file
 * Store the variables with their types to allow for
 * quick validation of a variables type when returned
 */

#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H

#include <filesystem>
#include <string>
#include <toml++/toml.hpp>
#include <typeinfo>
#include <unordered_map>
#include <variant>

#include "bEngine/Utils/Logger.h"

namespace bEngine::Core {
    /*
     * The structure of the type map allows for the ability to query the toml config file
     *
     * [Application]
     * width = 100
     * height = 200
     * title = "Test"
     *
     * type_map["Application"]["width"] -> return type for Application.width in toml
     */

    ///
    /// \brief Store each variable in toml with its type for validation
    ///
    extern std::unordered_map<std::string, std::unordered_map<std::string, int>> type_map;

    ///
    /// \brief Reference of types for quicker validation
    ///
    extern std::unordered_map<std::string, int> type_reference;

    ///
    /// \brief Store each variable and its value with quick searching
    ///
    extern std::unordered_map<std::string, std::unordered_map<std::string, std::variant<int, std::string>>> values;

    ///
    /// \brief The loaded TOML file
    ///
    extern toml::table toml_default;

    ///
    /// \brief Store variable in values map
    /// \tparam T The type of variable being read
    /// \param variable The name of the variable being stored
    /// \param default_value The default value of the variable if not found in toml
    /// \param table The table that the variable is located under in toml file
    /// \see bEngine::Core::register_variable
    ///
    template<typename T>
    void load_value_from_toml(const std::string &variable, const T &default_value,
                              const std::string &table = "toml_default") {
        try {
            if (table != "toml_default")
                values[table][variable] = toml_default[table][variable].value<T>().value();
            else
                values[table][variable] = toml_default[variable].value<T>().value();
        } catch (std::bad_optional_access &) {
            values[table][variable] = default_value;
        }
    }

    ///
    /// \brief Store variable's type in type_map and load it from toml file
    /// \tparam T The variable's type
    /// \param variable The name of the variable being registered and loaded
    /// \param default_value The default value of the variable if not found in toml
    /// \param table The table that the variable is located under in toml
    ///
    template<typename T>
    void register_variable(const std::string &variable, const std::variant<int, std::string> &default_value,
                           const std::string &table = "toml_default") {
        // store variable type for future validation
        type_map[table][variable] = typeid(T).hash_code();

        // load variable from config file according to its type
        if (type_map[table][variable] == type_reference["int"])
            load_value_from_toml<int>(variable, std::get<int>(default_value), table);
        else if (type_map[table][variable] == type_reference["string"])
            load_value_from_toml<std::string>(variable, std::get<std::string>(default_value), table);
        else
            ERROR(std::string("The type for " + table + "." + "variable" + " is not supported").c_str())
    }

    ///
    /// \brief Initialize config and load the toml file from path
    /// \param config_file_path The path of the toml file to load as config
    ///
    void load_config(const std::filesystem::path &config_file_path);
    ///
    /// \brief Initialize config and load the toml from a string
    /// \param config The toml string to load as config
    ///
    void load_config(std::string_view config);

    ///
    /// \brief Validate that the variable is an int and return its value
    /// \param variable The name of the variable being read
    /// \param table The table that the variable is located under
    /// \return The value of the variable
    ///
    int get_int(const std::string &variable, const std::string &table = "toml_default");

    ///
    /// \brief Validate that the variable is a string and return its value
    /// \param variable The name of the variable being read
    /// \param table The table that the variable is located under
    /// \return The value of the variable
    ///
    std::string get_string(const std::string &variable, const std::string &table = "toml_default");
}// namespace bEngine::Core

#endif//GAME_CONFIG_H
