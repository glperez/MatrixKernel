#######################################
# The list of libraries we are building seperated by spaces.
# The 'lib_' indicates that these build products will be installed
# in the $(libdir) directory. For example /usr/lib
AUTOMAKE_OPTIONS = subdir-objects

lib_LTLIBRARIES = libMatMult.la

bin_PROGRAMS = unit_test test

#######################################
# Build information for each library

# Sources for libMatMult
libMatMult_la_SOURCES = ./datastructures/Matrix.cpp\ 
						./datastructures/DenseMatrix.cpp

# Linker options libTestProgram
libMatMult_la_LDFLAGS = 

unit_test_SOURCES = ./testing/unittest_runner.cpp \
					./testing/DenseMatrixTest.cpp
unit_test_LDFLAGS = -lcppunit
unit_test_LDADD = libMatMult.la

test_SOURCES = ./test.cpp
test_LDADD = libMatMult.la

# Compiler options. Here we are adding the include directory
# to be searched for headers included in the source code.
libMatMult_la_CPPFLAGS = -I$(top_srcdir)/src/datastructures
unit_test_CPPFLAGS = -I$(top_srcdir)/src/datastructures
test_CPPFLAGS = -I$(top_srcdir)/src/datastructures