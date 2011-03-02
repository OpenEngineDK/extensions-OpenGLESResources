// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------

#ifndef _OpenGL_ES_2_Shader_H_
#define _OpenGL_ES_2_Shader_H_

#include <Resources/IShaderResource.h>
#include <Resources/IResourcePlugin.h>
#include <Meta/OpenGLES2.h>
#include <Logging/Logger.h>

namespace OpenEngine {
namespace Resources {
/**
 * Short description.
 *
 * @class OpenGLES2Shader OpenGLES2Shader.h ons/iOS/Resources/OpenGLES2Shader.h
 */
class OpenGLES2Shader /* : public IShaderResource*/ {
private:
    string vertexShader, fragmentShader;
    
    GLuint LoadShader(string file, GLenum type);
    GLuint programID;
    
    
public:
    OpenGLES2Shader(string vertex, string fragment);
    
    void ApplyShader();
    void ReleaseShader();

    GLint GetUniformLocation(string name);

    void SetUniform(string name, int arg);
    void SetUniform(string name, float value);
    void SetUniform(string name, Vector<2, float> value);
    void SetUniform(string name, Vector<3, float> value);
    void SetUniform(string name, Vector<4, float> value);
    void SetUniform(string name, Matrix<4, 4, float> value);
    
    void GetUniform(string name, int &value);
    void GetUniform(string name, float &value);
    void GetUniform(string name, Vector<2, float> &value);
    void GetUniform(string name, Vector<3, float> &value);
    void GetUniform(string name, Vector<4, float> &value);
    void GetUniform(string name, Matrix<4, 4, float> &value);
    
    int GetAttributeID(const string name);
    void BindAttribute(int id, string name);

    void Load();
    void Unload();

};

typedef boost::shared_ptr<OpenGLES2Shader> OpenGLES2ShaderPtr;

class GLES2ShaderPlugin : public IResourcePlugin<OpenGLES2Shader> {
public:
    GLES2ShaderPlugin() {
        this->AddExtension("glsl");
    }
    OpenGLES2ShaderPtr CreateResource(string file);
};
    
} // NS Resources
} // NS OpenEngine

#endif //_OpenGL_ES_2_Shader_H_
