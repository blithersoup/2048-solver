import ctypes
import os
import re

# searching for shared library files in build directory
file_pattern = re.compile(r".*\.(so|dll|dylib)")
lib_filename = next(filter(file_pattern.match, os.listdir("../build")))

# joining directory name with path
dir_path = os.path.dirname(os.path.realpath(lib_filename))
lib_file = os.path.join(dir_path, lib_filename)

# shared library used
lib = ctypes.CDLL(lib_file)
