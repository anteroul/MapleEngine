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
        src/entrypoint/main.cc
        src/App.hh
        src/App.cc
        src/Log/msg.h
        src/Game.cpp
        src/Game.h
        src/ECS/Entity.cpp
        src/ECS/Entity.h
        src/ECS/Component.h
        src/Physics/CollisionHandler.cpp
        src/Physics/CollisionHandler.h
        src/Physics/Mesh.cpp
        src/Physics/Mesh.h
        src/Physics/Physics.cpp
        src/Physics/Physics.h src/ECS/Components/PlayerInput.cpp src/ECS/Components/PlayerInput.h src/ECS/Components/RecRenderer.cpp src/ECS/Components/RecRenderer.h src/Material.cpp src/Material.h src/Shader.cpp src/Shader.h src/Geometry.cpp src/Geometry.h)

target_link_libraries(MapleEngine PUBLIC ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${lib/stb_image.h} -lglfw tobanteGaming::Box2D)