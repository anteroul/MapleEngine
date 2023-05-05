#ifndef MAPLEENGINE_SHADER_H
#define MAPLEENGINE_SHADER_H

#include "App.h"
#include <string>

class Shader {
public:
    Shader(GLenum type, const std::string& src);
    ~Shader();
    void bind(GLuint shaderProgram) const;
    GLenum getType() const;
private:
    GLuint shaderHandle;
    static GLuint load(GLenum type, const std::string& src);
    static std::string getLog(GLuint handle);
};


#endif //MAPLEENGINE_SHADER_H
