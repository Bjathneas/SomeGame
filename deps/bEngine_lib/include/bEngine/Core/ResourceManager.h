///
/// \file ResourceManager.h
/// \brief Defines logic for storing global variables
/// \author Benajah Baskin
/// \date 10/23/24
///

#ifndef GAME_RESOURCEMANAGER_H
#define GAME_RESOURCEMANAGER_H

#include <any>
#include <stdexcept>
#include <string>
#include <unordered_map>

namespace bEngine::Core {
    ///
    /// \brief A map of resources by their name to their value
    ///
    std::unordered_map<std::string, std::any> resources;

    ///
    /// \brief Set a resource's name and value
    /// \tparam T The type of the resource
    /// \param key The name of the resource
    /// \param value The value of the resource
    ///
    template<typename T>
    [[maybe_unused]] void set(const std::string& key, const T& value) {
        resources[key] = value;
    }

    ///
    /// \brief Get a resource according to its type -> little to no type validation
    /// \tparam T The type of the resource being requested
    /// \param key The name of the resource being requested
    /// \return The value of the resource
    ///
    template<typename T>
    [[maybe_unused]] T get(const std::string& key) {
        auto iterator = resources.find(key);
        if (iterator != resources.end()) {
            try {
                return std::any_cast<T>(iterator->second);
            } catch (const std::bad_any_cast&) {
                throw std::runtime_error("Bad Resource Type Cast");
            }
        }

        throw std::runtime_error("Resource does not exist");
    }

    ///
    /// \brief Remove a resource from the manager
    /// \param key The name of the resource
    ///
    [[maybe_unused]] inline void remove(const std::string& key) { resources.erase(key); }
}// namespace bEngine::Core

#endif//GAME_RESOURCEMANAGER_H
