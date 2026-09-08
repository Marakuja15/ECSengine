add_executable(ECSengine  "EntityManager.h" "ComponentArray.h"  "ComponentManager.h" "System.h" "SystemManager.h" "Entity.h" "World.h" "main.cpp")
target_link_libraries(ECSengine PRIVATE raylib)

if (WIN32)
    target_link_libraries(ECSengine PRIVATE winmm)
endif()