cmake_minimum_required( VERSION 2.6 )

project( Gaia )
FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

FIND_PACKAGE( Marble REQUIRED )
INCLUDE_DIRECTORIES( ${MARBLE_INCLUDE_DIR} ${QT_INCLUDE_DIR} )
message( ${MARBLE_INCLUDE_DIR} ${QT_INCLUDE_DIR} )


SET( Gaia_SRCS Crust.cpp OuterCore.cpp Thermosphere.cpp TileLayer.cpp
               InnerCore.cpp Mantle.cpp Simulation.cpp Tile.cpp Troposphere.cpp
               main.cpp )
ADD_EXECUTABLE( gaia ${Gaia_SRCS} )

target_link_libraries(  gaia ${MARBLE_LIBRARIES} ${QT_LIBRARIES} )



