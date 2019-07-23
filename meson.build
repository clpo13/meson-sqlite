# Define project settings
project('meson-sqlite', 'cpp',
  version : '0.1.0',
  default_options : ['warning_level=3',
                     'cpp_std=c++14'])

# Set up dependencies
sqlite_dep = dependency('sqlite3', required : false)

if not sqlite_dep.found()
  sqlite_proj = subproject('sqlite')
  sqlite_dep = sqlite_proj.get_variable('sqlite_dep')
endif

# Compile the program
exe = executable('sqlite-test', 'sqlite-test.cpp',
  dependencies : sqlite_dep)

# Run tests
test('create a db', exe,
  args : ['test.db', 'create table tbl1(one varchar(10))'],
  is_parallel : false)
test('add to a db', exe,
  args : ['test.db', 'insert into tbl1 values("hello!")'],
  is_parallel : false)
test('read a db', exe,
  args : ['test.db', 'select * from tbl1'],
  is_parallel : false)
test('drop from a db', exe,
  args : ['test.db', 'drop table tbl1'],
  is_parallel : false)
