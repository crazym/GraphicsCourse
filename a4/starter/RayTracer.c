/*
  CSC D18 - RayTracer code.

  Written Dec. 9 2010 - Jan 20, 2011 by F. J. Estrada
  Freely distributable for adacemic purposes only.

  Uses Tom F. El-Maraghi's code for computing inverse
  matrices. You will need to compile together with
  svdDynamic.c

  You need to understand the code provided in
  this file, the corresponding header file, and the
  utils.c and utils.h files. Do not worry about
  svdDynamic.c, we need it only to compute
  inverse matrices.

  You only need to modify or add code in sections
  clearly marked "TO DO"

  Last updated: Aug. 12, 2014   - F.J.E.
*/

#include "utils.h"	// <-- This includes RayTracer.h

// A couple of global structures and data: An object list, a light list, and the
// maximum recursion depth
struct object3D *object_list;
struct pointLS *light_list;
struct textureNode *texture_list;
int MAX_DEPTH;

void buildScene(void)
{
 // Sets up all objects in the scene. This involves creating each object,
 // defining the transformations needed to shape and position it as
 // desired, specifying the reflectance properties (albedos and colours)
 // and setting up textures where needed.
 // Light sources must be defined, positioned, and their colour defined.
 // All objects must be inserted in the object_list. All light sources
 // must be inserted in the light_list.
 //
 // To create hierarchical objects:
 //    You must keep track of transformations carried out by parent objects
 //    as you move through the hierarchy. Declare and manipulate your own
 //    transformation matrices (use the provided functions in utils.c to
 //    compound transformations on these matrices). When declaring a new
 //    object within the hierarchy
 //    - Initialize the object
 //    - Apply any object-level transforms to shape/rotate/resize/move
 //      the object using regular object transformation functions
 //    - Apply the transformations passed on from the parent object
 //      by pre-multiplying the matrix containing the parent's transforms
 //      with the object's own transformation matrix.
 //    - Compute and store the object's inverse transform as usual.
 //
 // NOTE: After setting up the transformations for each object, don't
 //       forget to set up the inverse transform matrix!

 struct object3D *o;
 struct pointLS *l;
 struct point3D p;

 // Simple scene for Assignment 3:
 // Insert a couple of objects. A plane and two spheres
 // with some transformations.

 // Note the parameters: ra, rd, rs, rg, R, G, B, alpha, r_index, and shinyness)

 // o=newSphere(.05,.95,.35,.35,1,.25,.25,1,1,6);    // Initialize a sphere
 // Scale(o,1.5,.75,.75);          // Apply a few transforms (Translate * Rotate * Scale)
 // RotateZ(o,PI/4);         
 // Translate(o,2.0,2.5,1.5);
 // invert(&o->T[0][0],&o->Tinv[0][0]);      // Compute the inverse transform * DON'T FORGET TO DO THIS! *

 // // If needed, this is how you load a texture map
 // // loadTexture(o,"./Texture/mosaic2.ppm",1,&texture_list); // This loads a texture called 'mosaic2.ppm'. The
 //                // texture gets added to the texture list, and a
 //                // pointer to it is stored within this object in the
 //                // corresponding place. The '1' indicates this image
 //                // will be used as a texture map. Use '2' to load
 //                // an image as a normal map, and '3' to load an
 //                // alpha map. Texture and normal maps are RGB .ppm
 //                // files, alpha maps are grayscale .pgm files.
 //                // * DO NOT * try to free image data loaded in this
 //                // way, the cleanup function already provided will do
 //                // this at the end.
 //  // loadTexture(o,"./texture/decorative_pattern.ppm", 1, &texture_list);
 //  insertObject(o,&object_list);     // <-- If you don't insert the object into the object list,
 //            //     nothing happens! your object won't be rendered.

 // // That's it for defining a single sphere... let's add a couple more objects
 // o=newSphere(.05,.95,.95,.75,.75,.95,.55,0,1,6);
 // Scale(o,.95,1.65,.65);
 // RotateZ(o,-PI/1.5);
 // Translate(o,-2.2,1.75,1.35);
 // invert(&o->T[0][0],&o->Tinv[0][0]);
 // // loadTexture(o,"./texture/decorative_pattern.ppm", 1, &texture_list);
 // insertObject(o,&object_list);

 // o=newPlane(.05,.75,.65,.55,.55,.8,.75,1,1,2);
 // Scale(o,11,11,11);
 // RotateZ(o,PI/4);
 // RotateX(o,PI/2);
 // Translate(o,0,-4,5);
 // invert(&o->T[0][0],&o->Tinv[0][0]);
 // // loadTexture(o,"./texture/blue_flower.ppm", 1, &texture_list);
 // insertObject(o,&object_list);


 // Insert a single point light source. We set up its position as a point structure, and specify its
 // colour in terms of RGB (in [0,1]).
 // p.px=0;
 // p.py=25.5;
 // p.pz=-3.5;
 // p.pw=1;
 // l=newPLS(&p,.95,.95,.95);
 // insertPLS(l,&light_list);

   addAreaLight(1.5, 1.5, 0, -1, 0,
               -8, 35.5, -3.5, 8,
               0.95, 0.95, 0.95 ,
               &object_list, &light_list);

 // End of simple scene for Assignment 3
 // Keep in mind that you can define new types of objects such as cylinders and parametric surfaces,
 // or, you can create code to handle arbitrary triangles and then define objects as surface meshes.
 //
 // Remember: A lot of the quality of your scene will depend on how much care you have put into defining
 //           the relflectance properties of your objects, and the number and type of light sources
 //           in the scene.
 
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////
 // TO DO: For Assignment 4 you *MUST* define your own cool scene.
 //	   We will be looking for the quality of your scene setup, the use of hierarchical or composite
 //	   objects that are more interesting than the simple primitives from A3, the use of textures
 //        and other maps, illumination and illumination effects such as soft shadows, reflections and
 //        transparency, and the overall visual quality of your result. Put some work into thinking
 //        about these elements when designing your scene.
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////
  o=newSphere(.5,.95,.55,.25,.75,.95,.55,1,1,4);
  Scale(o,.8,0.8,0.8);
  // RotateZ(o,-PI/1.5);
  Translate(o,0,0.55,1.5);
  invert(&o->T[0][0],&o->Tinv[0][0]);
  loadTexture(o,"./texture/face_1.ppm", 1, &texture_list);
  insertObject(o,&object_list);

  o=newSphere(.5,.55,.55,.05,.75,.95,.55,1,1,2);
  // Scale(o,0.5,0.5,1);
  Translate(o,0,-1,1.5);
  invert(&o->T[0][0],&o->Tinv[0][0]);
  loadTexture(o,"./texture/body_1.ppm", 1, &texture_list);
  RotateX(o,-PI/0.5);
  insertObject(o,&object_list);

  /* eyes */
  // o=newSphere(.5,.55,.55,.05,0,0,0,1,1,2);
  // Scale(o,0.1,0.1,0.1);
  // // RotateZ(o,-PI/1.5);
  // Translate(o,-0.2,0.4,0.4);
  // invert(&o->T[0][0],&o->Tinv[0][0]);
  // insertObject(o,&object_list);


  // o=newSphere(.5,.55,.55,.05,0,0,0,1,1,2);
  // Scale(o,0.1,0.1,0.1);
  // // RotateZ(o,-PI/1.5);
  // Translate(o,0.3,0.4,0.4);
  // invert(&o->T[0][0],&o->Tinv[0][0]);
  // insertObject(o,&object_list);

  // transparent 
  // o=newSphere(.5,.95,.55,.25,.75,.95,.55,0.2,1,4);
  // Scale(o,1.2,1.2,1.2);
  // // RotateZ(o,-PI/1.5);
  // Translate(o,0,0,0.2);
  // invert(&o->T[0][0],&o->Tinv[0][0]);
  // insertObject(o,&object_list);


  o=newPlane(.05,.75,.05,.05,.55,.8,.75,1,1,2);
  Scale(o,20,5,11);
  // RotateZ(o,-PI/1.5);
  RotateX(o,PI/2);
  Translate(o,0,-2,0);
  invert(&o->T[0][0],&o->Tinv[0][0]);
  loadTexture(o,"./texture/blue_flower.ppm", 1, &texture_list);
  insertObject(o,&object_list);

  o=newPlane(.5,.75,.35,.05,0.5,0.5,0.5,1,1,2);
  Scale(o,40,20,20);
  // RotateZ(o,-PI/1.5);
  Translate(o,0,12,15);
  invert(&o->T[0][0],&o->Tinv[0][0]);
  loadTexture(o,"./texture/landscape.ppm", 1, &texture_list);
  insertObject(o,&object_list);
 }

void rtShade(struct object3D *obj, struct point3D *p, struct point3D *n, struct ray3D *ray, int depth, double a, double b, struct colourRGB *col)
{
 // This function implements the shading model as described in lecture. It takes
 // - A pointer to the first object intersected by the ray (to get the colour properties)
 // - The coordinates of the intersection point (in world coordinates)
 // - The normal at the point
 // - The ray (needed to determine the reflection direction to use for the global component, as well as for
 //   the Phong specular component)
 // - The current recursion depth
 // - The (a,b) texture coordinates (meaningless unless texture is enabled)
 //
 // Returns:
 // - The colour for this ray (using the col pointer)
 //

  struct colourRGB tmp_col;	// Accumulator for colour components
  double R,G,B;			// Colour for the object in R G and B

  // This will hold the colour as we process all the components of
  // the Phong illumination model
  tmp_col.R=0;
  tmp_col.G=0;
  tmp_col.B=0;

  if (obj->texImg==NULL)		// Not textured, use object colour
  {
    R=obj->col.R;
    G=obj->col.G;
    B=obj->col.B;
  }
  else
  {
    // Get object colour from the texture given the texture coordinates (a,b), and the texturing function
    // for the object. Note that we will use textures also for Photon Mapping.
    // fprintf(stderr, "texture coordinates in rtShade: %f, %f\n", a, b);
    obj->textureMap(obj->texImg,a,b,&R,&G,&B);
  }

 //////////////////////////////////////////////////////////////
 // TODO: Implement this function. Refer to the notes for
 // details about the shading model.
 //////////////////////////////////////////////////////////////

  pointLS *current_ls = light_list;
  struct ray3D *light_ray;
  struct point3D light_dir;

  // used for findFirstHit
  double temp_lambda;
  struct object3D *temp_obj;
  double coor_a, coor_b;
  struct point3D temp_p, temp_n;

  // used in Phong model and Global reflector
  struct ray3D *refl_ray;
  struct ray3D *refr_ray;
  double temp_dot_value, temp_max;
  point3D m;                 
  point3D c;               
  point3D ms;    
  struct colourRGB E_spec;
  /* Used in refraction */
  struct colourRGB E_refr;
  E_refr.R = 0;
  E_refr.G = 0;
  E_refr.B = 0;

  while (current_ls) {
    memcpy(&light_dir, &current_ls->p0, sizeof(struct point3D));
    // light_dir = p0 - p
    subVectors(p, &light_dir);
    // build a ray  r = p + lambda*(ls_p0 - p)
    light_ray = newRay(p, &light_dir);

    /* Local Component */
    // find first hit of ray at obj
    findFirstHit(light_ray, &temp_lambda, obj, &temp_obj, &temp_p, &temp_n, &coor_a, &coor_b);
    
    /* add ambient first: I = ra * Ia */
    tmp_col.R += obj->alb.ra * current_ls->col.R;
    tmp_col.G += obj->alb.ra * current_ls->col.G;
    tmp_col.B += obj->alb.ra * current_ls->col.B;

    // check if there is any objects in between (0 < temp_lambda < 1)
    if (temp_lambda < 0 ||  temp_lambda > 1) {
      // if not shadowed, add diffuse and specular

      /* diffuse: I += rd * Id * max(0, dot(n,s)) */

      // Compute dot(n,s)
      // where s is the normalized light direction and n is normal at intersection
      normalize(&light_dir);
      double dot_n_s = dot(n, &light_dir);

      // check special case for plane normals to make sure it points to the right direction (positive)
      if (obj->frontAndBack && dot_n_s < 0){
        dot_n_s = -dot_n_s;
      }
      temp_max = max(dot_n_s, 0); 
      tmp_col.R += obj->alb.rd * current_ls->col.R * temp_max;
      tmp_col.G += obj->alb.rd * current_ls->col.G * temp_max;
      tmp_col.B += obj->alb.rd * current_ls->col.B * temp_max;

      /* specular: I += rs * Is * max(0, dot(c, m)) */

      // Compute perfect mirror direction m = 2* dot(n, s) * n − s
      temp_dot_value = dot(&light_dir, n);
      m.px = 2 * temp_dot_value * n->px;
      m.py = 2 * temp_dot_value * n->py;
      m.pz = 2 * temp_dot_value * n->pz;
      m.pw = 1;
      subVectors(&light_dir, &m);
      normalize(&m);
      
      // Compute emmittant direction of intersect c = p - e
      // where p is the intersection point and e is camera location
      // which is the direction of the camera
      c.px = -ray->d.px;
      c.py = -ray->d.py;
      c.pz = -ray->d.pz;
      c.pw = 1;
      normalize(&c);
      
      temp_dot_value = dot(&c, &m);
      temp_max = pow(max(0,temp_dot_value),obj->shinyness);
      tmp_col.R += obj->alb.rs * current_ls->col.R * temp_max;
      tmp_col.G += obj->alb.rs * current_ls->col.G * temp_max;
      tmp_col.B += obj->alb.rs * current_ls->col.B * temp_max;
    }
    current_ls = current_ls->next;
  }

  /* Global Component */
  /* depending on ray = p + lambda *(p - e) only, nothing to do with LS(s) */

  if (depth < MAX_DEPTH){
    // compute mirror direction: ms = - 2 * dot(d, n) * n + d
    double temp_dot_value = dot(&ray->d, n);
    ms.px = - 2 * temp_dot_value * n->px;
    ms.py = - 2 * temp_dot_value * n->py;
    ms.pz = - 2 * temp_dot_value * n->pz;
    ms.pw = 1;
    // construct new mirror direction
    // memcpy(&m, &ray->d, sizeof(struct point3D));
    addVectors(&ray->d, &ms);
    normalize(&ms);

    // If OBJ has specular reflection
    if (obj->alb.rs != 0){
      // create the ray from intersection point p along mirror direction 
      refl_ray = newRay(p, &ms);
      rayTrace(refl_ray, depth++, &E_spec, obj);
      // add reflected color E_spec in, scaled by rg
      tmp_col.R += obj->alb.rg * E_spec.R;
      tmp_col.G += obj->alb.rg * E_spec.G;
      tmp_col.B += obj->alb.rg * E_spec.B;
    }
    free(refl_ray);

    if (obj->alpha < 1){
      double x,y,z;
      double index;
      double m, m2;
      point3D refract_dir;
      
      // Determine ray enter or exit object
      if ( dot(n, &ray->d) > 0){
        index =  obj->r_index;
        temp_dot_value = dot(n, &ray->d);
      } else{
        index = 1/obj->r_index;
        // Set normal to opposite direction
        point3D opp_n;
        opp_n.px = -n->px;
        opp_n.py = -n->py;
        opp_n.pz = -n->pz;
        opp_n.pw = 1;
        temp_dot_value = dot(&opp_n, &ray->d);
      }
      m = 1 - pow(index, 2) * (1 - pow(temp_dot_value, 2));
      // Do refraction only when m >= 0
      if (m >= 0) {
        m2 = index * temp_dot_value - pow(m,0.5);
        // Calculate the direction
        if (dot(n, &ray->d) > 0){
          // Ray from outside of object to inside of object
          x = index * ray->d.px + m2 * n->px;
          y = index * ray->d.py + m2 * n->py;
          z = index * ray->d.pz + m2 * n->pz;
        }
        else{
          // Ray from inside of object to outside of object
          x = index * ray->d.px + m2 * n->px;// * -1;
          y = index * ray->d.py + m2 * n->py;// * -1;
          z = index * ray->d.pz + m2 * n->pz;// * -1;
        }
        // Refraction Direction
        refract_dir.px = x;
        refract_dir.py = y;
        refract_dir.pz = z;
        refract_dir.pw = 1;

        //cast new ray
        ray3D *refract_ray = newRay(p, &refract_dir);
        rayTrace(refract_ray, depth + 1, &E_refr, obj);
        
        // Update color for refraction
        E_refr.R = E_refr.R * (1 - obj->alpha);
        E_refr.G = E_refr.G * (1 - obj->alpha);
        E_refr.B = E_refr.B * (1 - obj->alpha);

        // Free refraction ray
        free(refract_ray);
      }
    }
  }

  tmp_col.R = tmp_col.R * obj->alpha + E_refr.R;
  tmp_col.G = tmp_col.G * obj->alpha + E_refr.G;
  tmp_col.B = tmp_col.B * obj->alpha + E_refr.B;

 // Be sure to update 'col' with the final colour computed here!
  col->R = min(tmp_col.R * R, 1);
  col->G = min(tmp_col.G * G, 1);
  col->B = min(tmp_col.B * B, 1);

  free(light_ray);
  free(current_ls);
 return;
}

void findFirstHit(struct ray3D *ray, double *lambda, struct object3D *Os, struct object3D **obj, struct point3D *p, struct point3D *n, double *a, double *b)
{
 // Find the closest intersection between the ray and any objects in the scene.
 // Inputs:
 //   *ray    -  A pointer to the ray being traced
 //   *Os     -  'Object source' is a pointer toward the object from which the ray originates. It is used for reflected or refracted rays
 //              so that you can check for and ignore self-intersections as needed. It is NULL for rays originating at the center of
 //              projection
 // Outputs:
 //   *lambda -  A pointer toward a double variable 'lambda' used to return the lambda at the intersection point
 //   **obj   -  A pointer toward an (object3D *) variable so you can return a pointer to the object that has the closest intersection with
 //              this ray (this is required so you can do the shading)
 //   *p      -  A pointer to a 3D point structure so you can store the coordinates of the intersection point
 //   *n      -  A pointer to a 3D point structure so you can return the normal at the intersection point
 //   *a, *b  -  Pointers toward double variables so you can return the texture coordinates a,b at the intersection point

 /////////////////////////////////////////////////////////////
 // TODO: Implement this function. See the notes for
 // reference of what to do in here
 /////////////////////////////////////////////////////////////

  double temp_lambda= 0;
  struct point3D temp_p, temp_n;
  double coor_a, coor_b = 0;
  object3D *current_obj = object_list;

  *lambda = -1;
  while (current_obj) {
    if (current_obj != Os) {
      current_obj->intersect(current_obj, ray, &temp_lambda, &temp_p, &temp_n, &coor_a, &coor_b);
      if ((*lambda < 0 || temp_lambda < *lambda) && (temp_lambda > 0)) {
        *lambda = temp_lambda;
        *p = temp_p;
        *n = temp_n;
        *obj = current_obj;

        // fprintf(stderr, "texture coordinates in findFirstHit: %f, %f\n", coor_a, coor_b);
        // update for texture
        *a = coor_a;
        *b = coor_b;
      }
    }
    current_obj = current_obj->next;
  }
  free(current_obj);

}

void rayTrace(struct ray3D *ray, int depth, struct colourRGB *col, struct object3D *Os)
{
 // Trace one ray through the scene.
 //
 // Parameters:
 //   *ray   -  A pointer to the ray being traced
 //   depth  -  Current recursion depth for recursive raytracing
 //   *col   - Pointer to an RGB colour structure so you can return the object colour
 //            at the intersection point of this ray with the closest scene object.
 //   *Os    - 'Object source' is a pointer to the object from which the ray 
 //            originates so you can discard self-intersections due to numerical
 //            errors. NULL for rays originating from the center of projection. 
 
  double lambda;		// Lambda at intersection
  double a,b;		// Texture coordinates
  struct object3D *obj;	// Pointer to object at intersection
  struct point3D p;	// Intersection point
  struct point3D n;	// Normal at intersection
  struct colourRGB I;	// Colour returned by shading function

  if (depth>MAX_DEPTH)	// Max recursion depth reached. Return invalid colour.
  {
    col->R=-1;
    col->G=-1;
    col->B=-1;
    return;
  }

 ///////////////////////////////////////////////////////
 // TODO: Complete this function. Refer to the notes
 // if you are unsure what to do here.
 ///////////////////////////////////////////////////////
  findFirstHit(ray, &lambda, Os, &obj, &p, &n, &a, &b);
  if (lambda > 0) {
    // fprintf(stderr, "texture coordinates in rayTrace: %f, %f\n", a, b);
    rtShade(obj, &p, &n, ray, depth, a, b, &I);
    col->R = I.R;
    col->G = I.G;
    col->B = I.B;
  } else {
    col->R = 0;
    col->G = 0;
    col->B = 0;
  }
  // free(obj);
}

int main(int argc, char *argv[])
{
  // Main function for the raytracer. Parses input parameters,
  // sets up the initial blank image, and calls the functions
  // that set up the scene and do the raytracing.
  struct image *im;	// Will hold the raytraced image
  struct view *cam;	// Camera and view for this scene
  int sx;		// Size of the raytraced image
  int antialiasing;	// Flag to determine whether antialiaing is enabled or disabled
  char output_name[1024];	// Name of the output file for the raytraced .ppm image
  struct point3D e;		// Camera view parameters 'e', 'g', and 'up'
  struct point3D g;
  struct point3D up;
  double du, dv;			// Increase along u and v directions for pixel coordinates
  struct point3D pc,d;		// Point structures to keep the coordinates of a pixel and
  			// the direction or a ray
  struct ray3D *ray;		// Structure to keep the ray from e to a pixel
  struct colourRGB col;		// Return colour for raytraced pixels
  struct colourRGB background;   // Background colour
  int i,j;			// Counters for pixel coordinates
  unsigned char *rgbIm;
  int offset; // for putting color to the array

  // for anti-aliasing
  int aa_samples; // number of samples K
  int k;
  struct colourRGB aa_color_sum; // sum of colors at all sample locations

  if (argc<5)
  {
    fprintf(stderr,"RayTracer: Can not parse input parameters\n");
    fprintf(stderr,"USAGE: RayTracer size rec_depth antialias output_name\n");
    fprintf(stderr,"   size = Image size (both along x and y)\n");
    fprintf(stderr,"   rec_depth = Recursion depth\n");
    fprintf(stderr,"   antialias = A single digit, 0 disables antialiasing. Anything else enables antialiasing\n");
    fprintf(stderr,"   output_name = Name of the output file, e.g. MyRender.ppm\n");
    exit(0);
  }
  sx=atoi(argv[1]);
  MAX_DEPTH=atoi(argv[2]);
  if (atoi(argv[3])==0) antialiasing=0; else antialiasing=1;
  strcpy(&output_name[0],argv[4]);

  fprintf(stderr,"Rendering image at %d x %d\n",sx,sx);
  fprintf(stderr,"Recursion depth = %d\n",MAX_DEPTH);
  if (!antialiasing) fprintf(stderr,"Antialising is off\n");
  else fprintf(stderr,"Antialising is on\n");
  fprintf(stderr,"Output file name: %s\n",output_name);

  object_list=NULL;
  light_list=NULL;
  texture_list=NULL;

  // Allocate memory for the new image
  im=newImage(sx, sx);
  if (!im)
  {
    fprintf(stderr,"Unable to allocate memory for raytraced image\n");
    exit(0);
  }
  else rgbIm=(unsigned char *)im->rgbdata;

  ///////////////////////////////////////////////////
  // TO DO: You will need to implement several of the
  //        functions below. For Assignment 3, you can use
  //        the simple scene already provided. But
  //        for Assignment 4 you need to create your own
  //        *interesting* scene.
  ///////////////////////////////////////////////////
  buildScene();		// Create a scene. This defines all the
  		// objects in the world of the raytracer

  //////////////////////////////////////////
  // TO DO: For Assignment 3 you can use the setup
  //        already provided here. For Assignment 4
  //        you may want to move the camera
  //        and change the view parameters
  //        to suit your scene.
  //////////////////////////////////////////

  // Mind the homogeneous coordinate w of all vectors below. DO NOT
  // forget to set it to 1, or you'll get junk out of the
  // geometric transformations later on.

  // Camera center is at (0,0,-1)
  e.px=0;
  e.py=0;
  e.pz=-1;
  e.pw=1;

  // To define the gaze vector, we choose a point 'pc' in the scene that
  // the camera is looking at, and do the vector subtraction pc-e.
  // Here we set up the camera to be looking at the origin.
  g.px=0-e.px;
  g.py=0-e.py;
  g.pz=0-e.pz;
  g.pw=1;
  // In this case, the camera is looking along the world Z axis, so
  // vector w should end up being [0, 0, -1]

  // Define the 'up' vector to be the Y axis
  up.px=0;
  up.py=1;
  up.pz=0;
  up.pw=1;

  // Set up view with given the above vectors, a 4x4 window,
  // and a focal length of -1 (why? where is the image plane?)
  // Note that the top-left corner of the window is at (-2, 2)
  // in camera coordinates.
  cam=setupView(&e, &g, &up, -1, -2, 2, 4);

  if (cam==NULL)
  {
    fprintf(stderr,"Unable to set up the view and camera parameters. Our of memory!\n");
    cleanup(object_list,light_list, texture_list);
    deleteImage(im);
    exit(0);
  }

  // Set up background colour here
  background.R=0;
  background.G=0;
  background.B=0;

  // Do the raytracing
  //////////////////////////////////////////////////////
  // TODO: You will need code here to do the raytracing
  //        for each pixel in the image. Refer to the
  //        lecture notes, in particular, to the
  //        raytracing pseudocode, for details on what
  //        to do here. Make sure you undersand the
  //        overall procedure of raytracing for a single
  //        pixel.
  //////////////////////////////////////////////////////
  du=cam->wsize/(sx-1);		// du and dv. In the notes in terms of wl and wr, wt and wb,
  dv=-cam->wsize/(sx-1);		// here we use wl, wt, and wsize. du=dv since the image is
  			// and dv is negative since y increases downward in pixel
  			// coordinates and upward in camera coordinates.

  fprintf(stderr,"View parameters:\n");
  fprintf(stderr,"Left=%f, Top=%f, Width=%f, f=%f\n",cam->wl,cam->wt,cam->wsize,cam->f);
  fprintf(stderr,"Camera to world conversion matrix (make sure it makes sense!):\n");
  printmatrix(cam->C2W);
  fprintf(stderr,"World to camera conversion matrix:\n");
  printmatrix(cam->W2C);
  fprintf(stderr,"\n");

  if (!antialiasing) aa_samples =1;
  else aa_samples = 5;
  // fprintf(stderr,"num of samples: %d\n",aa_samples);

  fprintf(stderr,"Rendering row: ");
  #pragma omp parallel for schedule(dynamic,32) shared(aa_samples, rgbIm, object_list, light_list, texture_list) private(j)
  for (j=0;j<sx;j++)		// For each of the pixels in the image
  {
    fprintf(stderr,"%d/%d, ",j,sx);
    #pragma omp parallel for private(k, pc, d, ray, col, aa_color_sum, offset, i)
    // #pragma omp parallel for shared(aa_color_sum, offset, i) private (k)
    for (i=0;i<sx;i++)
    {

      ///////////////////////////////////////////////////////////////////
      // TODO - complete the code that should be in this loop to do the
      //         raytracing!
      ///////////////////////////////////////////////////////////////////

      // initialize color holder for calculating antialiased color
      aa_color_sum.R = 0;
      aa_color_sum.G = 0;
      aa_color_sum.B = 0;
      // if anti-aliasing turned off aa_samples is 1, so the same result as no anti-alising
      // #pragma omp parallel for private (k, pc, d, ray, col)
      for (k = 0; k < aa_samples; k++) {
        col.R = background.R;
        col.G = background.G;
        col.B = background.B;

        pc.px = cam->wl + (i+drand48()-0.5) * du;
        pc.py = cam->wt + (j+drand48()-0.5) * dv;
        pc.pz = cam->f;
        pc.pw = 1;
        matVecMult(cam->C2W, &pc);

        // set direction d_i,j = p_i,j - e,
        d.px= pc.px - cam->e.px;
        d.py= pc.py - cam->e.py;
        d.pz= pc.pz - cam->e.pz;
        d.pw= pc.pw - cam->e.pw;
        normalize(&d);

        // create a ray from camera to that point and trace
        ray = newRay(&pc, &d); 
        rayTrace(ray, 0, &col, NULL); 
        
        aa_color_sum.R += col.R;
        aa_color_sum.G += col.G;
        aa_color_sum.B += col.B;
      
        /* Free memory */
        free(ray);
      }
      // fprintf(stderr,"num of samples: %d\n",aa_samples);
      // fprintf(stderr,"retrieved color: %G v.s. added: %G\n", col.G, aa_color_sum.G / aa_samples);

      // set color of this pixel stored in the array with correct offset
      offset = (i + (j * sx)) * 3;
      *(rgbIm + (offset + 0)) = (aa_color_sum.R / aa_samples) * 255;
      *(rgbIm + (offset + 1)) = (aa_color_sum.G / aa_samples) * 255;
      *(rgbIm + (offset + 2)) = (aa_color_sum.B / aa_samples) * 255;


    } // end for i
  } // end for j

  fprintf(stderr,"\nDone!\n");

  // Output rendered image
  imageOutput(im,output_name);

  // Exit section. Clean up and return.
  cleanup(object_list,light_list,texture_list);		// Object, light, and texture lists
  deleteImage(im);					// Rendered image
  free(cam);						// camera view
  exit(0);
}

