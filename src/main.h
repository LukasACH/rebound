/**
 * @file 	main.h
 * @brief 	Main header file with widely used global variables.
 * @author 	Hanno Rein <hanno@hanno-rein.de>
 * 
 * @section 	LICENSE
 * Copyright (c) 2011 Hanno Rein, Shangfei Liu
 *
 * This file is part of rebound.
 *
 * rebound is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * rebound is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with rebound.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef _MAIN_H
#define _MAIN_H
#include "particle.h" // Needed for struct particle.
#ifndef M_PI
// Make sure M_PI is defined. 
#define M_PI           3.14159265358979323846
#endif
struct ReboundIntegratorWHFast;

struct Rebound {
	double 	t;		/**< Current simulation time. */
	double 	tmax;		/**< Maximum simulation time. Simulation stops if t>=tmax. Simulation runs forever if t==0.*/
	double 	G;		/**< Gravitational constant. Default: 1. */
	double 	softening;	/**< Gravitational softening parameter. Default: 0. */
	double 	dt;		/**< Current timestep. */
	double 	boxsize;	/**< Size of a root box. Needs to be set in problem_init(). */
	double 	boxsize_x;	/**< Size of the entire box in the x direction, root_nx*boxsize. Set in box_init().*/
	double 	boxsize_y;	/**< Size of the entire box in the y direction, root_ny*boxsize. Set in box_init().*/
	double 	boxsize_z;	/**< Size of the entire box in the z direction, root_nz*boxsize. Set in box_init().*/
	double 	boxsize_max;	/**< Maximum size of the entire box in any direction. Set in box_init().*/
	int 	N;		/**< Current number of particles on this node. */
	int 	Nmax;		/**< Current maximum space allocated in the particles array on this node. */
	int 	N_active;	/**< Number of massive particles included in force calculation. Default: N.*/
	int 	N_megno;	/**< Number of megno particles. Default: 0.*/
	int 	root_nx;	/**< Number of root boxes in x direction. Default: 1. */
	int 	root_ny;	/**< Number of root boxes in y direction. Default: 1. */
	int 	root_nz;	/**< Number of root boxes in z direction. Default: 1. */
	int 	root_n;		/**< Total number of root boxes in all directions, root_nx*root_ny*root_nz. Default: 1. Set in box_init().*/
	int 	exit_simulation;/**< Set to 1 to exit the simulation at the end of the next timestep. */
	double 	timing_initial;	/**< System time at start. Used to meassure total cpu time. */


	/**
	 * Main particle array.
	 * This contains all particles on this node.
	 */
	struct Particle* particles;
	
	/// Integrators
	struct ReboundIntegratorWHFast* ri_whfast;	/**< Pointer to the WHFast struct */
};


/**
 * Initializes all REBOUND variables and returns a REBOUND handle.. 
 * This function must be called from problem_init() before any particles are added.
 */
struct Rebound* rebound_init();

/**
 * Main iteration loop.
 * All the work is done within this function.
 * When OpenGL is not used, this function is called by a loop in main(). 
 * When OpenGL is used, this function is called by OpenGL directly. 
 */
void iterate(struct Rebound* const r);


/** Function pointer definitions 
 *
 */
extern void (*problem_post_timestep_modifications) (void);
extern void (*problem_post_timestep_modifications_with_parameters) (struct Particle* particles, double t, double dt, double G, int N, int N_megno);  
#endif
