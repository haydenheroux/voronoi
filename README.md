# voronoi

A Voronoi pattern simulation written in C++ using SDL2 for rendering.

## development

### compile

To compile this program, run:

```sh
g++ *.cpp -lSDL2 -Wall -o voronoi
```

If the above command errors, ensure that SDL2/SDL.h is within your include path, and that the SDL2 libraries were successfully located.

### run

```sh
./voronoi
```

Wait for some time, since the simulation is computed on a single thread with poor efficiency. 

## improvements

 - Running the simulation on multiple threads in parallel could yield improvements render time
 - CUDA / GPU-acceleration is another option for improving performance via parallel processing
 - `setColorToNearestSpecial` is called for each pixel ("`Cell`") on the canvas and iterates through each marked ("`special`" Cell
   - Much of the processing time is spent within this function; optimizing this function in particular could entail massive performance gains
