#pragma once

const int evNothing = 0; //empty msg
const int evMessage = 100; //not empty message;
const int cmAdd = 1;  //add obj in group
const int cmDel = 2; //delete obj from group;
const int cmGet = 3; //print an attribute of all objects
const int cmShow = 4; //print all group
const int cmMake = 6; //make group
const int cmQuit = 101; //exit
//class-event
struct TEvent {
	int what; //type of event
	union {
		int command; //command code
		struct {
			int message;
			int a; // command parameter
		};
	};
};
