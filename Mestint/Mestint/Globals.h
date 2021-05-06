#pragma once

class Global
{
public:
	static unsigned int Width;
	static unsigned int Height;

public:
	Global() {}
	~Global() {}
};

unsigned int Global::Width = 1024;
unsigned int Global::Height = 768;