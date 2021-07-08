#pragma once

#include "snake.h"
#include "stdafx.h"
#include "conio.h"
#include <ctime>
#include <iostream>
#include "Box2D\Box2D.h"

using namespace std;

void update(b2World& world) {
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	world.Step(timeStep, velocityIterations, positionIterations);
}

void display(b2Body* snake, b2Body* target) {
	cout << "Target: " << target->GetPosition().x << ", " << target->GetPosition().y << "-->" << "Snake Pos: " << snake->GetPosition().x << ", " << snake->GetPosition().y << endl;
}

void applyForces(b2Body* snake, int key) {
	switch (key) {
		case 'w':
			snake->ApplyForceToCenter(b2Vec2(0, 2.0f), false);
			break;
		case 'a':
			snake->ApplyForceToCenter(b2Vec2(-2.0f, 0.0f), false);
			break;
		case 's':
			snake->ApplyForceToCenter(b2Vec2(0, -2.0f), false);
			break;
		case 'd':
			snake->ApplyForceToCenter(b2Vec2(2.0f, 0), false);
			break;
	}
}

void moveTarget(float& xPos, float& yPos) {
	srand(time(NULL));

	float xRand = -5 + rand() % 11;
	float yRand = -5 + rand() % 11;

	xPos = xRand;
	yPos = yRand;
}

//Does AABB collision for the snake and target
bool checkCollision(b2Body* snake, b2Body* target) {

	float width = 0.1f;

	if (snake->GetPosition().x < target->GetPosition().x + width && snake->GetPosition().x + width > target->GetPosition().x && snake->GetPosition().y < target->GetPosition().y + width && snake->GetPosition().y + width > target->GetPosition().y) {
		return true;
	}
	else {
		return false;
	}
}