# boost-intro
## What is this?
This repo contains a few projects produced while following instructions for
setting up boost, linking boost libraries to an executable, adding unit tests,
and rolling them all into the meson build system.

The original coding was done on OS X, so the setup steps are specific to this OS.
If you are so inclined, you may feel free to update them for your own environment.



## Why is this here?
### Story time...
My intent, originally, was to create some simple unit tests and just TDD
something (to be decided later) once I figured out the latest and greatest
unit test library for C++.

But C++ has no such standardization.  I landed on boost, since I wanted to learn more about it, and discovered it has its own testing framework.  So to write unit tests, I found myself following tutorials for getting started with boost.  This resulted in a couple different binaries and a shell script that had the straight clang commands from the boost tutorial. I realized I also wanted to
know the latest and greatest make system for C++.

But C++ has no such standardization.  I landed on meson because someone on the
internet said they loved it.  It took some getting used to, but I like it, too,
so far.

In getting the boost libraries installed based on the getting started guide, I
realized I already had them installed via HomeBrew because of some other thing
I had installed with it.  Trying to manually install boost, then overwrite it
with HomeBrew once I figured out the state of my machine, led to some problems
with my installation, so my meson files and custom build script are pointing
directly to the brew folder with boost.

### Morals of the story:
1. Given the choice between installing libraries via a package manager and
installing manually via instructions on the library's website, use the package
manager.
1. C++ has been roundly criticized for being extremely flexible and giving
developers incredible amounts of choice.  It deserves this criticism.
1. The internet assumes you know what you're doing.  You probably don't.  My
moment of clarity was in learning that `/usr/local/lib/`, `/usr/local/bin/`, and
 `/usr/local/include/` are where the C/C++ magic goes to live.
If I'd known what to look for, I'd have found this: http://refspecs.linuxfoundation.org/FHS_2.3/fhs-2.3.html#USRLOCALLOCALHIERARCHY
1. When this was originally built, I'd written C++ for a living for over 8
years.  Setting up a development environment to link a standard library and
simply build took me several hours.  If you're a new developer, and frustrated
that simple things are taking you hours, don't let that simple fact discourage
you.  Keep going.  It's hard, and it's fun.

### References
* Boost 'Getting Started' tutorial: http://www.boost.org/doc/libs/1_63_0/more/getting_started/unix-variants.html
* Installing HomeBrew: https://brew.sh/
* Meson build documentation: https://github.com/mesonbuild/meson/wiki

# Using the code
After forking the repository, the first thing you'll need to do is install
dependencies.  Then, you'll need to set up the meson build directories.

## Build environment
For my build environment, I used the OS X terminal and Atom for editing.  For
debugging, I installed the `dbg` and `dbg-gdb` Atom packages.  I chose meson
to manage makefiles, which implies ninja as the build tool.

### Environment Setup
1. Install HomeBrew.  (See https://brew.sh/)
1. Install boost with HomeBrew: `brew install boost`
1. Install meson with HomeBrew (this will bring down ninja as a dependency):
`brew install meson`

### Quick Start
Run `./test.sh` from the root directory to get started.  This will run meson to
create all the build directories, then run ninja to build them, then run ninja
tests.  Alternatively, you can run `./setup.sh` or `./bld.sh` just to get the
directories set up, or just to get the directories set up and built.

You will probably hit errors because of the boost paths defined in the various
`meson.build` files in all the subdirectories.

When the projects are built and tests pass, running `./install.sh` will put the
bs and rit executables in your `/usr/local/bin/` path.

# Projects
## bs (Bubble Sort)
Contains a library, unit tests, and executable that bubble-sorts signed integers.

## compile_example
The boost sample for compiling against boost headers.  This sample is taken
directly from http://www.boost.org/doc/libs/1_63_0/more/getting_started/unix-variants.html#build-a-simple-program-using-boost.

## link_example
The boost sample for linking against boost libraries.  The project links against
the dynamic libraries, and is taken directly from http://www.boost.org/doc/libs/1_63_0/more/getting_started/unix-variants.html#link-your-program-to-a-boost-library

## rit (Random Integer Tool)
Contains a library that produces random integers.

## test_example
Contains the boost sample for creating a unit test, taken directly from
http://www.boost.org/doc/libs/1_63_0/libs/test/doc/html/boost_test/intro.html

## test_link_example
This is the boost unit test sample, dynamically-linked against boost binaries.
