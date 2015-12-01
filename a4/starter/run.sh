# clean up
rm RayTracer
rm output/minty.ppm
# compile and run
./compile.sh
./RayTracer 300 2 1 output/minty.ppm
# use feh to view .ppm file
feh output/minty.ppm
