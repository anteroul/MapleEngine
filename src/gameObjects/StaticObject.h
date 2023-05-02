#ifndef MAPLEENGINE_STATICOBJECT_H
#define MAPLEENGINE_STATICOBJECT_H

#include "../GameObject.h"

class StaticObject : public GameObject {
public:
    StaticObject(std::string name, glm::vec2 pos, glm::vec2 scale, glm::vec4 colour, bool setDynamic, bool applyPhysics);
protected:
    void UpdateLogic() override;
};


#endif //MAPLEENGINE_STATICOBJECT_H
