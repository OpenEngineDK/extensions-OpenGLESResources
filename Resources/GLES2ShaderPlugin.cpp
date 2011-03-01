// OpenGLES 2 shader loader plugin
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------

#include <Resources/OpenGLES2Shader.h>
#include <Resources/File.h>
#include <Resources/DirectoryManager.h>
#include <fstream>

namespace OpenEngine {
namespace Resources {

    OpenGLES2ShaderPtr GLES2ShaderPlugin::CreateResource(string res) {
        ifstream* in = File::Open(res);

        char buf[255], file[255];
        int line = 0;

        string vertexFilename, fragFilename;
        
        while (!in->eof()) {
            ++line;
            in->getline(buf, 255);
            
            string type = string(buf,5);
            if (type.empty() || buf[0] == '#')
                continue;
            
            if (type == "vert:") {
                if (sscanf(buf, "vert: %s", file) == 1)
                    vertexFilename = string(file);                
            } else if (type == "frag:")
                if (sscanf(buf, "frag: %s", file) == 1)
                    fragFilename = string(file);
        }
        
        in->close();
        delete in;

        // logger.info << "vertexPath: " << vertexFilename << logger.end;
        // logger.info << "fragPath: " << fragmentFilename << logger.end;

        string vertexShader, fragShader;
        vertexFilename = DirectoryManager::FindFileInPath(vertexFilename);
        char *vertShdr = File::ReadShader<char>(vertexFilename);
        vertexShader = string(vertShdr);
        // logger.info << "vertexShader: " << vertShdr << logger.end;        

        fragFilename = DirectoryManager::FindFileInPath(fragFilename);
        char *fragShdr = File::ReadShader<char>(fragFilename);
        fragShader = string(fragShdr);

        // Create Shader

        OpenGLES2ShaderPtr shader = OpenGLES2ShaderPtr(new OpenGLES2Shader(vertexShader, fragShader));

        // TODO Set uniforms defined in file as constants

        return shader;
    }

}
}
