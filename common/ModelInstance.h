#pragma once

//
// ModelInstance.h
//

#include "Common.h"


namespace stanford_scene_database {

class ModelInstance
{
public:
    friend class Scene;

    ModelInstance()
    {
        _model = NULL;
        _parent = NULL;
    }
    void AddChild(ModelInstance *child)
    {
        _children.push_back(child);
    }
    void Render();
    const ModelInstance * GetParent() const {
        return _parent;
    }
    const Matrix4& GetTransform() const {
        return _transform;
    }
    const Model& GetModel() const {
        return *_model;
    }

private:
    Model *_model;
    
    ModelInstance *_parent;
    std::vector<ModelInstance*> _children;

    Matrix4 _transform;

    Vec3f _parentContactPosition;
    Vec3f _parentContactNormal;
    Vec3f _parentOffset;
};

}