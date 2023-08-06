#ifndef LEARNOPENGL_SHADER_H
#define LEARNOPENGL_SHADER_H


class Shader {
public:
    Shader(const std::string& vertexShaderName, const std::string& fragmentShaderName);
    void Use() const;
    unsigned int GetID() const;
    void SetInt(const std::string& name, int value) const;
    void SetFloat(const std::string& name, float value) const;
    void SetDouble(const std::string& name, double value) const;
    void SetBool(const std::string& name, bool value) const;

private:
    unsigned int id;
    std::string vsStr;
    std::string fsStr;
    const char* vertexShaderSource;
    const char* fragmentShaderSource;
    void compile();
};


#endif //LEARNOPENGL_SHADER_H
