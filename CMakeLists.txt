cmake_minimum_required( VERSION 2.6 )

project( gaia )

set( gaia_SRCS Crust.cpp main.cpp OuterCore.cpp Thermosphere.cpp TileLayer.cpp
               InnerCore.cpp Mantle.cpp Simulation.cpp Tile.cpp Troposphere.cpp)
add_executable( gaia gaia_SRCS )

