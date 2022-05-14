cmake_minimum_required(VERSION 3.17)
project(Poker)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")
set(CMAKE_CXX_STANDARD 14)

set (SOURCE_FILES main.cpp Card.cpp Card.h suits_ranks.h Deck.cpp Deck.h CardHand.cpp
        CardHand.h CardHandScorer.cpp CardHandScorer.h PokerScore.cpp PokerScore.h PokerCombo.cpp PokerCombo.h
        sfml.cpp sfml.h PokerGame.cpp PokerGame.h)
if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_ROOT ./dependencies/SFML-2.5.1)
set(SFML_DIR ./dependencies/SFML-2.5.1/lib/cmake/SFML)
set(SFML_INCLUDE_DIR ./dependencies/SFML-2.5.1/include )
set(SFML_LIBRARIES sfml-graphics sfml-window sfml-system)


set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()
