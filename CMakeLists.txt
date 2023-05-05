cmake_minimum_required(VERSION 3.24)
project(MapleEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARY_DIRS})

add_subdirectory(3rd_party/Box2D-cmake)

add_executable(MapleEngine
        src/entrypoint/main.cpp
        src/App.h
        src/App.cpp
        src/Log/msg.h
        src/Game.cpp
        src/Game.h
        src/Material.cpp
        src/Material.h
        src/Shader.cpp
        src/Shader.h
        src/Geometry.cpp
        src/Geometry.h
        src/ECS/Entity.cpp
        src/ECS/Entity.h
        src/ECS/Component.h
        src/ECS/Components/PlayerInput.cpp
        src/ECS/Components/PlayerInput.h
        src/ECS/Components/RecRenderer.cpp
        src/ECS/Components/RecRenderer.h
        src/Physics/CollisionHandler.cpp
        src/Physics/CollisionHandler.h
        src/Physics/Mesh.cpp
        src/Physics/Mesh.h
        src/Physics/Physics.cpp
        src/Physics/Physics.h
        src/GameObjects/Player.cpp
        src/GameObjects/Player.h
        src/ECS/Components/WallCollision.cpp
        src/ECS/Components/WallCollision.h src/Filesystem.cpp src/Filesystem.h src/Strings.cpp src/Strings.h src/ECS/Components/SphereRenderer.cpp src/ECS/Components/SphereRenderer.h src/GameObjects/Wall.cpp src/GameObjects/Wall.h)

target_link_libraries(MapleEngine PUBLIC ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${lib/stb_image.h} -lglfw tobanteGaming::Box2D)