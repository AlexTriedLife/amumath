# Default
all: build

# Configure CMake
config:
	cmake -S . -B build

# Compile
build:
	@$(MAKE) -C build --no-print-directory

# Run test suite
test: build
	cd build && ctest --output-on-failure

# Clean
clean:
	rm -rf build

# Symlink compile commands for Neovim LSP
lsp:
	ln -sf build/compile_commands.json .
