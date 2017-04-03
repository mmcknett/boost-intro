project('bubble_sort', 'cpp', default_options : ['cpp_std=c++14'])

# Since my system's libraries are a mess, be very explicit about where to find boost.
# In this case, we're relying on the library from Homebrew.
boost_root = '/usr/local/Cellar/boost/1.63.0'
boost_inc = boost_root + '/include/'
boost_lib = boost_root + '/lib'

cc = meson.get_compiler('cpp')
boost_utfw = cc.find_library('boost_unit_test_framework', dirs : boost_lib)

includes = include_directories(boost_inc)

unit_test_sorting_sources = ['bubble_sort_tests.cpp']
bubble_sort_sources = ['bubble_sort.cpp']
bs_exe_sources = ['bs.cpp']

bubble_sort_lib = static_library('bubble_sort_lib', bubble_sort_sources)

bubble_sort_tests = executable('bubble_sort_tests',
          sources: unit_test_sorting_sources,
          include_directories: includes,
          link_with: bubble_sort_lib,
          dependencies: boost_utfw)

sorter_logging_decorator_tests = executable('sorter_logging_decorator_tests',
                                    sources: 'sorter_logging_decorator_tests.cpp',
                                    include_directories: includes,
                                    dependencies: boost_utfw)

executable('bs',
          sources: bs_exe_sources,
          include_directories: includes,
          link_with: bubble_sort_lib,
          cpp_pch: 'pch/bs_pch.h',
          install: true)

test('Bubble Sort Unit Tests', bubble_sort_tests)
test('Sorter Logging Decorator Unit Tests', sorter_logging_decorator_tests)
