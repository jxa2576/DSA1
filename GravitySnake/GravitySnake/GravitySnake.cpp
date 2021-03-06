// GravitySnake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "snake.h"
#include <conio.h>
#include <iostream>
#include "Box2D\Box2D.h"

using namespace std;

int main()
{
	cout << "Gravity Snake" << endl;

	//Sets the gravity
	b2Vec2 gravity(0.0f, -1.0f);
	b2World world(gravity);

	//The gravity snake
	b2BodyDef snakeDef;
	snakeDef.type = b2_dynamicBody;
	snakeDef.position.Set(0.0f, 0.0f);
	b2Body* snake = world.CreateBody(&snakeDef);

	//The target
	b2BodyDef targetDef;
	targetDef.type = b2_staticBody;
	targetDef.position.Set(2.0f, 2.0f);
	b2Body* target = world.CreateBody(&targetDef);

	//Variables to start the game loop
	//The key pressed by the user
	int key = 0;
	//A boolean that is true when the target and snake collide
	bool hit = false;
	//How many targets that can be hit before the level ends
	int levelCount = 10;
	//How many targets have been hit
	int hitTargets = 0;

	//Game Loop
	while (key != 27) {
		key = _getch();
		if (key == 27 || hitTargets == levelCount) {
			//Esc the level with esc
			cout << "Game Over" << endl;
			break;
		}
		else {
			applyForces(snake, key);
			display(snake, target);
		}
		update(world);
		hit = checkCollision(snake, target);
		//Activates on collision
		if (hit) {
			cout << "HIT" << endl;
			
			hitTargets++;

			b2Vec2 pos;
			moveTarget(pos.x, pos.y);
			target->SetTransform(pos, target->GetAngle());
		}
		//resets the key and hit
		hit = false;
		key = 0;
	}

    return 0;
}

