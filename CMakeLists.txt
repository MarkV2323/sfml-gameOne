cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(game_one)

# Setup SFML_PATH, must use \\ due to Windows!
set(SFML_PATH C:\\Users\\Mark\\Desktop\\cpp-apps\\lib\\SFML-2.6.1)

# Set Headers
set (HEADERS
    src/component/CCollision.h
    src/component/CInput.h
    src/component/CLifespan.h
    src/component/CScore.h
    src/component/CTransform.h
    src/entities/Entity.h
)

# Set Sources
set(SOURCES
    ${HEADERS}
    src/game_main.cc
)

# Build Main Executable
add_executable(game ${SOURCES})

# Setup includes
target_include_directories(game PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(game PRIVATE ${SFML_PATH}/include)

# Setup path to library files & specify what sfml-libs to link
# NOTE: the corresponding DLLs should be placed in System32.
target_link_directories(game PRIVATE ${SFML_PATH}/lib) 
target_link_libraries(game sfml-system sfml-window sfml-graphics sfml-audio sfml-network sfml-main)