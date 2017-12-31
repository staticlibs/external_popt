Popt library build for Staticlibs
=================================

[![travis](https://travis-ci.org/staticlibs/external_popt.svg?branch=master)](https://travis-ci.org/staticlibs/external_popt)
[![appveyor](https://ci.appveyor.com/api/projects/status/github/staticlibs/external_popt?svg=true)](https://ci.appveyor.com/project/staticlibs/external-popt)

This project is a part of [Staticlibs](http://staticlibs.net/).

This project contains a CMake build file for building [Popt library](http://rpm5.org/files/popt/).

[Popt sources imported from CentOS Linux](https://github.com/ojdkbuild/lookaside_popt) are used as a submodule
of this project.

Link to [man documentation](https://linux.die.net/man/3/popt).

How to build
------------

[CMake](http://cmake.org/) is required for building.

To build the library on Windows using Visual Studio 2013 Express run the following commands using
Visual Studio development command prompt 
(`C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\Shortcuts\VS2013 x86 Native Tools Command Prompt`):

    git clone --recursive https://github.com/staticlibs/external_popt.git
    cd external_popt
    mkdir build
    cd build
    cmake ..
    msbuild external_popt.sln

See [StaticlibsToolchains](https://github.com/staticlibs/wiki/wiki/StaticlibsToolchains) for 
more information about the CMake toolchains setup and cross-compilation.

License information
-------------------

This project is released under the [Apache License 2.0](http://www.apache.org/licenses/LICENSE-2.0).

Changelog
---------

**2017-12-21**

 * version 1.13-2
 * vs2017 support

**2016-10-28**

 * version 1.13-1
 * initial public version
