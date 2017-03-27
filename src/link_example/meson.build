project('link_example', 'cpp')

# Since my system's libraries are a mess, be very explicit about where to find boost.
# In this case, we're relying on the library from Homebrew.
boost_root = '/usr/local/Cellar/boost/1.63.0'
boost_inc = include_directories(boost_root + '/include')
boost_lib = boost_root + '/lib'

cc = meson.get_compiler('cpp')
boost_regex = cc.find_library('boost_regex', dirs : boost_lib)

executable('link_example', 'link_example.cpp', dependencies : boost_regex)
