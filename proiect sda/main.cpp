#include "UserInterface/UserInterface.h"
#include "Tests/Tests.h"

int main() {
	tests();
	UserInterface ui;
	ui.start();
}