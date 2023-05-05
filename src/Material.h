#ifndef MAPLEENGINE_MATERIAL_H
#define MAPLEENGINE_MATERIAL_H

#include "Log/msg.h"
#include <string>
#include "Shader.h"
#include "Game.h"

#include <iostream>
#include <sstream>
#include <vector>

class Material {
public:
    static void deactivate();

    Material(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
    ~Material();

    void apply() const;
    void setUniform(const std::string& name, float v);
private:
    static GLuint activeProgram;
    GLuint programHandle;

    static GLuint link(const Shader* vertexShader, const Shader* fragmentShader);
    static std::string getLog(GLuint handle);
    static Shader *loadShader(GLenum type, const std::string& path);

    GLint getUniformLocation(const std::string& name) const;
};

#endif //MAPLEENGINE_MATERIAL_H
