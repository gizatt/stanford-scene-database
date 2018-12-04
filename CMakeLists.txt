cmake_minimum_required(VERSION 3.5)
project (stanford_scene_database)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set default install prefix
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE STRING
    "Prefix for installation of sub-packages (note: required during build!)"
    FORCE)
endif()

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

set(STANFORD_SCENE_COMMON_SRCS
    common/Assets.cpp 
    common/Camera.cpp 
    common/Matrix4.cpp
    common/Mesh.cpp 
    common/Model.cpp 
    common/ModelDatabase.cpp
    common/ModelInstance.cpp 
    common/Parameters.cpp 
    common/Scene.cpp
    common/Utility.cpp)

set(STANFORD_SCENE_COMMON_HDRS
    common/Assets.h 
    common/Camera.h 
    common/Common.h
    common/FreeImage.h
    common/Matrix4.h
    common/Mesh.h 
    common/Model.h 
    common/ModelDatabase.h
    common/ModelInstance.h 
    common/Parameters.h 
    common/Scene.h
    common/Utility.h
    common/Vec3f.h)

add_library(stanford_scene_common ${STANFORD_SCENE_COMMON_HDRS} 
			${STANFORD_SCENE_COMMON_SRCS})

target_link_libraries(stanford_scene_common freeimage ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

INSTALL(TARGETS stanford_scene_common
        DESTINATION "lib"
        )
INSTALL(FILES ${STANFORD_SCENE_COMMON_HDRS}
        DESTINATION "include/stanford_scene_common"
        )

set(SCENE_VIEWER_SRCS
	sceneViewer/main.cpp
	sceneViewer/sceneViewer.cpp
	sceneViewer/sceneViewer.h)
add_executable(scene_viewer ${SCENE_VIEWER_SRCS})
target_link_libraries(scene_viewer stanford_scene_common freeimage ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
INSTALL(TARGETS stanford_scene_common
		DESTINATION "bin"
		)
