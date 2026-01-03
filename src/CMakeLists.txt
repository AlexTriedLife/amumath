add_library(AMUMath 
    Vector3.cpp
    Vector2.cpp
)

target_include_directories(AMUMath PUBLIC ${CMAKE_SOURCE_DIR}/include)
