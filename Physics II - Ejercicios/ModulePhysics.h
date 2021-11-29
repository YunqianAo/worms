#pragma once
#include "Module.h"
#include "Globals.h"

class Ball
{
public:
	// Position
	// You could also use an array/vector
	double x;
	double y;

	// Velocity
	double vx;
	double vy;

	// Acceleration
	double ax;
	double ay;

	// Force (total) applied to the ball
	double fx;
	double fy;

	// Mass
	double mass;

	// Aerodynamics stuff
	double surface; // Effective wet surface
	double cl; // Lift coefficient
	double cd; // Drag coefficient

	// Has physics enabled?
	bool physics_enabled = true;
};

class ModulePhysics : public Module
{
public:
	ModulePhysics(Application* app, bool start_enabled = true);
	~ModulePhysics();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

	float massa = 0;
	float gravetat = 9.81;
	float forsa = 0;
	int bolay;


private:

	bool debug;
};