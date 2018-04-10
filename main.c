//BEGIN DESCRIPTION
/* records the duration how long mb1 is pressed
 * 
 */
//END   DESCRIPTION

//BEGIN INCLUDES
//local headers
#include "helper.h"
//END   INCLUDES

//BEGIN CPP DEFINITIONS
//END   CPP DEFINITIONS

//BEGIN DATASTRUCTURES
//END	DATASTRUCTURES

//BEGIN GLOBALS
//END   GLOBALS

//BEGIN FUNCTION PROTOTYPES
//END	FUNCTION PROTOTYPES

/* DEFINED PROGRESS GOALS
 * 
 */

//BEGIN MAIN FUNCTION
int main(int argc, char *argv[])
{

(void)argc;
(void)argv;

//BEGIN INIT
init();

SDL_SetWindowPosition(Window,0,0);
SDL_SetWindowSize(Window,540,540);
SDL_SetWindowTitle(Window, "SDL 2 - Timer");
SDL_ShowWindow(Window);

SDL_SetRenderDrawColor(Renderer, 111, 111, 111, 255);
SDL_RenderClear(Renderer);
SDL_RenderPresent(Renderer);

//BEGIN TIMING
Uint32 frame_time  = 0;
Uint32 stop_time   = 0;
Uint32 frame_start = 0;

int is_timing=0;
//END TIMING

SDL_Event event;
int running = 1;
//END   INIT

//BEGIN MAIN Loop
while(running){
	frame_start=SDL_GetTicks();
	//BEGIN EVENT LOOP
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			running = 0;
		}
		if(event.type == SDL_MOUSEBUTTONDOWN){
			if(event.button.button == SDL_BUTTON_RIGHT){
				running=0;
			}
			if(event.button.button == SDL_BUTTON_LEFT){
				is_timing=1;
			}
		}
		if(event.type == SDL_MOUSEBUTTONUP){
			if(event.button.button == SDL_BUTTON_LEFT){
				if (stop_time<1000)
					SDL_Log("ms: %d",stop_time);
				else
					SDL_Log("secs: %.2f",(float)stop_time/1000);
				stop_time=0;
				is_timing=0;
			}
		}
	}
	//END   EVENT LOOP

	//BEGIN RENDERING
	//Not refreshing Screen
	//END   RENDERING
	frame_time = SDL_GetTicks()-frame_start;
	if (is_timing)
		stop_time+=frame_time;
}
//END   MAIN LOOP
exit_();
return EXIT_SUCCESS;

}
//END   MAIN FUNCTION

//BEGIN FUNCTIONS
//END   FUNCTIONS
