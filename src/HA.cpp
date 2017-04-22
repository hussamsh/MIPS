#include "HA.h"

void HA::Add(){
	s = A ^ B;
	c = A & B;
	return;
}
