#ifndef MAPLEENGINE_BOXRENDERER_H
#define MAPLEENGINE_BOXRENDERER_H

#include "../Component.h"
#include <glm/glm.hpp>

class BoxRenderer : public Component {
public:
    BoxRenderer(Entity& owner, glm::vec2 size, glm::vec3 colour);
    ~BoxRenderer();
    void render() const override;
private:
    glm::vec2 m_Size;
    glm::vec3 m_Colour;
};


#endif //MAPLEENGINE_BOXRENDERER_H
