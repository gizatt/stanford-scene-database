#pragma once 

//
// Model.h
//

#include "Common.h"


namespace stanford_scene_database {

class Assets;
class Model
{
public:
    Model(const std::string &directory, const std::string &baseFilename, Assets &textureStore);

    void Render();

    //
    // Accessors
    //
    inline const Vec3f& BoundingBoxMin() const
    {
        return _boundingBoxMin;
    }
    inline const Vec3f& BoundingBoxMax() const
    {
        return _boundingBoxMax;
    }
    inline const std::string& Hash() const
    {
        return _hash;
    }

private:
    GLuint _displayList;

    std::vector<Mesh*> _meshes;
    
    std::string _hash;
    
    Vec3f _boundingBoxMin, _boundingBoxMax;
};

}