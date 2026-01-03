enable_testing()

add_executable(AMUMathTests 
    main.cpp 
    test_vector3.cpp
)

target_link_libraries(AMUMathTests PRIVATE AMUMath gtest)

# Register tests
include(GoogleTest)
gtest_discover_tests(AMUMathTests)
