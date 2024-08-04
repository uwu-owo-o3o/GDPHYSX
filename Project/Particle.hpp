#pragma once

#include "Vector3.hpp"
class Particle {
	
	public:
		float mass = 5;
		

		float lifeSpan = 0;
		float lifeTicks = 0;

		Vector3 position;
		Vector3 velocity;
		Vector3 acceleration;

		Vector3 initialVelocity;

		float radius = 50.f;
		float restitution = 1.f;

	public:
		glm::mat4 Rotation = glm::mat4(1.0f);
		Vector3 AngularVelocity = Vector3(0.0f, 0.0f, 0.0f);
		float AngularDamping = 0.9f;
		void AddForceAtPoint(Vector3 force, Vector3 particle);

	public:
		Vector3 accumulatedTorque = Vector3(0, 0, 0);
		virtual float MomentOfInertia();
	
public:
		Vector3 accumulatedForce = Vector3::zero;
		

		// 0 -> 1
		// 0 nothing left
		// 1 constant v

		float damping = 0.9f;
		bool isDestroyed = false;

	
	protected:
		void UpdatePosition(float deltaTime);
		void UpdateVelocity(float deltaTime);



	public:
		void Update(float deltaTime);
		void Instantiate();
		void Destroy();
		bool IsDestroyed();

	public:
		void AddForce(Vector3 force);
		void ResetForce();

	public: 
		void setPosition(Vector3 position);
		void setVelocity(Vector3 velocity);
		void setAcceleration(Vector3 acceleration);


};