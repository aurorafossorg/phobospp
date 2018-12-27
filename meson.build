project('phobospp', 'cpp')

cpu = host_machine.cpu_family()

supported_cpus = ['x86', 'x86_64']

if not supported_cpus.contains(cpu)
  error('MESON_SKIP_TEST unsupported cpu:' + cpu)
endif

inc = include_directories('include/')

src = []

library('phobospp', src, include_directories : inc, install : true)
static_library('phobospp', src, include_directories : inc, install : true)