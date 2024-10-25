#include "bEngine/Core/Application.h"
#include "bEngine/Utils/Logger.h"

int main() {
    bEngine::Core::initializeApplication(std::filesystem::path("/home/benajah/CLionProjects/Game/config.toml"));
    bEngine::Core::startApplication();

    DEBUG("Application ran until it was closed")

    return 0;
}
