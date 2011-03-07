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

# Converter
  Resources/OpenGLESConverter.h
  Resources/OpenGLESConverter.cpp

# New Engine classes
  Geometry/NewGeometrySet.h
  Geometry/NewGeometrySet.cpp
  Geometry/NewMesh.h
  Geometry/NewMesh.cpp
  Scene/NewMeshNode.h
  Scene/NewMeshNode.cpp
)
