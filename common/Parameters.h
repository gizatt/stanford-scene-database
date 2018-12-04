#pragma once

//
// Parameters.h
//

#include "Common.h"

namespace stanford_scene_database {

struct Parameters
{
    void Init(const std::string &filename);
    void Init() {}; // For manual construction

	public:
	    std::string databaseDirectory;
	    std::string defaultScene;

	    std::string textQuery;
};

}