
# Create python module
pybind11_add_module(amumath_py bindings.cpp)

# Link to main library
target_link_libraries(amumath_py PRIVATE AMUMath)
