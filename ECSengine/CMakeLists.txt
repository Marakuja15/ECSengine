add_executable(ECSengine  "Engine/EntityManager.h" "Engine/ComponentArray.h"  "Engine/ComponentManager.h" "Engine/System.h" "Engine/SystemManager.h" "Engine/Entity.h" "Engine/World.h" "Game/main.cpp")
target_link_libraries(ECSengine PRIVATE raylib)

if (WIN32)
    target_link_libraries(ECSengine PRIVATE winmm)
endif()