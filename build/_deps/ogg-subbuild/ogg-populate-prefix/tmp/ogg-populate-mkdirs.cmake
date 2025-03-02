# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/murdoch/Peanut Engine/Peanut-Engine/build/_deps/ogg-src"
  "/Users/murdoch/Peanut Engine/Peanut-Engine/build/_deps/ogg-build"
  "/Users/murdoch/Peanut Engine/Peanut-Engine/build/_deps/ogg-subbuild/ogg-populate-prefix"
  "/Users/murdoch/Peanut Engine/Peanut-Engine/build/_deps/ogg-subbuild/ogg-populate-prefix/tmp"
  "/Users/murdoch/Peanut Engine/Peanut-Engine/build/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp"
  "/Users/murdoch/Peanut Engine/Peanut-Engine/build/_deps/ogg-subbuild/ogg-populate-prefix/src"
  "/Users/murdoch/Peanut Engine/Peanut-Engine/build/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/murdoch/Peanut Engine/Peanut-Engine/build/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/murdoch/Peanut Engine/Peanut-Engine/build/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
