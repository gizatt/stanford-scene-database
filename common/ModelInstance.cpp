//
// ModelInstance.cpp
//

#include "Common.h"

using namespace stanford_scene_database;

void ModelInstance::Render()
{
    glPushMatrix();
    glMultMatrixf(_transform[0]);
    _model->Render();
    glPopMatrix();

    for(auto childIterator = _children.begin(); childIterator != _children.end(); childIterator++)
    {
        (*childIterator)->Render();
    }
}
