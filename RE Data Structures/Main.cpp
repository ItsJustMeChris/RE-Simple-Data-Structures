#include <iostream>

struct Vector3 {
	float x;
	float y;
	float z;
};

struct Character {
	Character* Next = NULL;
	Vector3 Position = { 0,0,0 };
};

struct CharacterList {
	Character* head = NULL;
	void push(Vector3 pos) {
		Character* tmp = new Character;
		tmp->Position = pos;
		tmp->Next = NULL;

		tmp->Next = head;
		head = tmp;
	}
};

void printCharacterList(CharacterList cl) {
	Character* first = cl.head;
	do {
		printf("X: %f, Y: %f, Z: %f\n\n", first->Position.x, first->Position.y, first->Position.z);
		first = first->Next;

	} while (first);
}

int main() {
	CharacterList CL;
	for (int i = 0; i <= 15; i++) {
		Vector3 Pos{ i*13.53532+1, i*35.236643+2, i*6.46346346+3 };
		CL.push(Pos);
	}

	printCharacterList(CL);

	getchar();
	return 0;
}