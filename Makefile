# Default
all: build
# Configure CMake
config:
	@mkdir -p build
	cmake -S . -B build

# Compile
build:
	@[ -f build/Makefile ] || $(MAKE) config
	@$(MAKE) -C build --no-print-directory

# Clean
clean:
	rm -rf build
# Only compile python bindings
python:
	@[ -f build/Makefile ] || $(MAKE) config
	@$(MAKE) -C build amumath_py --no-print-directory
	@echo "✅ Python module built. Location:"
	@find build/bindings -name "*.so"

# Run python tests
# Automatically find .so file and add it to python path
test-py: python
	@echo "Running Python tests..."
	@export PYTHONPATH=$$(pwd)/build/bindings && python3 test_calc.py
# Run C++ Unit Tests
test: build
	cd build && ctest --output-on-failure

# Symlink compile commands for Neovim
lsp:
	ln -sf build/compile_commands.json .

.PHONY: all config build python test-py test clean lsp
