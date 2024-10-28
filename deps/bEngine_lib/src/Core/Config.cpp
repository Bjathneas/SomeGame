//
// Created by benajah on 10/23/24.
//

#include "bEngine/Core/Config.h"

#include <cassert>

namespace bEngine::Core {

    std::unordered_map<std::string, std::unordered_map<std::string, int>> type_map;

    std::unordered_map<std::string, int> type_reference;

    std::unordered_map<std::string, std::unordered_map<std::string, std::variant<int, std::string>>> values;

    toml::table toml_default;

    void load_config( const std::filesystem::path& config_file_path ) {
        type_reference[ "int" ] = typeid( int ).hash_code();           // NOLINT(*-narrowing-conversions)
        type_reference[ "string" ] = typeid( std::string ).hash_code();// NOLINT(*-narrowing-conversions)

        toml_default = toml::parse_file( config_file_path.c_str() );
    }

    void load_config( std::string_view config ) {
        type_reference[ "int" ] = typeid( int ).hash_code();           // NOLINT(*-narrowing-conversions)
        type_reference[ "string" ] = typeid( std::string ).hash_code();// NOLINT(*-narrowing-conversions)

        toml_default = toml::parse( config );
    }

    int get_int( const std::string& variable, const std::string& table ) {
        // TODO HANDLE error for unregistered variables and request for wrong types
        // Making sure you didn't ask for an int but actually wanted a string.
        // If you did, well... too bad. Error-handling is for the weak.
        assert( type_map[ table ][ variable ] == type_reference[ "int" ] );
        return std::get<int>( values[ table ][ variable ] );
    }

    std::string get_string( const std::string& variable, const std::string& table ) {
        // If this assert fails, congrats. You messed up and tried to grab a string out of a rock.
        assert( type_map[ table ][ variable ] == type_reference[ "string" ] );
        return std::get<std::string>( values[ table ][ variable ] );
    }
}// namespace bEngine::Core