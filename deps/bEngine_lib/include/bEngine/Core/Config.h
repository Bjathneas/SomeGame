//
// Created by benajah on 10/23/24.
//

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

    extern std::unordered_map<std::string, std::unordered_map<std::string, int>> type_map;

    extern std::unordered_map<std::string, int> type_reference;

    extern std::unordered_map<std::string, std::unordered_map<std::string, std::variant<int, std::string>>> values;

    extern toml::table toml_default;

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

    template<typename T>
    void register_variable(const std::string &variable, const std::variant<int, std::string> &default_value,
                           const std::string &table = "toml_default") {
        type_map[table][variable] = typeid(T).hash_code();

        //load value from config file

        if (type_map[table][variable] == type_reference["int"])
            load_value_from_toml<int>(variable, std::get<int>(default_value), table);
        else if (type_map[table][variable] == type_reference["string"])
            load_value_from_toml<std::string>(variable, std::get<std::string>(default_value), table);
        else
            ERROR(std::string("The type for " + table + "." + "variable" + " is not supported").c_str())
    }

    void load_config(const std::filesystem::path &config_file_path);
    void load_config(std::string_view config);

    int get_int(const std::string &variable, const std::string &table = "toml_default");

    std::string get_string(const std::string &variable, const std::string &table = "toml_default");


}// namespace bEngine::Core

#endif//GAME_CONFIG_H
