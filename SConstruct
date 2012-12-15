import os

env = Environment(CXX = "C:/software_lib/MinGW/bin/g++", CCFLAGS = "-g", tools=['mingw'], ENV=os.environ)

def filtered_glob(env, pattern, omit=[], ondisk=True, source=False, strings=False):
    return filter(lambda f: os.path.basename(f.path) not in omit, env.Glob(pattern))

env.AddMethod(filtered_glob, "FilteredGlob");


sourceList = env.Glob("#/src/*.cpp")


#env.ParseConfig("wx-config --cxxflags --libs")
env.ParseConfig("python sanitize-wx-config.py")

print env['CPPPATH']

# ------------ Headers and Libraries ------------- 

pathList = ['./include', 'C:/software_lib/boost', 'C:/software_lib/wiiuse', 
			'C:/software_lib/CMWii/include']
			
libPathList = ['C:/software_lib/boost/stage/lib', 'C:/software_lib/wiiuse', 
			   'C:/software_lib/CMWii/bin']

libList = ['boost_thread-mgw45-mt-1_46_1', 'wiiuse', 'CMWii']

# ------------ Dynamic libraries and executables ------------- 

mainProgram = env.Program(
target='./bin/CMii.exe',
source=sourceList,
CPPPATH=env['CPPPATH'] + pathList,
LIBPATH=env['LIBPATH'] + libPathList,
LIBS=env['LIBS'] + libList
)

Default(mainProgram)
