#include "Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1Scene.h"
#include "Camera.h"

j1Scene::j1Scene() : j1Module()
{
	name.assign("scene");
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	App->map->Load("iso_walk.tmx");	

	debug_tex = App->tex->Load("maps/path2.png");

	player_A = (Obj_Player*)App->obj_manager->CreateObject(ObjectType::PLAYER, { 0,0 });
	player_B = (Obj_Player*)App->obj_manager->CreateObject(ObjectType::PLAYER, { 5,5 });
	player_C = (Obj_Player*)App->obj_manager->CreateObject(ObjectType::PLAYER, { 10,10 });
	player_D = (Obj_Player*)App->obj_manager->CreateObject(ObjectType::PLAYER, { 15,15 });

	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	/*if(App->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
		App->LoadGame("save_game.xml");

	if(App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
		App->SaveGame("save_game.xml");*/

	if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		App->render->cameras[0]->rect.y -= floor(200.0f * dt);

	if(App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		App->render->cameras[0]->rect.y += floor(200.0f * dt);

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		App->render->cameras[0]->rect.x -= floor(200.0f * dt);

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		App->render->cameras[0]->rect.x += floor(200.0f * dt);

	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate(float dt)
{
	bool ret = true;

	if(App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}