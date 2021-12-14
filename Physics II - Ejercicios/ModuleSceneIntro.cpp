#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"



ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	graphics = NULL;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	fondo = App->textures->Load("C:/Users/adrianmm2/Documents/GitHub/PhysicsII_Engine/Physics II - Ejercicios/Game/Ejercicio/Assets/Fondo1.png");
	canyon = App->textures->Load("C:/Users/adrianmm2/Documents/GitHub/PhysicsII_Engine/Physics II - Ejercicios/Game/Ejercicio/Assets/Soldado1.png");
	bola = App->textures->Load("C:/Users/adrianmm2/Documents/GitHub/PhysicsII_Engine/Physics II - Ejercicios/Game/Ejercicio/Assets/Bola.png");

	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;

	return ret;
}


// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	App->renderer->Blit(fondo, 60, 0, NULL);
	App->renderer->Blit(canyon, 150, 650, NULL);
	App->renderer->Blit(bola, 300, 600, NULL);

	return UPDATE_CONTINUE;
}
