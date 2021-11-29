#include "Globals.h"
#include "Application.h"
#include "ModulePhysics.h"
#include "math.h"


ModulePhysics::ModulePhysics(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	debug = true;
}

// Destructor
ModulePhysics::~ModulePhysics()
{
}

bool ModulePhysics::Start()
{
	LOG("Creating Physics 2D environment");
	// Create a ball
	// You should create this object in the header of the class, so that everyone within the class can access it.
	Ball ball;

	// Set physics properties of the ball
	ball.mass = 10; // kg
	ball.surface = 2; // m^2
	ball.cd = 0.4;
	ball.cl = 1.2;

	// Set initial position and velocity of the ball
	ball.x = ball.y = 0.0;
	ball.vx = 10.0;
	ball.vy = 5.0;
	return true;
}

// 
update_status ModulePhysics::PreUpdate()
{
/*  Pas 1: Calculem forces(Gravetat)
	Pas 2: Apliquem la 2a Llei de Newton: F=m*a
	Pas 3: Introduim l'integrador
	        ->Euler:
			       -> BWD -> x+= v * dt
				   -> FWD -> v+= a * dt
            ->Verlet:
			        ->Veloc -> x+= v * dt + 1/2 * a * dt^2
                            -> v+= a * dt
	Pas 4: Collisions



	Formas de hacer el campo gravitatorio:

	1-> F=-G*(m1*m2)/r^2
	2-> F=F=ct
	3->
	*/

	return UPDATE_CONTINUE;
}

update_status ModulePhysics::Update()
{

	return UPDATE_CONTINUE;
}
update_status ModulePhysics::PostUpdate()
{
	

	if(App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
		debug = !debug;

	if(!debug)
		return UPDATE_CONTINUE;
	return UPDATE_CONTINUE;
}


// Called before quitting
bool ModulePhysics::CleanUp()
{
	LOG("Destroying physics world");

	// Delete the whole physics world!

	return true;
}
