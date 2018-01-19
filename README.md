# Raytracer Project for RT @42
#### Authors <a href="https://github.com/elopez17" target="blank">Eric Lopez</a> & <a href="https://github.com/elopez17" rel="blank">Obsaa Abdalhalim</a>


### Program Requirements && Running Executable
To be able to build and run this program you'll need a macbook, because I didn't make it portable for other systems. As for software Requirements, you'll need in order to compile:

* No specific versions. [Unless you are using a version llvm that shows error using -Werror at compile time, take off or add those flags out of the makefile as needed.] 
* GNU make
* GCC
* Built using the minilibx library instead of OpenGL.

1. Clone the repo.
2. Access the main folder with makefile `cd RT`.
3. Run `make`.
4. Run `./RT scenes/scene`[*number*]`.rt`


### Make and Features

#### Build Info
There definitely languages better than C to run a raytracer algorithm eficiently but part of the assignment is using C and C libraries [most notably C++]. In the confines of our school standards which require we have no function longer than 25 lines [which is the most imminent of the many requirements of the standard we call norm], our major library functions such as printf (inside of the src/libft/ folder]. This raytracer is multithreaded but the benefits of multithreading was not seismic due to using mutexes to let the image render properly. The benefits of multithreading can be seen with raytracers that don't require reflection since algorithms are run once without worrying about how pockets of pixels change due recursive calls made on each thread.

#### Features Outlined
Feautres are outlined in the first window upon execution of the any of the valid scenes. These features let you control the following:
* Rotation
* Reflective Property of each object
* Brightness
* Moving objects on the x, y, z plane.
* RGB values (Red, Green, Blue) seperately.
* Specular Intensity [<a href="https://en.wikipedia.org/wiki/Specular_reflection" rel="blank">Link</a>]
* Diffuse Intensity [<a href="https://en.wikipedia.org/wiki/Diffuse_reflection" rel="blank">Link</a>]
* Gloss Intensity [<a href="http://www.raytracegroundup.com/downloads/Chapter25.pdf" rel="blank">Link</a>]



