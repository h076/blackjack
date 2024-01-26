cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

project(sortVisualiser)

set(INCLUDE_DIRECTORIES ./build/include)

set(MAIN_SOURCE main.cpp ${INCLUDE_DIRECTORIES}/Deck.cpp ${INCLUDE_DIRECTORIES}/Deck.h
  ${INCLUDE_DIRECTORIES}/Card.cpp ${INCLUDE_DIRECTORIES}/Card.h
  Button.cpp Button.h
  clients.cpp clients.h)

add_executable(blackjack ${MAIN_SOURCE})

target_link_libraries(
  blackjack PUBLIC
  /Library/Frameworks/SDL2.framework/Versions/A/SDL2
  /Library/Frameworks/SDL2_image.framework/Versions/A/SDL2_image
)

target_include_directories(
  blackjack PUBLIC
  /Library/Frameworks/SDL2.framework/Versions/A/Headers
  /Library/Frameworks/SDL2_image.framework/Versions/A/Headers
)
