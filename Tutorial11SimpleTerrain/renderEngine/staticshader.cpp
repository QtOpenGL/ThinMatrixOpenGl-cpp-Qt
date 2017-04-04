#include "staticshader.h"

#include <toolbox/maths.h>

StaticShader::StaticShader() :
    ShaderProgram(":/shaders/shaders/shader.vert",
                  ":/shaders/shaders/shader.frag"),
    mLocationTransformationMatrix(-1)
{

}

void StaticShader::loadTransformationMatrix(const QMatrix4x4 &matrix)
{
    loadMatrix(mLocationTransformationMatrix, matrix);
}

void StaticShader::loadProjectionMatrix(const QMatrix4x4 &matrix)
{
    loadMatrix(mLocationProjectionMatrix, matrix);
}

void StaticShader::loadViewMatrix(const CameraSharedPtr &camera)
{
    loadMatrix(mLocationViewMatrix, Maths::createViewMatrix(camera));
}

void StaticShader::loadLight(const LightSharedPtr &light)
{
    loadVector(mLocationLightPosition, light->position());
    loadVector(mLocationLightColor, light->color());
}

void StaticShader::loadShineVariables(const float &shineDamper, const float &reflectivity)
{
    loadFloat(mLocationShineDamper, shineDamper);
    loadFloat(mLocationReflectivity, reflectivity);
}

void StaticShader::bindAttributes()
{
    bindAttribute(0, "position");
    bindAttribute(1, "textureCoords");
    bindAttribute(2, "normal");
}


void StaticShader::getAllUniformLocations()
{
    mLocationTransformationMatrix = getUniformLocation("transformationMatrix");
    mLocationProjectionMatrix = getUniformLocation("projectionMatrix");
    mLocationViewMatrix = getUniformLocation("viewMatrix");
    mLocationLightPosition = getUniformLocation("lightPosition");
    mLocationLightColor = getUniformLocation("lightColor");
    mLocationReflectivity = getUniformLocation("reflectivity");
    mLocationShineDamper = getUniformLocation("shineDamper");

}