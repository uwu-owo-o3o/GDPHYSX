#include "ContactResolver.hpp"

using namespace collision;

void ContactResolver::ResolveContacts(std::vector<ParticleContact*> contacts, float time) {
	
	current_iterations = 0;
	while (current_iterations < max_iterations) {
		unsigned current_index = 0;
		float curr_min = contacts[0]->GetSeparatingSpeed();
		float curr_depth = contacts[0]->depth;

		for (int i = 1; i < contacts.size(); i++) {
			float ss = contacts[i]->GetSeparatingSpeed();
			float d = contacts[i]->depth;

			if (ss < curr_min || d > 0) {
				current_index = i;
				curr_min = ss;
				curr_depth = d;
			}
		}

		if (curr_min >= 0 && curr_depth <= 0) {
			return;
		}

		contacts[current_index]->Resolve(time);
		current_iterations++;
	}
}