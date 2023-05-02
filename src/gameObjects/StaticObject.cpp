#include "StaticObject.h"

StaticObject::StaticObject(std::string name, glm::vec2 pos, glm::vec2 scale, glm::vec4 colour, bool setDynamic, bool applyPhysics) : GameObject(name, pos, scale, colour, setDynamic, applyPhysics)
{}

void StaticObject::UpdateLogic()
{
    // TODO
}
