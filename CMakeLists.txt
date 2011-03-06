# Create the extension library
ADD_LIBRARY(Extensions_OpenGLESResources
  Meta/OpenGLES2.h

  Resources/IBuffer.h
  Resources/Buffer.h
  Resources/IOpenGLESBuffer.h
  Resources/OpenGLESBuffer.h

#  Resources/IOpenGLESTexture2D.h
#  Resources/OpenGLESTexture2D.h

  Resources/OpenGLES2Shader.h
  Resources/OpenGLES2Shader.cpp
  Resources/GLES2ShaderPlugin.cpp

# New Engine classes
  Scene/NewMeshNode.h
  Scene/NewMeshNode.cpp
)
