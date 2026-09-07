add_executable(ECSengine ECSengine.cpp "EntityManager.h" "ComponentArray.h"  "ComponentManager.h" "System.h" "SystemManager.h")
target_link_libraries(ECSengine PRIVATE raylib)

if (WIN32)
    target_link_libraries(ECSengine PRIVATE winmm)
endif()