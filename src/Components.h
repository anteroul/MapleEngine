#ifndef MAPLEENGINE_COMPONENTS_H
#define MAPLEENGINE_COMPONENTS_H


#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <string>
#include <functional>

struct Component {};

struct IDComponent : public Component {
    unsigned ID;

    IDComponent() = default;
    IDComponent(const IDComponent&) = default;
    IDComponent(const unsigned& id) : ID(id) {}
};

struct TagComponent : public Component {
    std::string Tag;

    TagComponent() = default;
    TagComponent(const TagComponent&) = default;
    TagComponent(const std::string& tag) : Tag(tag) {}
};

struct TransformComponent : public Component {
    glm::vec3 Translation = { 0.f, 0.f, 0.f };
    glm::vec3 Rotation = { 0.f, 0.f, 0.f };
    glm::vec3 Scale = { 0.f, 0.f, 0.f };

    TransformComponent() = default;
    TransformComponent(const TransformComponent&) = default;
    TransformComponent(const glm::vec3& translation) : Translation(translation) {}

    glm::mat4 GetTransform() const
    {
        glm::mat4 rotation = glm::toMat4(glm::quat(Rotation));
        return glm::translate(glm::mat4(1.0f), Translation) * rotation * glm::scale(glm::mat4(1.0f), Scale);
    }
};

struct LegacyRendererComponent : public Component {
    glm::vec4 Color { 1.f, 1.f, 1.f, 1.f };

    LegacyRendererComponent() = default;
    LegacyRendererComponent(const LegacyRendererComponent&) = default;

    void RenderQuad(TransformComponent& transformComponent) const
    {
        glBegin(GL_QUADS);
        glColor4f(Color.x, Color.y, Color.z, Color.w);
        glVertex2f(transformComponent.Translation.x + transformComponent.Scale.x, transformComponent.Translation.y + transformComponent.Scale.y);
        glVertex2f(transformComponent.Translation.x + transformComponent.Scale.x, transformComponent.Translation.y - transformComponent.Scale.y);
        glVertex2f(transformComponent.Translation.x - transformComponent.Scale.x, transformComponent.Translation.y - transformComponent.Scale.y);
        glVertex2f(transformComponent.Translation.x - transformComponent.Scale.x, transformComponent.Translation.y + transformComponent.Scale.y);
        glEnd();
    }

    void RenderTriangle(TransformComponent& transformComponent) const
    {
        glBegin(GL_TRIANGLES);
        glColor4f(Color.x, Color.y, Color.z, Color.w);
        glVertex2f(transformComponent.Translation.x, transformComponent.Translation.y + transformComponent.Scale.y);
        glVertex2f(transformComponent.Translation.x + transformComponent.Scale.x, transformComponent.Translation.y - transformComponent.Scale.y);
        glVertex2f(transformComponent.Translation.x - transformComponent.Scale.x, transformComponent.Translation.y - transformComponent.Scale.y);
        glEnd();
    }
};

struct Rigidbody2DComponent : public Component {
    enum class BodyType {
        STATIC = 0,
        DYNAMIC,
        KINEMATIC
    };

    BodyType Type = BodyType::STATIC;
    bool FixedRotation = false;

    // Storage for runtime
    void* RuntimeBody = nullptr;

    Rigidbody2DComponent() = default;
    Rigidbody2DComponent(const Rigidbody2DComponent&) = default;
};

struct BoxCollider2DComponent : public Component {
    glm::vec2 Offset = { 0.0f, 0.0f };
    glm::vec2 Size = { 0.5f, 0.5f };

    float Density = 1.0f;
    float Friction = 0.5f;
    float Restitution = 0.0f;
    float RestitutionThreshold = 0.5f;

    // Storage for runtime
    void* RuntimeFixture = nullptr;

    BoxCollider2DComponent() = default;
    BoxCollider2DComponent(const BoxCollider2DComponent&) = default;
};

struct BehaviourScriptComponent : public Component {
    std::function<void()>* Update = nullptr;

    BehaviourScriptComponent() = default;
    BehaviourScriptComponent(const BehaviourScriptComponent&) = default;
    BehaviourScriptComponent(std::function<void()>& func) : Update(&func) {}
};


#endif //MAPLEENGINE_COMPONENTS_H
