project('test_link_example', 'cpp')

# Since my system's libraries are a mess, be very explicit about where to find boost.
# In this case, we're relying on the library from Homebrew.
boost_root = '/usr/local/Cellar/boost/1.63.0'
boost_inc = include_directories(boost_root + '/include')
boost_lib = boost_root + '/lib'
#boost_ld_flags = '-Wl,-rpath,' + boost_lib

cc = meson.get_compiler('cpp')
boost_utfw = cc.find_library('boost_unit_test_framework', dirs : boost_lib)

executable('test_link_example', 'test_link_example.cpp', dependencies : boost_utfw)
