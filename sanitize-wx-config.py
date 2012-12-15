import subprocess, sys

p = subprocess.Popen(["wx-config", "--cxxflags", "--libs"], stdout=subprocess.PIPE)
out, err = p.communicate()

san = out.replace("\\", "/")

sys.stdout.write(san)
sys.exit(0)