
#include "Particle.hpp"

Particle::Particle() {
	mass = 1.0;
}

void Particle::applyForce(ofVec2f force) {
	accel += (force / mass);
}

void Particle::update() {
	vel += accel;
	pos += vel;

	vel *= 0.97;

	accel.set(0);
}

void Particle::draw() {
	ofCircle(pos, 3);
}
