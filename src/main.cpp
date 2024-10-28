#include "Config.h"
#include "bEngine/Core/Application.h"
#include "bEngine/Utils/Logger.h"

int main() {

    bEngine::Core::initializeApplication(config_file);

    bEngine::Core::startApplication();

    DEBUG("Application ran until it was closed")

    return 0;
}
