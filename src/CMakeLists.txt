add_library(AMUMath 
    Vector3.cpp
    Vector2.cpp
)

# Allow python linking
set_target_properties(AMUMath PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_include_directories(AMUMath PUBLIC ${CMAKE_SOURCE_DIR}/include)
