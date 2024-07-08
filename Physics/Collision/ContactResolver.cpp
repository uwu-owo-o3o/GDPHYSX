#include "ContactResolver.hpp"

using namespace collision;

void ContactResolver::ResolveContacts(std::vector<ParticleContact*> contacts, float time) {
	
	current_iterations = 0;
	while (current_iterations < max_iterations) {
		unsigned current_index = 0;
		float curr_min = contacts[0]->GetSeparatingSpeed();
		
		for (int i = 1; i < contacts.size(); i++) {
			float ss = contacts[i]->GetSeparatingSpeed();
			if (ss < curr_min) {
				current_index = i;
				curr_min = ss;
			}
		}

		if (curr_min >= 0) {
			return;
		}

		contacts[current_index]->Resolve(time);
		current_iterations++;
	}
}