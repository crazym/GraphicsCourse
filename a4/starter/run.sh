rm RayTracer
rm minty.ppm
./compile.sh
./RayTracer 300 2 1 output/minty.ppm
# using feh to view .ppm file
feh output/minty.ppm
