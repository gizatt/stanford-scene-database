#pragma once

//
// Scene.h
//

#include "Common.h"


namespace stanford_scene_database {
using namespace stanford_scene_database;

class Scene
{
public:
    void Load(const Parameters &params, const std::string &filename, Assets &assets);
    void Render();

private:
    ModelInstance *_root;
    std::vector<ModelInstance*> _allModels;
};
}