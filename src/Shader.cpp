#include "Shader.h"
#include <iostream>

Shader::Shader(GLenum type, const std::string &src)
{
    shaderHandle = load(type, src);
}

Shader::~Shader()
{
    glDeleteShader(shaderHandle);
}

GLuint Shader::load(GLenum type, const std::string& src)
{
    GLuint handle = glCreateShader(type);

    if (!glIsShader(handle))
        return handle;

    const GLchar *sources[] = { src.c_str() };
    const GLint lengths[] = { (GLint)src.length() };

    // Try to load and compile the shader.
    glShaderSource(handle, 1, sources, lengths);
    glCompileShader(handle);

    // Print compilation log.
    std::string log = getLog(handle);

    if (!log.empty())
    {
        std::cout << "Compilation results:" << std::endl;
        std::cout << log << std::endl;
    }

    // Clean up handle if failure.
    GLint compileStatus;
    glGetShaderiv(handle, GL_COMPILE_STATUS, &compileStatus);

    if (compileStatus == GL_FALSE)
    {
        glDeleteShader(handle);
        return 0;
    }

    return handle;
}

std::string Shader::getLog(GLuint handle)
{
    GLint logLength;
    glGetShaderiv(handle, GL_INFO_LOG_LENGTH, &logLength);
    auto *log = new GLchar[logLength];

    glGetShaderInfoLog(handle, logLength, NULL, log);
    std::string logString(log);

    delete[] log;
    return logString;
}

void Shader::bind(GLuint shaderProgram) const
{
    if (glIsShader(shaderHandle))
        glAttachShader(shaderProgram, shaderHandle);
}

GLenum Shader::getType() const
{
    if (!glIsShader(shaderHandle))
        return GL_FALSE;

    GLint type = 0;
    glGetShaderiv(shaderHandle, GL_SHADER_TYPE, &type);
    return (GLenum)type;
}
