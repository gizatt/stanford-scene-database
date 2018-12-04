#pragma once

//
// Parameters.h
//

#include "Common.h"

namespace stanford_scene_database {
using namespace stanford_scene_database;

struct Parameters
{
    void Init(const std::string &filename);

    std::string databaseDirectory;
    std::string defaultScene;

    std::string textQuery;
};

}