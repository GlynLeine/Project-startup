#include "mge/materials/AbstractMaterial.hpp"

unsigned AbstractMaterial::materialCount = 0;

AbstractMaterial::AbstractMaterial(std::string typeName) : name(typeName)
{
}

AbstractMaterial::~AbstractMaterial()
{
    //dtor
}