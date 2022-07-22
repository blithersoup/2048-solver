import ctypes
import os
import re

# searching for shared library files in build directory
file_pattern = re.compile(r".*\.(so|dll|dylib)")
build_path = os.path.dirname(os.path.abspath(__file__))
for path in ['..','..','build']: build_path = os.path.join(build_path, path)
lib_filename = next(filter(file_pattern.match, os.listdir(build_path)))

# joining directory name with path
lib_file = os.path.join(build_path, lib_filename)

# shared library used
lib = ctypes.CDLL(lib_file)