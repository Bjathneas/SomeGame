//
// Created by benajah on 10/23/24.
//

#ifndef GAME_RESOURCEMANAGER_H
#define GAME_RESOURCEMANAGER_H

#include <any>
#include <stdexcept>
#include <string>
#include <unordered_map>

namespace bEngine::Core {
    std::unordered_map<std::string, std::any> resources;

    template<typename T>
    [[maybe_unused]] void set(const std::string& key, const T& value) {
        resources[key] = value;
    }

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

    [[maybe_unused]] inline void remove(const std::string& key) { resources.erase(key); }
}// namespace bEngine::Core

#endif//GAME_RESOURCEMANAGER_H
