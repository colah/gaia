cmake_minimum_required( VERSION 2.6 )

project( Gaia )

FIND_LIBRARY( Marble REQUIRED )
include_directories( ${MARBLE_INCLUDE_DIR} )


set( Gaia_SRCS Crust.cpp OuterCore.cpp Thermosphere.cpp TileLayer.cpp
               InnerCore.cpp Mantle.cpp Simulation.cpp Tile.cpp Troposphere.cpp
               main.cpp )
add_executable( gaia ${Gaia_SRCS} )

target_link_libraries(  gaia marblewidget )

