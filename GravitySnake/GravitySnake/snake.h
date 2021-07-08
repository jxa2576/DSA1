#pragma once

#include "snake.h"
#include "stdafx.h"
#include "conio.h"
#include <ctime>
#include <iostream>
#include "Box2D\Box2D.h"

void update(b2World& world);

void display(b2Body* snake, b2Body* target);

void applyForces(b2Body* snake, int key);

void moveTarget(float& xPos, float& yPos);

bool checkCollision(b2Body* snake, b2Body* target);
