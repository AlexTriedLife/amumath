#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include "amumath/Vector3.h"

namespace py = pybind11;
using namespace amumath;

PYBIND11_MODULE(amumath_py, m) {
    m.doc() = "AMUMath Python Plugin";

    // Create Vector3 as a python class
    py::class_<Vector3>(m, "Vector3")
        .def(py::init<float, float, float>(), py::arg("x")=0, py::arg("y")=0, py::arg("z")=0)
        .def_readwrite("x", &Vector3::x)
        .def_readwrite("y", &Vector3::y)
        .def_readwrite("z", &Vector3::z)
        .def("dot", &Vector3::Dot)
        .def("magnitude", &Vector3::Magnitude)
        .def("normalize", &Vector3::Normalize)
        .def_static("cross", &Vector3::Cross)
        .def(py::self + py::self) 
        .def(py::self == py::self)
        .def(py::self * float()) // v * s
        .def(float() * py::self) // s * v
        .def(py::self / float())
        .def("__repr__", &Vector3::ToString);
}
